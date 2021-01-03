#include <iostream>

class Array
{
    public :
        Array(int s) {
            _size = s;
            _pointer = new int[s];
        }
        Array(Array& array);

        ~Array() {
            delete[] _pointer;
        }

        int& operator[](int i) const;
        Array& operator=(const Array& array);

    private :
        int* _pointer;
        int _size;
};

int& Array::operator[](int i) const {
    if (i >= 0 && i < _size)
        return *(_pointer + i);
}

Array::Array(Array& array) {
    _size = array._size;
    _pointer = new int[_size];
    
    for (int i = 0; i < _size; i++)
        *(_pointer + i) = *(array._pointer + i);
}

Array& Array::operator=(const Array& array) {
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

int main() {
    const int SIZE = 10;
    Array array(SIZE);

    for (int i = 0; i < SIZE; i++)
        array[i] = i * i;

    for (int i = 0; i < SIZE; i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;

    Array arrayTwo = array;
    for (int i = 0; i < SIZE; i++)
        std::cout << arrayTwo[i] << ' ';
    std::cout << std::endl;
    
    Array arrayThree(6);
    arrayThree = arrayTwo;
    for (int i = 0; i < 6; i++)
        std::cout << arrayThree[i] << ' ';
    std::cout << std::endl;

    Array arrayFour(16);
    arrayFour = arrayTwo;
    for (int i = 0; i < 16; i++)
        std::cout << arrayFour[i] << ' ';
    std::cout << std::endl;

    return 0;
}