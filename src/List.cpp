#include "List.h"

template<class T>
List<T>::List() {
    size = 0;
    head = new Node<T>();
}

template<class T>
List<T>::~List() {
    Node<T> *p;
    p = head->next;
    while(p != nullptr){
        head->next = p->next;
        delete p;
        p = head->next;
    }
    size = 0;
    tail = head;
}

template<class T>
int List<T>::GetSize() {
    return size;
}

template<class T>
bool List<T>::IsEmpty() {
    return size ==0;
}

template<class T>
void List<T>::InsertAfter(T item)  {
    Node<T> *newNode(item);

    tail->next = newNode;
    tail = newNode;
    size++;
}

template<class T>
void List<T>::InsertBefore(T item) {
    Node<T> *newNode(item);

    newNode->next = head->next;
    head->next = newNode;

    size++;
    if(newNode->next == nullptr)
        tail = newNode;
}

template<class T>
T List<T>::RemoveFirst() {
    if (IsEmpty())
        throw "Não tem nenhum item!";

    Node<T> *p;
    T poppedItem;

    poppedItem = head->item;
    p = head;
    head = head->prox;
    delete p;
    size--;
    return poppedItem;
}