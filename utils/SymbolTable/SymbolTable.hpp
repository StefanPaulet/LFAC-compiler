#ifndef __SYMBOL_TABLE_HPP__
#define __SYMBOL_TABLE_HPP__

#include "VariableEntry/VariableEntry.hpp"
#include "FunctionEntry/FunctionEntry.hpp"


class SymbolTable {
    
public:
    using SymbolList = std :: list < SymbolEntry * >;

private:
    SymbolList * _pSymbolList = new SymbolList;

public:
    SymbolTable () = default;


    auto addSymbol (
        SymbolEntry * pNewSymbol 
    ) -> void {
        
        this->_pSymbolList->push_back ( pNewSymbol );
    }


    auto lookUpSymbol ( 
        char const * pSymbolName
    ) -> SymbolEntry * {
        
        for ( auto e : * this->_pSymbolList ) {
            if ( ! strcmp ( e->getName(), pSymbolName ) ) {
                return e;
            }
        }

        return nullptr;
    }


};

#endif //__SYMBOL_TABLE_HPP__