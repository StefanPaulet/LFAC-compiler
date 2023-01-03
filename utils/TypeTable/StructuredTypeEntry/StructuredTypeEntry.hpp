#ifndef __STRUCTURED_TYPE_ENTRY_HPP
#define __STRUCTURED_TYPE_ENTRY_HPP

#include "../TypeEntry/TypeEntry.hpp"
#include <utility>
#include <list>

class StructuredTypeEntry : public TypeEntry {

public:
    using StructureField = std :: pair < char const *, StructuredTypeEntry const * >;

    using FieldList = std :: list < StructureField * >;

private:
    FieldList * _pFieldList;

public:
    StructuredTypeEntry (
        char const * pName,
        FieldList  * pFields 
    ) : 
        TypeEntry ( pName ) {

            this->_pFieldList = new FieldList;

            for ( auto e : * pFields ) {
                this->_length += e->second->_length;
                this->_pFieldList->push_back ( e );
            }
        }

};


#endif //__STRUCTURED_TYPE_ENTRY_HPP