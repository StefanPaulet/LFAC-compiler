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


auto Scope :: addVariable (
        char const * pSymbolType,
        char const * pSymbolName
) -> bool {

    auto symbolEntry = this->_pSymbols->lookUpSymbol ( pSymbolName );
    if ( symbolEntry != nullptr ) {
        error :: variableAddingError ( pSymbolName, symbolEntry );
        return false;
    }

    auto pType = this->_pTypes->getType ( pSymbolType );
    if ( pType == nullptr ) { 
        pType = this->_pGlobalScope->getTypeTable()->getType ( pSymbolType );
        if ( pType == nullptr ) {
            error :: undefinedTypeError ( pSymbolType );
            return false;
        }
    }

    this->_pSymbols->addSymbol ( 
        new VariableEntry (
                pSymbolName,
                pType
            )
        );
    return true;
}


auto Scope :: addUserDefinedType ( 
    char const * pTypeName,
    Scope *      pTypeScope
) -> StructuredTypeEntry * {

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