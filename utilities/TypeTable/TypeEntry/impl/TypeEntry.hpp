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
) -> int {

    auto pCopy1 = strdup ( pArraytype->first );
    auto pCopy2 = strdup ( this->_pName );
    
    int subscripts1[16];
    int subscriptsCount1 = 0;
    int subscripts2[16];
    int subscriptsCount2 = 0;

    auto pAux = strtok ( pCopy1, "_" );
    while ( pAux != nullptr ) {
        subscripts1 [ subscriptsCount1 ++ ] = atoi ( pAux + 1 );
        pAux = strtok ( NULL, "_" );
    }

    pAux = strtok ( pCopy2, "_" );
    while ( pAux != nullptr ) {
        if ( *pAux != 'A' ) {
            break;
        }
        subscripts2 [ subscriptsCount2 ++ ] = atoi ( pAux + 1 );
        pAux = strtok ( NULL, "_" );
    }

    if ( subscriptsCount1 < subscriptsCount2 ) {
        error :: arrayPointerAccess();
        return 0;
    }

    if ( subscriptsCount1 > subscriptsCount2 ) {
        error :: invalidSubscriptAccess();
        return 0;
    }

    int returnValue;
    for ( int i = 0; i < subscriptsCount1 - 1; ++ i ) {
        returnValue = ( returnValue + subscripts1 [ i ] ) *  subscripts2 [ i + 1 ];
    }
    return returnValue + subscripts1 [ subscriptsCount1 - 1 ];
}

#endif //__TYPE_ENTRY_IMPL_HPP__