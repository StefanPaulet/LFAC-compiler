#ifndef __TREE_NODE_HPP__
#define __TREE_NODE_HPP__

class TreeNode {

protected:
    enum _OPERATORS {
        __PLUS,
        __MINUS,
        __MUL,
        __DIV,
        __ASG,
        __BNOT,
        __BAND,
        __BOR,
        __BXOR,
        __VAR,
        __CONST,
        __IF,
        __WHILE,
        __FOR,
        __FUNC,
        __CALL,
        __ROOT
    };

    _OPERATORS   _label { __ROOT };

    unsigned int _childCount { 0 };

    TreeNode * * _pChildList { nullptr };

public:
    TreeNode () = default;

    TreeNode ( TreeNode const * node ) {

        this->_label      = node->_label;
        this->_childCount = node->_childCount;
        this->_pChildList = new TreeNode * [ node->_childCount ];

        for ( auto i = 0; i < node->_childCount; ++ i ) {
            this->_pChildList [ i ] = new TreeNode ( node->_pChildList [ i ] );
        }
    }

    TreeNode (
        _OPERATORS   label,
        unsigned int childCount,
        TreeNode * * pchildList
    ) :
        _label      ( label ),
        _childCount ( childCount) {

            if ( pchildList != nullptr ) {
                this->_pChildList = new TreeNode * [ childCount ];
                for ( auto i = 0; i < childCount; ++ i ) {
                    this->_pChildList [ i ] = new TreeNode ( pchildList [ i ] );
                }
            }
        }

    ~TreeNode () {

        if ( this->_pChildList != nullptr ) { 
            for ( auto i = 0; i < this->_childCount; ++ i ) {
                delete this->_pChildList [ i ];
            }
            delete[] this->_pChildList;
        }
    }
};

#endif //__TREE_NODE_HPP__