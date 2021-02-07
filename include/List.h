#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <class T>
class List
{
    public:
        List();
        ~List();
        int GetSize();
        bool IsEmpty();

    protected:
        Node<T> *head;
        Node<T> *tail;
        int size;

        void InsertAfter(T item);
        void InsertBefore(T item);
        virtual T RemoveFirst();
};

#endif