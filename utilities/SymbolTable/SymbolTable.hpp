#ifndef __SYMBOL_TABLE_HPP__
#define __SYMBOL_TABLE_HPP__

#include "SymbolEntry/VariableEntry/VariableEntry.hpp"
#include "SymbolEntry/FunctionEntry/FunctionEntry.hpp"


class SymbolTable {
    
public:
    using SymbolList = std :: list < SymbolEntry * >;

private:
    SymbolList * _pSymbolList = new SymbolList;

public:
    SymbolTable () = default;


    auto addSymbol (
        SymbolEntry * pNewSymbol 
    ) -> void;


    auto lookUpSymbol ( 
        char const * pSymbolName
    ) -> SymbolEntry *;

    auto getSymbols () -> SymbolList const *; 
};

#include "SymbolEntry/VariableEntry/impl/VariableEntry.hpp"
#include "SymbolEntry/FunctionEntry/impl/FunctionEntry.hpp"

#endif //__SYMBOL_TABLE_HPP__