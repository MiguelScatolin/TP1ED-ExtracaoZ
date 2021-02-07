#include "Stack.h"

template<class T>
void Stack<T>::Push(T item)  {
    InsertFirst(item);
}

template<class T>
T Stack<T>::Pop() {
    return this.RemoveFirst();
}