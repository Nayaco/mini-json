//
// kvcast - json-KVcast
//

#include "kvcast.hpp"
#include "toEx/to.hpp"
#include <cstring>
#include <typeinfo>
#include <typeindex>
#include <any>
KV::KV():bodySize(0){}

KV::KV(const KV& _kv):bodySize(_kv.bodySize), bodyCast(_kv.bodyCast)
{
    memcpy(body, _kv.body, L_LEN * sizeof(castptr));
}

auto KV::typeMatch(const kvcast& kv1, const kvcast& kv2)->bool
{
    return kv1.type == kv2.type;
}

auto KV::getattr(const std::string& key)->kvcast&
{
    return *bodyCast[key];
}

auto KV::getattr_s(const std::string& key)->const kvcast&
{
    castptr kv0 = (castptr)malloc(sizeof(kvcast));
    castptr kv1 = bodyCast[key];
    memcpy(kv0, kv1, sizeof(kvcast));
    kv0->body = malloc(kv0->size);
    memcpy(kv0->body, kv1, kv0->size);
    return *kv0;
}

auto KV::setattr(std::string key, std::any value, std::type_info type)->bool
{
    
    if(bodyCast.find(key) == bodyCast.end()){
        body[bodySize++] = new kvcast;
        bodyCast[key] = body[bodySize - 1];
        
        
    }
} 

