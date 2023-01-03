#ifndef __TYPE_TABLE_HPP
#define __TYPE_TABLE_HPP

#include "StructuredTypeEntry/StructuredTypeEntry.hpp"

class TypeTable {

public:
    using TypeList = std :: list < TypeEntry const * >;

private:
    TypeList * _pTypes { nullptr };

public:
    TypeTable () {

        this->_pTypes = new TypeList;
    }


    auto addType ( 
        TypeEntry const * pNewType
    ) -> void { 

        this->_pTypes->push_back ( pNewType );
    }


    auto getTypeLength ( 
        char const * pTypeName
    ) -> unsigned short int { 

        for ( auto e : * this->_pTypes ) {
            if ( ! strcmp ( e->getTypeName(), pTypeName ) ) {
                return e->getTypeLength();
            }
        }
        return 0;
    }
};

#endif //__TYPE_TABLE_HPP