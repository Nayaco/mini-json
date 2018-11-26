//
// to.js-toException
//

///'TO' ties a function to try...catch...
///Return with 2 params (err, value)
/// If no error occurs err should be 0x00
#ifndef TO_HPP
#define TO_HPP

#include <functional>
#include <cstdint>
#include <tuple>
#include <exception>
#include "errorcode.hpp"

template<typename RV, typename ...T>
std::tuple<ERRCODE, RV> to(std::function<RV(ERRCODE&, T ...args)> func, T ...args){
    try{    
        ERRCODE err = SUCCESS;
        RV value = func(err, args...);
        return std::make_tuple(err, value);
    }catch(const std::exception &e){
        throw e;
    }
}

#endif