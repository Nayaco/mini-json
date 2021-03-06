#ifndef ZJSON
#define ZJSON

#include <map>
#include <cstdint>

#define K_LEN       8
#define L_LEN       1024

typedef struct      {
        size_t      type; 
        size_t      size;
        void        *body;
}       kvcast;
typedef kvcast      *castptr;
class   KV{
protected:
    int64_t                             bodySize;
    castptr                             body[L_LEN];
    std::map<std::string, castptr>      bodyCast;
private:
    virtual     auto    typeMatch(const kvcast&, const kvcast&)->bool;
public:
    constexpr KV();
    KV(const KV&);
    ~KV();
    virtual     auto    getattr(const std::string&)->kvcast&;
    virtual     auto    getattr_s(const std::string&)->const kvcast&;
    virtual     auto    setattr(std::string, std::any, std::type_info)->bool;
};

#endif