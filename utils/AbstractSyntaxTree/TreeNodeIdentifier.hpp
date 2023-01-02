#ifndef __TREE_NODE_IDENTIFIER_HPP__
#define __TREE_NODE_IDENTIFIER_HPP__

#include "TreeNode.hpp"

#include <string>

class TreeNodeIdentifier : public TreeNode {

private:
    std :: string _name { };

public:
    TreeNodeIdentifier () = default;

    TreeNodeIdentifier ( TreeNodeIdentifier const * node ) :
        TreeNode ( node ),
        _name    ( node->_name ) {

        }

    TreeNodeIdentifier (
        _OPERATORS   label,
        unsigned int childCount,
        TreeNode * * pChildList,
        std :: string && name
    ) : 
        TreeNode ( label, childCount, pChildList ),
        _name    ( std :: move ( name ) ) {

        }
};

#endif //__TREE_NODE_IDENTIFIER_HPP__