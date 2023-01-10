#ifndef __SCOPE_IMPL_HPP__
#define __SCOPE_IMPL_HPP__

Scope * Scope :: pGlobalScope = new Scope ( 
            nullptr,
            new TypeTable (
                new TypeTable :: TypeList {
                    new TypeEntry ( "nonExistentType", 0 ),
                    new TypeEntry ( "char", 1 ),
                    new TypeEntry ( "bool", 1 ),
                    new TypeEntry ( "float", 4 ),
                    new TypeEntry ( "int", 4 ),
                    new TypeEntry ( "string", 8 ),
                    new TypeEntry ( "function", 1 )
                }
            )
    );

Scope :: Scope ( 
    Scope     * pUpperScope,
    TypeTable * pTypes      
) :
    _pUpperScope  ( pUpperScope ) {

    if ( pTypes != nullptr ) {
        for ( auto e : * pTypes->getTypes() ) {
            this->_pTypes->addType ( e ); 
        }
    }
}


Scope :: ~Scope () {

    delete this->_pTypes;
    delete this->_pSymbols;
}


auto constexpr Scope :: getUpperScope () -> Scope * {
    
    return this->_pUpperScope;
}


auto constexpr Scope :: getSymbolTable () -> SymbolTable * {
        
    return this->_pSymbols;
}


auto constexpr Scope :: getTypeTable () -> TypeTable * {
    
    return this->_pTypes;
}


auto Scope :: _copyScope (
    Scope * pOtherScope
) -> void {
    this->_pTypes = pOtherScope->_pTypes;
    this->_pUpperScope = pOtherScope->_pUpperScope;
    for ( auto e : * pOtherScope->_pSymbols->getSymbols() ) {
        auto pVar = dynamic_cast < VariableEntry * > ( e );
        if ( pVar != nullptr ) {
            this->addVariable ( pVar->getType()->getName(), pVar->getName() );
        } else {
            this->_pSymbols->addSymbol ( e );
        }
    }
}


auto Scope :: _typeExistenceCheck (
    char const * pTypeName
) -> TypeEntry * {

    auto pType = this->_pTypes->getType ( pTypeName );
    if ( pType == nullptr ) { 
        if ( this->_pUpperScope != nullptr ) {
            pType = this->_pUpperScope->_typeExistenceCheck ( pTypeName );
        }
    }
    return pType;
}


auto Scope :: addVariable (
    char const * pSymbolType,
    char const * pSymbolName
) -> VariableEntry * {

    auto pType = this->_typeExistenceCheck ( pSymbolType );
    if ( pType == nullptr ) {
        error :: undefinedType ( pSymbolType );
        return nullptr;
    }

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pSymbolName );
    if ( symbolEntry != nullptr ) {
        error :: variableRedeclaration ( pSymbolName, symbolEntry );
        return nullptr;
    }

    auto pNewEntry = new VariableEntry (
                        pSymbolName,
                        pType
                    );

    if ( * pType->getName() >= '0' && * pType->getName() <= '9' ) {
        Scope * pScopeView = new Scope;
        auto pCopiedScope = ( reinterpret_cast < StructuredTypeEntry * > ( pType ) )->getScope();
        pScopeView->_copyScope ( pCopiedScope );
        pNewEntry->setValue ( pScopeView );
    }

    this->_pSymbols->addSymbol ( 
            pNewEntry
        );
    return pNewEntry;
}


auto Scope :: addVariable (
    TypeEntry  * pSymbolType,
    char const * pSymbolName
) -> VariableEntry * {

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pSymbolName );
    if ( symbolEntry != nullptr ) {
        error :: variableRedeclaration ( pSymbolName, symbolEntry );
        return nullptr;
    }

    auto pNewEntry = new VariableEntry (
                        pSymbolName,
                        pSymbolType
                    );

    this->_pSymbols->addSymbol ( 
            pNewEntry
        );
    return pNewEntry;
}


auto Scope :: addArrayVariable (
    char const * pBaseType,
    char const * pSymbolName,
    char const * pArrayType,
    TypeLength   arraySize
) -> void {

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pSymbolName );
    if ( symbolEntry != nullptr ) {
        error :: variableRedeclaration ( pSymbolName, symbolEntry );
        return;
    }

    auto pType = this->_typeExistenceCheck ( pBaseType );
    if ( pType == nullptr ) {
        error :: undefinedType ( pBaseType );
        return;
    }

    std :: string arrayComposedType = std :: string ( pArrayType ) + pType->getName();
    auto pNewArrayType = this->_typeExistenceCheck ( arrayComposedType.c_str() );
    if ( pNewArrayType == nullptr ) {

        pNewArrayType = new ArrayTypeEntry ( arrayComposedType.c_str(), arraySize * pType->getLength(), pType );
        this->_pTypes->addType ( pNewArrayType );
    }
    
    auto pNewEntry = new VariableEntry (
            pSymbolName,
            pNewArrayType
        );

    auto arrayValues = new VariableEntry * [ arraySize ];
    for ( auto i = 0; i < arraySize; ++ i ) {
        arrayValues[ i ] = new VariableEntry ( std :: to_string ( i ).c_str(), pType ); 
    }
    pNewEntry->setValue ( arrayValues );
    this->_pSymbols->addSymbol ( pNewEntry );
}


auto Scope :: addFunction (
    char const                   * pFunctionName,
    char const                   * pReturnTypeName,
    TreeNode                     * pFunctionBody,
    ParameterDeclarationList     * pParameterListTypes,
    Scope                        * pScope
) -> void {

    auto pReturnType = this->_typeExistenceCheck ( pReturnTypeName );
    if ( pReturnType == nullptr ) {
        error :: undefinedType ( pReturnTypeName );
        return;
    }

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pFunctionName );
    if ( symbolEntry != nullptr ) {
        error :: functionRedeclaration ( pFunctionName, symbolEntry );
        return;
    }

    auto pParameters = new ParameterList;
    for ( auto e : * pParameterListTypes ) {
        auto pType = this->_typeExistenceCheck ( e->first );
        if ( pType == nullptr ) {
            error :: undefinedType ( e->first );
            pType = pGlobalScope->getTypeTable()->getTypes()->front();
        }
        pParameters->push_back ( pScope->addVariable ( pType, e->second ) );
    }
    pScope->addVariable ( pReturnTypeName, "$return" );

    this->_pSymbols->addSymbol ( 
        new FunctionEntry (
                pFunctionName,
                pGlobalScope->getTypeTable()->getType ( "function" ),
                pFunctionBody,
                pParameters,
                pScope
            )
        );
}



auto Scope :: addUserDefinedType ( 
    char const * pTypeName,
    Scope *      pTypeScope
) -> StructuredTypeEntry * {

    auto pTypeEntry = this->_pTypes->getType ( pTypeName );
    if ( pTypeEntry != nullptr ) {
        error :: redefinedType ( pTypeName );
        return nullptr;
    }


    std :: string prefixedTypeName = std :: to_string ( strlen ( pTypeName ) ) + pTypeName;
    auto pNewEntry = new StructuredTypeEntry ( prefixedTypeName.c_str(), pTypeScope );
    this->_pTypes->addType ( pNewEntry );
    return pNewEntry;
}


auto Scope :: setUserDefinedTypeLength (
    StructuredTypeEntry * pTypeEntry
) -> void {

    TypeLength typeLength = 0;
    for ( auto e : * pTypeEntry->getScope()->getSymbolTable()->getSymbols() ) {
        auto entryType = dynamic_cast < VariableEntry * > ( e );
        if ( entryType != nullptr ) {
            typeLength += entryType->getType()->getLength();
        }
    }

    this->_pTypes->setTypeLength ( pTypeEntry, typeLength == 0 ? 1 : typeLength );
}


auto Scope :: getSymbol (
    char const * pSymbolName
) -> SymbolEntry * {

    SymbolEntry * pSymbol = this->_pSymbols->lookUpSymbol ( pSymbolName );
    if ( pSymbol == nullptr ) {
        if ( this->_pUpperScope != nullptr ) {
            pSymbol = this->_pUpperScope->getSymbol ( pSymbolName );
        }
    }
    return pSymbol;
}
#endif //__SCOPE_IMPL_HPP__