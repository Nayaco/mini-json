#ifndef REFLECT_HPP
#define REFLECT_HPP

#include <functional>
#include <tuple>
#include <map>
#include <string>
#include "toEx/errorcode.hpp"
#include "toEx/to.hpp"

template<class R, class ...T>
class Reflect{
public:
    static   Reflect    &getInstance();
    virtual  auto        regObject(const std::string, std::function<R(ERRCODE&, T...)>) -> bool;
    virtual  auto        getObject(const std::string, T ...args) -> std::tuple<ERRCODE, R>;
protected:
    std::map<std::string, std::function<R(T...)> >  objectPool;
    static   Reflect*    instance;
    Reflect();
};

template<class R, class ...T>
Reflect<R, T...> *Reflect<R, T...>::instance = NULL;

template<class R, class ...T>
Reflect<R, T...>::Reflect():objectPool(){}

template<class R, class ...T>
Reflect<R, T...>& Reflect<R, T...>::getInstance()
{
    if(instance == NULL){
        instance = new Reflect<R, T...>();
    }
    return *instance;
}

template<class R, class ...T>
auto Reflect<R, T...>::regObject(const std::string key, std::function<R(ERRCODE&, T...)> func)->bool
{
    if(objectPool.find(key) != objectPool.end())return false;
        else objectPool[key] = func;
    return true;
}

template<class R, class ...T>
auto Reflect<R, T...>::getObject(const std::string key, T ...args)->std::tuple<ERRCODE, R>
{
    if(objectPool.find(key) == objectPool.end())return std::make_tuple(NFOUND, NULL);
        else return to(objectPool[key], args...);
}

#endif // REFLECT_HPP
