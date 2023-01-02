#ifndef __SYMBOL_ENTRY_HPP__
#define __SYMBOL_ENTRY_HPP__

#include <string>

class SymbolEntry {
    
    std :: string _name { };
    std :: string _type { };
    
public:
    SymbolEntry () = delete;
    SymbolEntry ( SymbolEntry const & entry ) = delete;
    SymbolEntry ( SymbolEntry && entry ) = delete;

    SymbolEntry (
        std :: string && pname,
        std :: string && ptype
    ) :
        _name ( std :: move ( pname ) ),
        _type ( std :: move ( ptype ) ) {

        }


    constexpr auto getName () const -> std :: string const & { 
        return this->_name;
    }


    constexpr auto getType () const -> std :: string const & {
        return this->_type;
    }
};

#endif //__SYMBOL_ENTRY_HPP__