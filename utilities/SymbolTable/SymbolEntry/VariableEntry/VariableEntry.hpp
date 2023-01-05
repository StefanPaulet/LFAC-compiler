#ifndef __VARIABLE_ENTRY_HPP__
#define __VARIABLE_ENTRY_HPP__

#include "../SymbolEntry.hpp"
#include "../../../TypeTable/TypeEntry/TypeEntry.hpp"

class Scope;

class VariableEntry : public SymbolEntry {

public:
    union VarValue {
        bool    boolValue;
        char    charValue;
        float   floatValue;
        int     intValue;
        char *  stringValue;
        bool *  pBoolValue;
        float * pFloatValue;
        int *   pIntValue;
        Scope * structValue;

        VarValue () = default;
        VarValue ( bool val ) : boolValue ( val ) { }
        VarValue ( char val ) : charValue ( val ) { }
        VarValue ( float val ) : floatValue ( val ) { }
        VarValue ( int val ) : intValue ( val ) { }
        VarValue ( char * pVal ) : stringValue ( strdup ( pVal ) ) { }
        
    };
    
private:
    TypeEntry * _pType;

    VarValue _val;

public:
    VariableEntry ( 
        char const *    pName,
        TypeEntry  *    pType
    );

    VariableEntry (
        char const *    pName,
        TypeEntry  *    pType,
        VarValue        val
    );

    ~VariableEntry ();

    auto getTypeName () const -> std :: string;

    constexpr auto getType () const -> TypeEntry *;
};

#endif //__VARIABLE_ENTRY_HPP__