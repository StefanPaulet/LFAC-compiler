#ifndef __FUNCTION_ENTRY_HPP__
#define __FUNCTION_ENTRY_HPP__

#include "../SymbolEntry.hpp"
#include "../../../AbstractSyntaxTree/TreeNodeIdentifier.hpp"
#include <list>
#include <utility>
#include <stdio.h>

class FunctionEntry : public SymbolEntry {

public:
    using ParameterEntry = std :: pair < char const *, char const * >;
    using ParameterList  = std :: list < ParameterEntry * >;
    
private:
    char const * _pReturnType;

    TreeNodeIdentifier * _pFunctionBody;

    ParameterList * _pParameterList;

public:

    FunctionEntry ( 
        char const              * pname,
        char const              * pReturnType,
        TreeNodeIdentifier      * pFunctionBody,
        ParameterList           * pParameterList
    ) : 
        SymbolEntry    ( pname ),
        _pReturnType   ( pReturnType ),
        _pFunctionBody ( pFunctionBody ) {

            this->_pParameterList = new ParameterList;
            for ( auto e : * pParameterList ) {
                this->_pParameterList->push_back ( e );
            }
        }


    ~FunctionEntry () {

        delete this->_pFunctionBody;
        while ( ! _pParameterList->empty() ) {
            delete _pParameterList->front();
            _pParameterList->pop_front();
        }
    }


    auto getType () const -> std :: string override {

        std :: string s ( this->_pReturnType );
        s += '(';
        for ( auto e = this->_pParameterList->begin(); e != this->_pParameterList->end(); ++ e ) {
            s += (*e)->first;
            if ( e == this->_pParameterList->end() ) {
                s += ")";
            } else {
                s += ", ";
            }
        }
        return s;
    }
};

#endif //__FUNCTION_ENTRY_HPP__