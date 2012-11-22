#include "../_include/identity.h"

// Dependencies
#include <malloc.h>
#include <stdbool.h>

//---Macro---
#define DEFAULT_ID_STACK_SIZE     20
#define DEFAULT_ID_STACK_ID_START 0
#define MAX_ID_STACK_ID_COUNT     (UINT32_MAX / 2)



//---Prototypes---

static bool incIdStack (IdStack *stack);



//---Implementations---

IdStack* newIdStack ()
{
    IdStack* stack = malloc(sizeof(IdStack));

    if (!stack) {
        return NULL;
    }

    Identity *list = malloc(sizeof(Identity) * DEFAULT_ID_STACK_SIZE);

    if (!list) {
        return NULL;
    }

    stack->capacity_ = DEFAULT_ID_STACK_SIZE;
    stack->size_     = 0;
    stack->curId_    = NULL_ID;
    stack->idList_   = list;

    return stack;
}

void delIdStack (IdStack *stack)
{
    free(stack->idList_);
    free(stack);
}

Identity newId (IdStack *stack)
{
    if (stack->curId_ >= MAX_ID_STACK_ID_COUNT) {
        return NULL_ID;
    }

    if (stack->size_ >= stack->capacity_) {
        if (!incIdStack(stack)) {
            return NULL_ID;
        }
    }

    uint32_t size  = ++(stack->size_);
    uint32_t newId = ++(stack->curId_);
    stack->idList_[size - 1] = newId;

    return newId;
}

bool incIdStack (IdStack *stack)
{
    uint32_t newCapacity = stack->capacity_ * 2;
    uint32_t *newList    = realloc(stack->idList_,
                                   sizeof(uint32_t) * newCapacity);

    if (!newList) {
        return false;
    }

    stack->capacity_ = newCapacity;
    stack->idList_   = newList;
    return true;
}
