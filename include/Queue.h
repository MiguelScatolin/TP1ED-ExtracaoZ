#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <class T>
class Queue : public List<T>
{
    public:
        Queue() : List() {}
        ~Queue() : ~List() {}
        void EnQueue(T item);
        T DeQueue();
};

#endif