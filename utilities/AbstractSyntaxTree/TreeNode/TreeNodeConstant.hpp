#ifndef __TREE_NODE_CONSTANT_HPP__
#define __TREE_NODE_CONSTANT_HPP__

#include "TreeNode.hpp"
#include <string.h>

class TreeNodeConstant : public TreeNode {

public:
    using TreeNode :: ValueType;
    using TreeNode :: ValueUnion;

private:
    ValueType _type;
    ValueUnion _value;

public:
    TreeNodeConstant () = default;

    TreeNodeConstant (
        ValueType          type,
        ValueUnion const & value
    );

    auto eval () -> ValueUnion override;
};

#endif //__TREE_NODE_CONSTANTS_HPP__