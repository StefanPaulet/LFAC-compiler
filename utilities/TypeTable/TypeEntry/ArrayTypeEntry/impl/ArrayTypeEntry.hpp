#ifndef __ARRAY_TYPE_ENTRY_IMPL_HPP__
#define __ARRAY_TYPE_ENTRY_IMPL_HPP__

ArrayTypeEntry :: ArrayTypeEntry (
    char const * pName,
    TypeLength   length,
    TypeEntry  * pBaseType
) : 
    TypeEntry   ( pName, length ),
    _pBaseType  ( pBaseType ) {
        
    }

#endif //__ARRAY_TYPE_ENTRY_IMPL_HPP__