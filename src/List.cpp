#include "List.h"

template <class T>
List<T>::List() {
    size = 0;
    head = new Node<T>();
}

template <class T>
List<T>::~List() {
    Node *p;
    p = head->next;
    while(p!=NULL){
        head->next = p->next;
        delete p;
        p = head->next;
    }
    size = 0;
    tail = head;
}

template <class T>
int List<T>::GetSize() {
    return size;
}

template <class T>
bool List<T>::IsEmpty() {
    return size ==0;
}

template <class T>
void List<T>::InsertAfter(T item)  {
    Node<T> *newNode(item);

    tail->next = newNode;
    tail = newNode;
    tamanho++;
}

template <class T>
void List<T>::InsertBefore(T item) {
    Node<T> *newNode(item);

    newNode->next = head->next;
    head->next = newNode;

    tamanho++;
    if(newNode->next == NULL)
        tail = newNode;
}

template <class T>
T List<T>::RemoveFirst() {
    if (IsEmpty())
        throw "Não tem nenhum item!";

    Node *p;
    T poppedItem;

    poppedItem = head->item;
    p = head;
    head = head->prox;
    delete p;
    tamanho--;
    return poppedItem;
}