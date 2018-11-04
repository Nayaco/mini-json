//
// to.js-to.cpp
//
#ifndef TO_CPP
#define TO_CPP

#include <functional>
#include <cstdint>
#include <tuple>
#include <exception>
#include "errorcode.hpp"

template<typename RV, typename ...T>
std::tuple<ERRCODE, RV> to(std::function<RV(T ...args)> func, T ...args){
    try{    
        RV value = func(args...);
        return std::make_tuple(SUCCESS, value);
    }catch(const std::exception &e){
        return std::make_tuple(UNKNOWERR, NULL);
    }
}

#endif