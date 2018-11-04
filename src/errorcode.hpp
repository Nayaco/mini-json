//
// Created by nyancochan on 18-11-2.
//

#ifndef PRO1_ERRORCODE_HPP
#define PRO1_ERRORCODE_HPP
#include <cstdint>
typedef int8_t ERRCODE;

#define     SUCCESS             0x00
#define     MOE                 0x01
#define     SOE                 0x02
#define     NFOUND              0x03
#define     TYPEERR             0x04
#define     NPERM               0x05
#define     UNKNOWERR           0xff

typedef struct{
    ERRCODE     err_code;
    int8_t      err_message[1000];
} __BASICERROR__;


#endif //PRO1_ERRORCODE_HPP
