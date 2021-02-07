#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <typename T>
class Queue : List<T>
{
    public:
        Queue();
        void Push(T item);
        T Pop();
        bool IsEmpy();

    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
};

#endif