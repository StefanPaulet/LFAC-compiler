#ifndef __SYMBOL_TABLE_IMPL_HPP__
#define __SYMBOL_TABLE_IMPL_HPP__

auto SymbolTable :: addSymbol (
        SymbolEntry * pNewSymbol 
) -> void {
    
    this->_pSymbolList->push_back ( pNewSymbol );
}


auto SymbolTable :: lookUpSymbol ( 
        char const * pSymbolName
) -> SymbolEntry * {
    
    for ( auto e : * this->_pSymbolList ) {
        if ( ! strcmp ( e->getName(), pSymbolName ) ) {
            return e;
        }
    }

    return nullptr;
}


auto SymbolTable :: getSymbols () -> SymbolList const * {

    return this->_pSymbolList;
}

#endif //__SYMBOL_TABLE_IMPL_HPP__