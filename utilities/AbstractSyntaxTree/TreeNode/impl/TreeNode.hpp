#ifndef __TREE_NODE_IMPL_HPP__
#define __TREE_NODE_IMPL_HPP__

TreeNode :: ~TreeNode () {

    if ( this->_pChildList != nullptr ) { 
        for ( auto i = 0; i < this->_childCount; ++ i ) {
            delete this->_pChildList [ i ];
        }
        delete[] this->_pChildList;
    }
}

auto TreeNode :: setChildList (
    TreeNode * * pChildList
) -> void {
    this->_pChildList = pChildList;
}

auto TreeNode :: setParent (
    TreeNode * pParent
) -> void {
    this->_pParent = pParent;
}

auto TreeNode :: eval () -> ValueUnion {
    
    switch ( this->_label ) {
        case __PLUS: {
            return this->_pChildList[0]->eval().intValue + this->_pChildList[1]->eval().intValue;
        }
        case __MINUS: {
            return this->_pChildList[0]->eval().intValue - this->_pChildList[1]->eval().intValue;
        }
        case __UMINUS: {
            return - this->_pChildList[0]->eval().intValue;
        }
        case __MUL: {
            return this->_pChildList[0]->eval().intValue * this->_pChildList[1]->eval().intValue;
        }
        case __DIV: {
            return this->_pChildList[0]->eval().intValue / this->_pChildList[1]->eval().intValue;
        }
        case __ASG: {
            ValueUnion aux = this->_pChildList[1]->eval();
            ( reinterpret_cast < TreeNodeIdentifier * > ( this->_pChildList[0] ) )->setVal ( aux );
            break;
        }
        case __STMT: {
            if ( this->_childCount != 0 ) {
                this->_pChildList[0]->eval();
                this->_pChildList[1]->eval();
            }
            break;
        }
        case __FUNC:
        case __CALL:
        case __VAR: {
            ( reinterpret_cast < TreeNodeIdentifier * > ( this ) )->eval();
            break;
        }
        case __CONST: {
            ( reinterpret_cast < TreeNodeConstant * > ( this ) )->eval();
            break;
        }
    }
    return 0;
};

#endif //__TREE_NODE_IMPL_HPP__