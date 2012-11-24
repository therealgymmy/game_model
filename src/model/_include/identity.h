#ifndef IDENTITY_H
#define IDENTITY_H

// Dependencies
#include <stdint.h>

//---Macros---

#define NULL_ID 0



//---Types---

typedef uint32_t Identity;

typedef struct idstore_t {
    uint32_t capacity_;
    uint32_t size_;
    Identity curId_;
    Identity *idList_;
} IdStack;



//---Prototypes

IdStack* newIdStack ();
void     delIdStack (IdStack *stack);
Identity newId      (IdStack *stack);



#endif//IDENTITY_H
