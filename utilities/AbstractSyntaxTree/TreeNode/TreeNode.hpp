#ifndef __TREE_NODE_HPP__
#define __TREE_NODE_HPP__

class TreeNode {

public:
    enum _OPERATORS {
        __PLUS,
        __MINUS,
        __UMINUS,
        __MUL,
        __DIV,
        __ASG,
        __BNOT,
        __BAND,
        __BOR,
        __VAR,
        __CONST,
        __IF,
        __WHILE,
        __FOR,
        __FUNC,
        __CALL,
        __STMT,
        __ROOT
    };

    enum ValueType {
        __STRING, __CHAR, __BOOL, __FLOAT, __INT, __NON_VALUE
    };

    union ValueUnion {
        char const * stringValue;
        char         charValue;
        bool         boolValue;
        float        floatValue;
        int          intValue;

        ValueUnion () = default;
        ValueUnion ( char const * str ) : stringValue ( strdup ( str ) ) {} 
        ValueUnion ( char chr ) : charValue ( chr ) { }
        ValueUnion ( bool val ) : boolValue ( val ) { }
        ValueUnion ( float val ) : floatValue ( val ) { }
        ValueUnion ( int val ) : intValue ( val ) { }
    };

protected:

    _OPERATORS   _label { __ROOT };

    ValueType    _nodeType { __NON_VALUE };

    unsigned int _childCount { 0 };

    TreeNode * * _pChildList { nullptr };

    TreeNode *   _pParent { nullptr };

public:
    TreeNode () = default;

    TreeNode (
        _OPERATORS   label,
        ValueType    type,
        unsigned int childCount,
        TreeNode * * pchildList
    ) :
        _label      ( label ),
        _nodeType   ( type ),
        _childCount ( childCount),
        _pChildList ( pchildList ) {
        }

    ~TreeNode ();


    auto setChildList (
        TreeNode * * pChildList
    ) -> void;
    auto setParent (
        TreeNode * pParent
    ) -> void;


    virtual auto eval () -> ValueUnion;


    auto setChildCount (
        unsigned int childCount
    ) -> void;


    auto getType () -> ValueType;


    auto setType (
        ValueType type
    ) -> void;
};

#endif //__TREE_NODE_HPP__