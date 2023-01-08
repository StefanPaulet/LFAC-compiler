#ifndef __TYPE_ENTRY_IMPL_HPP__
#define __TYPE_ENTRY_IMPL_HPP__

#include "../../../ErrorReporting/ErrorReporting.hpp"

TypeEntry :: TypeEntry ( 
    char const * pName 
) : _pName ( strdup ( pName ) ) {

}

TypeEntry :: TypeEntry ( 
    char const * pName,
    TypeLength   length
) : 
    _pName  ( strdup ( pName ) ),
    _length ( length ) {

    }


constexpr auto TypeEntry :: getName () const -> char const * const {
    
    return this->_pName;
}


constexpr auto TypeEntry :: getLength () const -> TypeLength {

    return this->_length;
}


auto TypeEntry :: setLength (
    TypeLength length
) -> void {

    this->_length = length;
}


auto TypeEntry :: matchArraySubscript (
    ArraytypePair * pArraytype
) -> bool {

    auto pCopy1 = strdup ( pArraytype->first );
    auto pCopy2 = this->_pName;

    auto pAux = strtok ( pCopy1, "_" );
    while ( pAux != nullptr ) {
        pCopy2 = strchr ( pCopy2 + 1, '_' );
        if ( pCopy2 == nullptr ) {
            error :: invalidSubscriptAccess();
            return false;
        }
        pAux = strtok ( nullptr, "_" );
    }
    pCopy2 = strchr ( pCopy2 + 1, '_' );
    if ( pCopy2 != nullptr && *(pCopy2 + 1) == 'A' ) {
        error :: arrayPointerAccess ();
        return false;
    }
    return true;
}

#endif //__TYPE_ENTRY_IMPL_HPP__