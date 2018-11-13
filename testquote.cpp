#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <map>
#include <any>
using namespace std;

template<typename T>
struct X{
    T a;
};

class testquote
{
private:
    int k;
public:
    testquote(/* args */);
    ~testquote();
    const int operator [](int N)const{
        return k;
    }
};

testquote::testquote(/* args */)
{
    k = 10;
}

testquote::~testquote()
{
}
typedef struct {
    int x;
    int y;
}ttt;
main(int argc, char const *argv[])
{
    ttt s = {1, 1};
    std::any a = s;
    cout<<std::any_cast<ttt>(a).x<<' '<<std::any_cast<ttt>(a).x<<'\n';
    return 0;
}
