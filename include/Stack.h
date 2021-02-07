#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename T>
class Stack : public List<T>
{
    public:
        Stack() : List() {}
        void Push(T item);
        T Pop();
};

#endif