#pragma once

#include <iostream>


template <typename T>
class Array
{
    public :
        Array(int s) : _size(s) {
            _pointer = new T[s];
        }
        Array(Array& array);

        ~Array() {
            delete[] _pointer;
        }

        class IndexExept 
        {
            public :
                IndexExept() : index(0), message() {}
                IndexExept(const char* mes, int ind) : index(ind) {
                    strcpy_s(message, mes);
                }

            public :
                char message[32];
                int index;
        };

        void display(void) const;

        T& operator[](int i) const;
        Array& operator=(const Array& array);

    private :
        T* _pointer;
        int _size;
};

template <typename T>
T& Array<T>::operator[](int i) const {
    if (i >= 0 && i < _size)
        return *(_pointer + i);
    else if (i < 0)
        throw IndexExept(" index is lower allow range!", i);
    else if (i >= _size)
        throw IndexExept(" index is higher allow range!", i);
}

template <typename T>
Array<T>::Array(Array& array) {
    _size = array._size;
    _pointer = new T[_size];
    
    for (int i = 0; i < _size; i++)
        *(_pointer + i) = *(array._pointer + i);
}

template <typename T>
void Array<T>::display(void) const {
    for (int i = 0; i < _size; i++)
        std::cout << *(_pointer + i) << ' ';
    std::cout << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& array) {
    if (_size >= array._size) {
        for (int i = 0; i < array._size; i++)
            *(_pointer + i) = *(array._pointer + i);
        for (int i = array._size; i < _size; i++)
            *(_pointer + i) = 0;
    }
    else
        for (int i = 0; i < _size; i++)
            *(_pointer + i) = *(array._pointer + i);

    return *this;
}

