#ifndef __TREE_NODE_IDENTIFIER_HPP__
#define __TREE_NODE_IDENTIFIER_HPP__

#include "TreeNode.hpp"

#include <string.h>

class TreeNodeIdentifier : public TreeNode {

private:
    char const * _name { nullptr };

public:
    TreeNodeIdentifier () = default;

    TreeNodeIdentifier ( TreeNodeIdentifier const * node ) :
        TreeNode ( node ),
        _name    ( node->_name ) {

        }

    TreeNodeIdentifier (
        _OPERATORS      label,
        unsigned int    childCount,
        TreeNode * *    pChildList,
        char const *    name
    ) : 
        TreeNode ( label, childCount, pChildList ),
        _name    ( strdup ( name ) ) {

        }
};

#endif //__TREE_NODE_IDENTIFIER_HPP__