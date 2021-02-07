#include "Queue.h"

template <class T>
T Queue<T>::DeQueue() {
    return RemoveFirst();
}
/*
template <class T>
void Queue<T>::EnQueue(T item);
    InsertAfter(item);
} */