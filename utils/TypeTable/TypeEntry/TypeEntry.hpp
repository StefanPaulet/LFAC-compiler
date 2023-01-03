#ifndef __TYPE_ENTRY_HPP
#define __TYPE_ENTRY_HPP

#include <string.h>

class TypeEntry {

protected:
    char const * _pName { nullptr };

    unsigned short int _length { 0 };

public:
    TypeEntry () = delete;
    TypeEntry ( TypeEntry const & ) = delete;
    TypeEntry ( TypeEntry && ) = delete;

    TypeEntry ( 
        char const * pName 
    ) : _pName ( pName ) {

    }


    TypeEntry ( 
        char const * pName,
        unsigned short int length
    ) : 
        _pName  ( strdup ( pName ) ),
        _length ( length ) {

        }

    constexpr auto getTypeName () const -> char const * const {
        return this->_pName;
    }

    constexpr auto getTypeLength () const -> unsigned short int {
        return this->_length;
    }
};

#endif //__TYPE_ENTRY_HPP