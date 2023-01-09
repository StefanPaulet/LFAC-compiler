#ifndef __TREE_NODE_IDENTIFIER_HPP__
#define __TREE_NODE_IDENTIFIER_HPP__

#include "TreeNode.hpp"
#include "../../SymbolTable/SymbolEntry/VariableEntry/VariableEntry.hpp"

#include <string.h>

class TreeNodeIdentifier : public TreeNode {

private:
    VariableEntry * _pEntry { nullptr };

public:
    TreeNodeIdentifier () = default;

    TreeNodeIdentifier ( TreeNodeIdentifier const * node );

    TreeNodeIdentifier (
        _OPERATORS      label,
        unsigned int    childCount,
        TreeNode * *    pChildList,
        char const *    pEntry
    );
};

#include "../../SymbolTable/SymbolEntry/VariableEntry/impl/VariableEntry.hpp"

#endif //__TREE_NODE_IDENTIFIER_HPP__