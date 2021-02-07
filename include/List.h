#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
    public:
        List() {}
        List() : size(0), head(nullptr), tail(nullptr) {}
        int GetSize() { return size; };
        bool IsEmpty() { return size == 0; };

        virtual void Push(T item) = 0;
        virtual T Pop() = 0;

    protected:
        Node<T> *head;
        Node<T> *tail;
        int size;
};

#endif