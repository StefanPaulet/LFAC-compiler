#ifndef __TYPE_TABLE_HPP__
#define __TYPE_TABLE_HPP__

#include "TypeEntry/StructuredTypeEntry/StructuredTypeEntry.hpp"
#include "TypeEntry/ArrayTypeEntry/ArrayTypeEntry.hpp"

class TypeTable {

public:
    using TypeList = std :: list < TypeEntry * >;
    using TypeLength = TypeEntry :: TypeLength;

private:
    TypeList * _pTypes = new TypeList;

public:
    TypeTable ( 
        TypeList * pInitialTypes = nullptr
    );


    auto constexpr getTypes () -> TypeList *;


    auto addType ( 
        TypeEntry * pNewType
    ) -> void;


    auto getType ( 
        char const * pTypeName
    ) -> TypeEntry *;


    auto setTypeLength ( 
        StructuredTypeEntry * pType,
        TypeLength            length
    ) -> void;
};

#include "TypeEntry/ArrayTypeEntry/impl/ArrayTypeEntry.hpp"
#include "TypeEntry/StructuredTypeEntry/impl/StructuredTypeEntry.hpp"

#endif //__TYPE_TABLE_HPP__