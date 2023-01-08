#ifndef __TYPE_ENTRY_HPP__
#define __TYPE_ENTRY_HPP__

#include <string.h>

class TypeEntry {

public:
    using TypeLength = unsigned short int;
    using ArraytypePair = std :: pair < char *, TypeLength >;

protected:
    char const * _pName { nullptr };

    TypeLength _length { 0 };

public:
    TypeEntry () = delete;
    TypeEntry ( TypeEntry const & ) = delete;
    TypeEntry ( TypeEntry && ) = delete;

    TypeEntry ( 
        char const * pName 
    );


    TypeEntry ( 
        char const * pName,
        TypeLength   length
    );


    constexpr auto getName () const -> char const * const;


    constexpr auto getLength () const -> TypeLength;


    auto setLength (
        TypeLength length
    ) -> void;


    auto matchArraySubscript (
        ArraytypePair * pArraytype
    ) -> bool;

};

#endif //__TYPE_ENTRY_HPP__