#include <iostream>


template <typename T>
void swap(T&, T&);

int main() {
    char charOne = 'A';
    char charTwo = 'B';
    std::cout << charOne << "<->" << charTwo << std::endl;
    swap(charOne, charTwo);
    std::cout << charOne << ">-<" << charTwo << std::endl;
    std::cout << std::endl;

    int intOne = 228;
    int intTwo = 115;
    std::cout << intOne << "<->" << intTwo << std::endl;
    swap(intOne, intTwo);
    std::cout << intOne << ">-<" << intTwo << std::endl;
    std::cout << std::endl;

    float floatOne = 3.1415f;
    float floatTwo = 2.74f;
    std::cout << floatOne << "<->" << floatTwo << std::endl;
    swap(floatOne, floatTwo);
    std::cout << floatOne << ">-<" << floatTwo << std::endl;


    return 0;
}

template <typename T>
inline void swap(T& one, T& two) {
    T buffer = one;
    one = two;
    two = buffer;
}