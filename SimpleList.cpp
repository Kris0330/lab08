#include "SimpleList.h"
#include <stdexcept> // 為了使用例外處理

template <class T>
SimpleList<T>::SimpleList() {
    numElements = 0;
    elements = new T[CAPACITY]; // 配置記憶體
}

template <class T>
SimpleList<T>::~SimpleList() {
    delete[] elements; // 釋放記憶體
}

template <class T>
T SimpleList<T>::at(int index) const {
    if (index < 0 || index >= numElements) {
        throw std::out_of_range("InvalidIndexException");
    }
    return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const {
    return numElements == 0;
}

template <class T>
T SimpleList<T>::first() const {
    if (empty()) {
        throw std::runtime_error("EmptyListException");
    }
    return elements[0];
}

template <class T>
T SimpleList<T>::last() const {
    if (empty()) {
        throw std::runtime_error("EmptyListException");
    }
    return elements[numElements - 1];
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) {
    if (numElements == CAPACITY) {
        throw std::overflow_error("FullListException");
    }
    elements[numElements++] = item;
}

template <class T>
void SimpleList<T>::remove(int index) {
    if (empty()) {
        throw std::runtime_error("EmptyListException");
    }
    if (index < 0 || index >= numElements) {
        throw std::out_of_range("InvalidIndexException");
    }
    for (int i = index; i < numElements - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    --numElements;
}
