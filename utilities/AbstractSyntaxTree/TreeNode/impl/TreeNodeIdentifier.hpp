#ifndef __TREE_NODE_IDENTIFIER_IMPL_HPP__
#define __TREE_NODE_IDENTIFIER_IMPL_HPP__

TreeNodeIdentifier :: TreeNodeIdentifier ( TreeNodeIdentifier const * node ) :
    TreeNode ( node ),
    _pEntry  ( node->_pEntry ) {

    }


TreeNodeIdentifier (
    _OPERATORS      label,
    unsigned int    childCount,
    TreeNode * *    pChildList,
    VariableEntry * pEntry
) : 
    TreeNode ( label, childCount, pChildList ),
    _pEntry  ( pEntry ) {

    }

#endif //__TREE_NODE_IDENTIFIER_IMPL_HPP__