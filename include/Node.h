#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:
        Node();
        Node(T item) : item(item) {}
        T GetItem() { return item; };
        Node<T>* GetNext() { return next; };

    private:
        T item;
        Node<T> *next;
};

#endif