//
// to.js-to.cpp
//

/** 
 * Tie a function to try...catch...
 * Return with 2 params (err, value)
 * If no error occurs err should be 0x00
 */
#ifndef TO_HPP
#define TO_HPP

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