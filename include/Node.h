#ifndef NODE_H
#define NODE_H

#include "List.h"

template <class T>
class Node
{
    public:
        Node();
        Node(T item) : item(item) {}

    private:
        T item;
        Node *next;

    friend class List;
};

#endif