#ifndef __TYPE_ENTRY_HPP__
#define __TYPE_ENTRY_HPP__

#include <string.h>

class TypeEntry {

public:
    using TypeLength = unsigned short int;

protected:
    char const * _pName { nullptr };

    TypeLength _length { 0 };

public:
    TypeEntry () = delete;
    TypeEntry ( TypeEntry const & ) = delete;
    TypeEntry ( TypeEntry && ) = delete;

    TypeEntry ( 
        char const * pName 
    ) : _pName ( strdup ( pName ) ) {

    }


    TypeEntry ( 
        char const * pName,
        TypeLength   length
    ) : 
        _pName  ( strdup ( pName ) ),
        _length ( length ) {

        }


    constexpr auto getName () const -> char const * const {
        
        return this->_pName;
    }


    constexpr auto getLength () const -> TypeLength {

        return this->_length;
    }


    auto setLength (
        TypeLength length
    ) -> void {

        this->_length = length;
    }
};

#endif //__TYPE_ENTRY_HPP__