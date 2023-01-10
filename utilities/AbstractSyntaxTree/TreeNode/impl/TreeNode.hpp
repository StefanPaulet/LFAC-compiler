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
            switch ( this->_nodeType ) {
                case __INT : {
                    return this->_pChildList[0]->eval().intValue + this->_pChildList[1]->eval().intValue;
                }
                case __FLOAT : {
                    return this->_pChildList[0]->eval().floatValue + this->_pChildList[1]->eval().floatValue;
                }
                case __BOOL : {
                    return this->_pChildList[0]->eval().boolValue + this->_pChildList[1]->eval().boolValue;
                }
                case __CHAR : {
                    return this->_pChildList[0]->eval().charValue + this->_pChildList[1]->eval().charValue;
                }
                case __STRING : {
                    break;
                }
            }
            
        }
        case __MINUS: {
            switch ( this->_nodeType ) {
                case __INT : {
                    return this->_pChildList[0]->eval().intValue - this->_pChildList[1]->eval().intValue;
                }
                case __FLOAT : {
                    return this->_pChildList[0]->eval().floatValue - this->_pChildList[1]->eval().floatValue;
                }
                case __BOOL : {
                    return this->_pChildList[0]->eval().boolValue - this->_pChildList[1]->eval().boolValue;
                }
                case __CHAR : {
                    return this->_pChildList[0]->eval().charValue - this->_pChildList[1]->eval().charValue;
                }
                case __STRING : {
                    break;
                }
            }
        }
        case __UMINUS: {
            switch ( this->_nodeType ) {
                case __INT : {
                    return -this->_pChildList[0]->eval().intValue;
                }
                case __FLOAT : {
                    return -this->_pChildList[0]->eval().floatValue;
                }
                case __BOOL : {
                    return -this->_pChildList[0]->eval().boolValue;
                }
                case __CHAR : {
                    return -this->_pChildList[0]->eval().charValue;
                }
                case __STRING : {
                    break;
                }
            }
        }
        case __MUL: {
            switch ( this->_nodeType ) {
                case __INT : {
                    return this->_pChildList[0]->eval().intValue * this->_pChildList[1]->eval().intValue;
                }
                case __FLOAT : {
                    return this->_pChildList[0]->eval().floatValue * this->_pChildList[1]->eval().floatValue;
                }
                case __BOOL : {
                    return this->_pChildList[0]->eval().boolValue * this->_pChildList[1]->eval().boolValue;
                }
                case __CHAR : {
                    return this->_pChildList[0]->eval().charValue * this->_pChildList[1]->eval().charValue;
                }
                case __STRING : {
                    break;
                }
            }
        }
        case __DIV: {
            switch ( this->_nodeType ) {
                case __INT : {
                    return this->_pChildList[0]->eval().intValue / this->_pChildList[1]->eval().intValue;
                }
                case __FLOAT : {
                    return this->_pChildList[0]->eval().floatValue / this->_pChildList[1]->eval().floatValue;
                }
                case __BOOL : {
                    return this->_pChildList[0]->eval().boolValue / this->_pChildList[1]->eval().boolValue;
                }
                case __CHAR : {
                    return this->_pChildList[0]->eval().charValue / this->_pChildList[1]->eval().charValue;
                }
                case __STRING : {
                    break;
                }
            }
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


auto TreeNode :: setChildCount (
    unsigned int childCount
) -> void {
    
    this->_childCount = childCount;
}


auto TreeNode :: getType () -> ValueType {
    return this->_nodeType;
}


auto TreeNode :: setType (
    ValueType type
) -> void {
    this->_nodeType = type;
}

#endif //__TREE_NODE_IMPL_HPP__