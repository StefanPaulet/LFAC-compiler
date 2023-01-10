#ifndef __ABSTRACT_SYNTAX_TREE_IMPL_HPP__
#define __ABSTRACT_SYNTAX_TREE_IMPL_HPP__

AbstractSyntaxTree :: AbstractSyntaxTree (
    TreeNode * pGlobalInitialization,
    TreeNode * pMainFunction
) {
    auto pChildren = new TreeNode * [ 2 ];
    pChildren [ 0 ] = pGlobalInitialization;
    pChildren [ 1 ] = pMainFunction;
    this->_pRoot = new TreeNode ( ASTOperators :: __STMT, 2, pChildren );
}


auto AbstractSyntaxTree :: eval () -> void{

    this->_pRoot->eval();
}

#endif //__ABSTRACT_SYNTAX_TREE_IMPL_HPP__