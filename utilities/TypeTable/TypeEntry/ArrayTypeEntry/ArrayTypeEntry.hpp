#ifndef __ARRAY_TYPE_ENTRY_HPP__
#define __ARRAY_TYPE_ENTRY_HPP__

#include "../TypeEntry.hpp"

class ArrayTypeEntry : public TypeEntry {

public:
    using TypeEntry :: TypeLength;

private:
    TypeEntry * _pAliasedType;

public:
    ArrayTypeEntry (
        char const * pName,
        TypeLength   length,
        TypeEntry  * pAliasedType
    );
};

#include "../impl/TypeEntry.hpp"

#endif //__ARRAY_TYPE_ENTRY_HPP__