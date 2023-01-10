#ifndef __STRUCTURED_TYPE_ENTRY_HPP__
#define __STRUCTURED_TYPE_ENTRY_HPP__

#include "../TypeEntry.hpp"

class Scope;

class StructuredTypeEntry : public TypeEntry {

public:
    using TypeEntry :: TypeLength;

private:
    Scope * _pTypeScope;

public:
    StructuredTypeEntry (
        char const * pName,
        Scope      * pTypeScope 
    );


    constexpr auto getScope () -> Scope *;
    
};

#include "../impl/TypeEntry.hpp"

#endif //__STRUCTURED_TYPE_ENTRY_HPP__