#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template<class T>
class Queue : public List<T>
{
    public:
        Queue() : List<T>() {};
        void EnQueue(T item);
        T DeQueue();
};

template<class T>
void Queue<T>::EnQueue(T item)  {
    this->InsertAfter(item);
}

template<class T>
T Queue<T>::DeQueue() {
    return this->RemoveFirst();
}

#endif