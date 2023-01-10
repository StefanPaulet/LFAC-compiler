#ifndef __VARIABLE_ENTRY_IMPL_HPP__
#define __VARIABLE_ENTRY_IMPL_HPP__

VariableEntry :: VariableEntry ( 
        char const *    pName,
        TypeEntry  *    pType
) : 
    SymbolEntry ( pName ),
    _pType      ( pType ) {
    }

VariableEntry :: VariableEntry (
        char const *    pName,
        TypeEntry  *    pType,
        VarValue        val
) :
    VariableEntry ( 
        pName, 
        pType 
    ) {

        this->_val = val;
    }

VariableEntry :: VariableEntry (
    VariableEntry const & var
) : 
    VariableEntry ( var._pName, var._pType ) {
        
    }

VariableEntry :: ~VariableEntry () {

    delete ( this->_pName );
}


auto VariableEntry :: getTypeName () const -> std :: string { 

    return std :: string ( this->_pType->getName() );
}


constexpr auto VariableEntry :: getType () const -> TypeEntry * {

    return this->_pType;
}


auto VariableEntry :: getValue () -> VarValue {

    return this->_val;
}


auto VariableEntry :: setValue (
    VarValue val
) -> void {


    std :: cout << this << ' ' << this->_pName << " has value " << this->_val.intValue << '\n';
    this->_val = val;

    std :: cout << this << ' ' << this->_pName << " get value " << this->_val.intValue << '\n';
}


constexpr auto VariableEntry :: getConstQualifier () -> bool {
    
    return this->_constQualified;
}


auto VariableEntry :: setConstQualifier (
    bool constQualified
) -> void {

    this->_constQualified = constQualified;
}
#endif //__VARIABLE_ENTRY_IMPL_HPP__