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


VariableEntry :: ~VariableEntry () {

    delete ( this->_pName );
}


auto VariableEntry :: getTypeName () const -> std :: string { 

    return std :: string ( this->_pType->getName() );
}


constexpr auto VariableEntry :: getType () const -> TypeEntry * {

    return this->_pType;
}


auto VariableEntry :: getValue () -> VarValue & {

    return this->_val;
}


auto VariableEntry :: setValue (
    VarValue val
) -> void {

    this->_val = val;
}
#endif //__VARIABLE_ENTRY_IMPL_HPP__