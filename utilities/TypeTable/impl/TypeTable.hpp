#ifndef __TYPE_TABLE_IMPL_HPP__
#define __TYPE_TABLE_IMPL_HPP__

TypeTable :: TypeTable ( 
    TypeList * pInitialTypes
) {

    if ( pInitialTypes != nullptr ) {
        for ( auto e : * pInitialTypes ) {
            this->_pTypes->push_back ( e );
        }
    }
}


auto constexpr TypeTable :: getTypes () -> TypeList * {
        
    return this->_pTypes;
}


auto TypeTable :: addType ( 
    TypeEntry * pNewType
) -> void { 

    this->_pTypes->push_back ( pNewType );
}


auto TypeTable :: getType ( 
    char const * pTypeName
) -> TypeEntry * { 

    for ( auto e : * this->_pTypes ) {
        char const * c = e->getName();
        while ( *c >= '0' && *c <= '9' ) {
            ++ c;
        }
        if ( ! strcmp ( c, pTypeName ) ) {
            return e;
        }
    }
    return nullptr;
}


auto TypeTable :: setTypeLength (
    StructuredTypeEntry * pType,
    TypeLength            length
) -> void {

    pType->setLength ( length );
}

#endif //__TYPE_TABLE_IMPL_HPP__