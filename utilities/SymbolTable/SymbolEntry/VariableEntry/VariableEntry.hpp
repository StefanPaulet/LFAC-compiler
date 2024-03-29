#ifndef __VARIABLE_ENTRY_HPP__
#define __VARIABLE_ENTRY_HPP__

#include "../SymbolEntry.hpp"

class Scope;

class VariableEntry : public SymbolEntry {

public:
    union VarValue {
        bool    boolValue;
        char    charValue;
        float   floatValue;
        int     intValue;
        char const *  stringValue;
        Scope * structValue;

        VariableEntry ** arrayValue;

        VarValue () = default;
        VarValue ( bool val ) : boolValue ( val ) { }
        VarValue ( char val ) : charValue ( val ) { }
        VarValue ( float val ) : floatValue ( val ) { }
        VarValue ( int val ) : intValue ( val ) { }
        VarValue ( char const * pVal ) : stringValue ( strdup ( pVal ) ) { }
        VarValue ( Scope * pVal ) : structValue ( pVal ) { }
        VarValue ( VariableEntry ** pVal ) : arrayValue ( pVal ) { }
    };
    
private:
    TypeEntry * _pType;

    VarValue _val;

    bool _constQualified;

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
    VariableEntry (
        VariableEntry const & var
    );


    ~VariableEntry ();


    auto getTypeName () const -> std :: string;


    constexpr auto getType () const -> TypeEntry * override;


    auto getValue () -> VarValue;


    auto setValue ( 
        VarValue val
    ) -> void;


    constexpr auto getConstQualifier () -> bool;

    auto setConstQualifier (
        bool constQualified
    ) -> void;
};


#endif //__VARIABLE_ENTRY_HPP__