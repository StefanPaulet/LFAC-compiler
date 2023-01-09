#ifndef __FUNCTION_ENTRY_IMPL_HPP__
#define __FUNCTION_ENTRY_IMPL_HPP__

#include "../../../../ErrorReporting/ErrorReporting.hpp"

FunctionEntry :: FunctionEntry ( 
        char const              * pname,
        TypeEntry               * pReturnType,
        TreeNodeIdentifier      * pFunctionBody,
        ParameterList           * pParameterList,
        Scope                   * pScope
) : 
    SymbolEntry    ( pname ),
    _pReturnType   ( pReturnType ),
    _pFunctionBody ( pFunctionBody ),
    _pScope        ( pScope ) {

    this->_pParameterList = new ParameterList;
    for ( auto e : * pParameterList ) {
        this->_pParameterList->push_back ( e );
    }
}


FunctionEntry :: ~FunctionEntry () {

    delete this->_pFunctionBody;
    while ( ! _pParameterList->empty() ) {
        delete _pParameterList->front();
        _pParameterList->pop_front();
    }
}


auto FunctionEntry :: getTypeName () const -> std :: string {

    std :: string s ( this->_pReturnType->getName() );
    s += '(';
    for ( auto e = this->_pParameterList->begin(); e != this->_pParameterList->end(); ++ e ) {
        s += (*e)->first->getName();
        s += ",";
    }
    if ( ! this->_pParameterList->empty() ) {
        s.pop_back();
    }
    s += ")";
    return s;
}


constexpr auto FunctionEntry :: getType () const -> TypeEntry * {

    return this->_pReturnType;
}


auto FunctionEntry :: matchParameterList (
    std :: list < SymbolEntry * > * pParameterList
) -> bool {

    if ( pParameterList->size() != this->_pParameterList->size() ) {
        error :: mismatchedParameterCount ( pParameterList->size(), this->_pParameterList->size() );
        return false;
    }


    auto e1 = pParameterList->begin();
    auto e2 = this->_pParameterList->begin();
    unsigned short int parameterCount = 1;
    for ( ; e1 != pParameterList->end(); ++ e1, ++ e2, ++ parameterCount ) {
        if ( (*e1)->getType() == nullptr ) {
            error :: undeclaredSymbol ( (*e1)->getName() );
            return false;
        }
        if ( ! strcmp ( (*e2)->first->getName(), "nonExistentType" ) ) {
            continue;
        }
        if ( (*e1)->getType() != (*e2)->first ) {
            error :: mismatchetParameterType ( parameterCount, (*e2)->first->getName(), (*e1)->getTypeName().c_str() );
            return false;
        }
    }

    return true;
}


constexpr auto FunctionEntry :: getScope () const -> Scope * {
    
    return this->_pScope;
}

#endif //__FUNCTION_ENTRY_IMPL_HPP__