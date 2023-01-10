#ifndef __TREE_NODE_IDENTIFIER_HPP__
#define __TREE_NODE_IDENTIFIER_HPP__

#include "TreeNode.hpp"
#include "../../SymbolTable/SymbolEntry/VariableEntry/VariableEntry.hpp"

#include <string.h>

class TreeNodeIdentifier : public TreeNode {

private:
    using TreeNode :: ValueType;
    using TreeNode :: _OPERATORS;
    SymbolEntry * _pEntry { nullptr };

public:
    TreeNodeIdentifier () = default;

    TreeNodeIdentifier (
        _OPERATORS      label,
        ValueType       type,
        SymbolEntry *   pEntry
    );


    auto getSymbol () -> SymbolEntry *;


    auto setSymbol (
        SymbolEntry * pNewSymbol
    ) -> void;


    auto setLabel (
        _OPERATORS newLabel
    ) -> void;


    auto getVal () -> ValueUnion;

    auto setVal ( 
        ValueUnion val
    ) -> void;

    auto eval () -> ValueUnion override;
};

#include "../../SymbolTable/SymbolEntry/VariableEntry/impl/VariableEntry.hpp"

#endif //__TREE_NODE_IDENTIFIER_HPP__