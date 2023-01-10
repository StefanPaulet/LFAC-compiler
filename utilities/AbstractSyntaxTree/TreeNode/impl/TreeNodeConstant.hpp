#ifndef __TREE_NODE_CONSTANT_IMPL_HPP__
#define __TREE_NODE_CONSTANT_IMPL_HPP__

TreeNodeConstant :: TreeNodeConstant (
    ValueType          type,
    ValueUnion const & value
) : 
    TreeNode ( __CONST, type, 0, nullptr ),
    _value   ( value ) {

    }

auto TreeNodeConstant :: eval () -> ValueUnion {
    switch ( this->_nodeType ) {
        case __STRING: {
            return this->_value.stringValue;
            break;
        }
        case __CHAR: {
            return this->_value.charValue;
            break;
        }
        case __BOOL: {
            return this->_value.boolValue;
            break;
        }
        case __INT: {
            return this->_value.intValue;
            break;
        }
        case __FLOAT: {
            return this->_value.floatValue;
            break;
        }
    }
    return 0;
}

#endif //__TREE_NODE_CONSTANT_IMPL_HPP__
