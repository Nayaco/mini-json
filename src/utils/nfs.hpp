#ifndef NFA_HPP
#define NFA_HPP
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <tuple>
#pragma region 
#define     L_LEN       255

typedef     uint8_t     Stat;
#define     WAIT        0x00
#define     MATCH       0x01
#define     UNMATCH     0x02
#define     SPLIT       0x03
#define     END         0x04

typedef     struct{
            Stat        stat;
            statPtr     out1;
            statPtr     out2;
            uint32_t    lastSSet;
}           Nstat;
typedef     Nstat       *statPtr;

typedef     struct{
            uint32_t    len;
            statPtr     list;
            statSetPtr  next;
}           statSet;
typedef     statSet     *statSetPtr;

statSet&    lsh();
void        expand(     statSet&);
void        push(       statSet&,       
                        Nstat&);
void        merge(      statSet&,
                        statSet&);

typedef     struct{
            statPtr     start;
            statSet     set;
}           frag;

statPtr     post(       char*);
#pragma endregion

class nfs
{
protected:
    /* data */
public:
    nfs(/* args */);
    ~nfs();
};




#endif