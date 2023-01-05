#ifndef __TREE_NODE_CONSTANTS_HPP__
#define __TREE_NODE_CONSTANTS_HPP__

#include "TreeNode.hpp"
#include <string.h>

class TreeNodeConstants : public TreeNode {

private:
    union ValueType {
        char const * stringValue;
        char         charValue;
        bool         boolValue;
        int          intValue;

        ValueType () = default;
        explicit ValueType ( char const * str ) : stringValue ( strdup ( str ) ) {} 
        explicit ValueType ( char chr ) : charValue ( chr ) {}
        explicit ValueType ( bool val ) : boolValue ( val ) {}
        explicit ValueType ( int val ) : intValue ( val ) {}
    } _value;

public:
    TreeNodeConstants () = default;

    TreeNodeConstants ( TreeNodeConstants const * node ) :
        TreeNode ( node ),
        _value    ( node->_value ) {

        }

    TreeNodeConstants (
        _OPERATORS          label,
        unsigned int        childCount,
        TreeNode * *        pChildList,
        ValueType const &   value
    ) : 
        TreeNode ( label, childCount, pChildList ),
        _value   ( value ) {

        }
};

#endif //__TREE_NODE_CONSTANTS_HPP__