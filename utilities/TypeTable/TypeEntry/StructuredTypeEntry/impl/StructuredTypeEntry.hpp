#ifndef __STRUCTURED_TYPE_ENTRY_IMPL_HPP__
#define __STRUCTURED_TYPE_ENTRY_IMPL_HPP__

StructuredTypeEntry :: StructuredTypeEntry (
    char const * pName,
    Scope      * pTypeScope 
) : 
    TypeEntry   ( pName ),
    _pTypeScope ( pTypeScope ) {

    }


constexpr auto StructuredTypeEntry :: getScope () -> Scope * {

    return this->_pTypeScope;
}

#endif //__STRUCTURED_TYPE_ENTRY_IMPL_HPP__