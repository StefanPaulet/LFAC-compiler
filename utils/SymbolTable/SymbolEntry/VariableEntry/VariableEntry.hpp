#ifndef __VARIABLE_ENTRY_HPP__
#define __VARIABLE_ENTRY_HPP__

#include "../SymbolEntry.hpp"

class VariableEntry : public SymbolEntry {
    
private:
    char const * _pType;

    void * _pVal;

public:
    VariableEntry ( 
        char const *        pName,
        char const *        pType,
        unsigned short int  typeLength
    ) : 
        SymbolEntry ( pName ),
        _pType      ( pType ) {

            this->_pVal = ( void * ) malloc ( typeLength );
        }

    ~VariableEntry () {

        delete ( this->_pType );
        free ( this->_pVal );
    }

    auto getType () const -> std :: string { 
        return std :: string ( this->_pType );
    }
};

#endif //__VARIABLE_ENTRY_HPP__