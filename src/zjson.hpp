#ifndef ZJSON
#define ZJSON

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include "to.cpp"
#define K_LEN   8
#define V_LEN   1024
#define J_LEN   1024

template<class T>
typedef struct{
    uint8_t     klen;
    uint8_t     key[K_LEN];
    T           *value;
}   KV;

typedef struct{
    uint8_t     type;
    KV          *value;
}   KVPtr;

class JSON{
    private:
        int64_t         getHash(const uint8_t[]);
        void            selfCopy(const JSON&);
        const KVPtr&    which();
    protected:
        uint32_t                    N;
        std::map<int64_t, KVPtr>    map_table;
        KVPtr                       body[J_LEN];
    public:
        JSON();
        JSON(uint32_t, KV**);
        JSON(const JSON&);
        ~JSON();
        KV& operator [](const JSON&, const uint32_t);
        KV& operator [](const JSON&, const uint8_t[]);
        const KV& operator =(const JSON&);
};

#endif