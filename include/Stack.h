#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class T>
class Stack : public List<T>
{
    public:
        Stack() : List() {}
        ~Stack() : ~List() {}
        void Push(T item);
        T Pop();
};

#endif