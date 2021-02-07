#include "Queue.h"

template<class T>
void Queue<T>::EnQueue(T item)  {
    InsertFirst(item);
}

template<class T>
T Queue<T>::DeQueue() {
    return this.RemoveFirst();
}