#include "nfs.hpp"

statSet& lsh()
{
    statSetPtr set  = (statSetPtr)malloc(sizeof(statSet));
    set->list       = (statPtr)malloc(sizeof(L_LEN));
    set->len        = 1;
    return  *set;
}

void expand(statSet& set)
{
    statSetPtr setliter = &set;
    while(setliter->next != NULL){
        setliter = setliter->next;
    }
}
void push(statSet& set, Nstat &stat)
{
    if(set.len == L_LEN){
        
    }
}
