#ifndef __TREE_NODE_IDENTIFIER_IMPL_HPP__
#define __TREE_NODE_IDENTIFIER_IMPL_HPP__


TreeNodeIdentifier :: TreeNodeIdentifier (
    _OPERATORS     label,
    ValueType      type,
    SymbolEntry * pEntry
) : 
    TreeNode ( label, type, 0, nullptr ),
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

    switch ( this->_nodeType ) {
        case __STRING: {
            return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().stringValue;
        }
        case __CHAR: {
            return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().charValue;
        }
        case __BOOL: {
            return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().boolValue;
        }
        case __INT: {
            return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().intValue;
        }
        default: {
            return ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->getValue().floatValue;
        }
    }
}


auto TreeNodeIdentifier :: setVal ( 
    ValueUnion val
) -> void {

    switch ( this->_nodeType ) {
        case __STRING: {
            ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.stringValue );
            break;
        }
        case __CHAR: {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.charValue );
            break;
        }
        case __BOOL: {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.boolValue );
            break;
        }
        case __INT: {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.intValue );
            break;
        }
        case __FLOAT: {
        ( reinterpret_cast < VariableEntry * > ( this->_pEntry ) )->setValue ( val.floatValue );
            break;
        }
    }
}


auto TreeNodeIdentifier :: eval () -> ValueUnion {

    switch ( this->_label ) {
        case __FUNC : {
            break;
        }
        case __CALL : {
            auto pFunction = ( reinterpret_cast < FunctionEntry * > ( ( reinterpret_cast < TreeNodeIdentifier * > ( this->_pChildList[0] ) )->getSymbol() ) );
            auto pParameterEntries = pFunction->getParameterList()->begin();
            for ( auto i = 1; i < this->_childCount; ++ i ) {
                ( reinterpret_cast < VariableEntry * > ( * pParameterEntries ) )->setValue ( 
                    ( reinterpret_cast < VariableEntry * > ( ( reinterpret_cast < TreeNodeIdentifier * > ( this->_pChildList[i] ) )->getSymbol() ) )->getValue()
                );
                ++ pParameterEntries;
            }
            pFunction->getFunctionBody()->eval();
            return this->getVal();
        }
        case __VAR : {
            return this->getVal();
        }
    }
    return 0;
}
#endif //__TREE_NODE_IDENTIFIER_IMPL_HPP__