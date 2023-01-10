#ifndef __TREE_NODE_IDENTIFIER_IMPL_HPP__
#define __TREE_NODE_IDENTIFIER_IMPL_HPP__


TreeNodeIdentifier :: TreeNodeIdentifier (
    _OPERATORS     label,
    SymbolEntry * pEntry
) : 
    TreeNode ( label, 0, nullptr ),
    _pEntry  ( pEntry ) {

    }


auto TreeNodeIdentifier :: getSymbol () -> SymbolEntry * {

    return this->_pEntry;
}


auto TreeNodeIdentifier :: setSymbol (
    SymbolEntry * pNewSymbol
) -> void {

    this->_pEntry = pNewSymbol;
}


auto TreeNodeIdentifier :: setLabel (
    _OPERATORS newLabel
) -> void {

    this->_label = newLabel;
}


auto TreeNodeIdentifier :: getVal () -> ValueUnion {

    if ( this->_pEntry->getTypeName() == "float" ) {
        return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().floatValue;
    }
    if ( this->_pEntry->getTypeName() == "char" ) {
        return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().charValue;
    }
    if ( this->_pEntry->getTypeName() == "bool" ) {
        return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().boolValue;
    }
    if ( this->_pEntry->getTypeName() == "string" ) {
        return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().stringValue;
    }
    return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().intValue;
}


auto TreeNodeIdentifier :: setVal ( 
    ValueUnion val
) -> void {

    if ( this->_pEntry->getTypeName() == "int" ) {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.intValue );
        return;
    }
    if ( this->_pEntry->getTypeName() == "float" ) {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.floatValue );
        return;
    }
    if ( this->_pEntry->getTypeName() == "char" ) {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.charValue );
        return;
    }
    if ( this->_pEntry->getTypeName() == "bool" ) {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.boolValue );
        return;
    }
    if ( this->_pEntry->getTypeName() == "string" ) {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.stringValue );
        return;
    }
}


auto TreeNodeIdentifier :: eval () -> ValueUnion {

    switch ( this->_label ) {
        case __FUNC : {
            break;
        }
        case __CALL : {
            return 0;
        }
        case __VAR : {
            return this->getVal();
        }
    }
    return 0;
}
#endif //__TREE_NODE_IDENTIFIER_IMPL_HPP__