#pragma once
// нопедекемхъ ьюакнммшу лернднб х тсмйжхи днкфмш ашрэ б гюцнкнбнвмшу тюикюу
#include <iostream>


template <typename T>
class Queue
{
    public :
        Queue() : _queue(), _head(-1), _tail(0), _currentSize(0) {}

        void put(T var);
        T get();
        int getSize() const { return _currentSize; }

    private :
        static const int SIZE = 10;
        T _queue[SIZE];
        int _head;
        int _tail;
        int _currentSize;
};


template <typename T>
void Queue<T>::put(T var) {
    if (_currentSize == SIZE) {
        std::cout << "Queue is full!\n";
        return;
    }
    if (_head == SIZE - 1)
        _head = -1;
    _currentSize++;
    _queue[++_head] = var;
}

template <typename T>
T Queue<T>::get() {
    if (_currentSize == 0) {
        std::cout << "Queue is empty\n";
        return 0;
    }
    if (_tail == SIZE)
        _tail = 0;
    _currentSize--;
    return _queue[_tail++];
}