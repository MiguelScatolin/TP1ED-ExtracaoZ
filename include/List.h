#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <class T>
class List
{
    public:
        List();
        ~List();
        void InsertHead(T newItem);
        void InsertTail(T newItem);
        T RemoveHead();
        T RemoveTail();

    private:
        Node<T> *first;
        Node<T> *last;
        int size;
};

#endif