#ifndef __ABSTRACT_SYNTAX_TREE_HPP__
#define __ABSTRACT_SYNTAX_TREE_HPP__

#include "TreeNode/TreeNodeConstant.hpp"
#include "TreeNode/TreeNodeIdentifier.hpp"

class AbstractSyntaxTree {

public:
    using ASTOperators = TreeNode :: _OPERATORS;
private:
    TreeNode * _pRoot { };

public:
    AbstractSyntaxTree(
        TreeNode * pGlobalInitialization,
        TreeNode * pMainFunction
    );

    auto eval() -> void;
};

#include "TreeNode/impl/TreeNode.hpp"
#include "TreeNode/impl/TreeNodeIdentifier.hpp"
#include "TreeNode/impl/TreeNodeConstant.hpp"

#endif //__ABSTRACT_SYNTAX_TREE_HPP__