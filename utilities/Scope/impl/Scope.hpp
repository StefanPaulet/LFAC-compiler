#ifndef __SCOPE_IMPL_HPP__
#define __SCOPE_IMPL_HPP__

Scope :: Scope ( 
    Scope     * pUpperScope,
    Scope     * pGlobalScope, 
    TypeTable * pTypes      
) :
    _pUpperScope  ( pUpperScope ),
    _pGlobalScope ( pGlobalScope ) {

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


auto Scope :: _typeExistenceCheck (
    char const * pTypeName
) -> TypeEntry * {

    auto pType = this->_pTypes->getType ( pTypeName );
    if ( pType == nullptr && this->_pGlobalScope != nullptr ) { 

        pType = this->_pGlobalScope->getTypeTable()->getType ( pTypeName );
    }
    return pType;
}


auto Scope :: addVariable (
    char const * pSymbolType,
    char const * pSymbolName
) -> void {

    auto pType = this->_typeExistenceCheck ( pSymbolType );
    if ( pType == nullptr ) {
        error :: undefinedTypeError ( pSymbolType );
        return;
    }

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pSymbolName );
    if ( symbolEntry != nullptr ) {
        error :: variableAddingError ( pSymbolName, symbolEntry );
        return;
    }
    this->_pSymbols->addSymbol ( 
        new VariableEntry (
                pSymbolName,
                pType
            )
        );
}


auto Scope :: addFunction (
    char const                   * pFunctionName,
    char const                   * pReturnTypeName,
    TreeNodeIdentifier           * pFunctionBody,
    std :: list < char const * > * pParameterListTypes
) -> void {

    auto pReturnType = this->_typeExistenceCheck ( pReturnTypeName );
    if ( pReturnType == nullptr ) {
        error :: undefinedTypeError ( pReturnTypeName );
        return;
    }

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pFunctionName );
    if ( symbolEntry != nullptr ) {
        error :: functionAddingError ( pFunctionName, symbolEntry );
        return;
    }

    auto pParameters = new ParameterList;
    for ( auto e : * pParameterListTypes ) {
        auto pType = this->_typeExistenceCheck ( e );
        if ( pType == nullptr ) {
            error :: undefinedTypeError ( e );
            pType = this->_pGlobalScope->getTypeTable()->getTypes()->front();
        }
        pParameters->push_back ( pType );
    }

    this->_pSymbols->addSymbol ( 
        new FunctionEntry (
                pFunctionName,
                pReturnType,
                pFunctionBody,
                pParameters
            )
        );
}



auto Scope :: addUserDefinedType ( 
    char const * pTypeName,
    Scope *      pTypeScope
) -> StructuredTypeEntry * {

    auto pTypeEntry = this->_pTypes->getType ( pTypeName );
    if ( pTypeEntry != nullptr ) {
        error :: redefinedTypeError ( pTypeName );
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
#endif //__SCOPE_IMPL_HPP__