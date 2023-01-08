#ifndef __SYMBOL_ENTRY_HPP__
#define __SYMBOL_ENTRY_HPP__

#include <string.h>
#include <string>
#include "../../TypeTable/TypeEntry/TypeEntry.hpp"

class SymbolEntry {
    
protected:
    char const * _pName { nullptr };
    
public:
    SymbolEntry () = delete;
    SymbolEntry ( SymbolEntry const & entry ) = delete;
    SymbolEntry ( SymbolEntry && entry ) = delete;

    SymbolEntry (
        char const * pName
    ) :
        _pName ( strdup ( pName ) ) {

        }

    ~SymbolEntry () {

        delete this->_pName;
    }


    auto constexpr getName () const -> char const * const { 

        return this->_pName;
    }


    virtual auto getTypeName () const -> std :: string = 0;


    virtual auto getType () const -> TypeEntry * = 0;
    
};

#endif //__SYMBOL_ENTRY_HPP__