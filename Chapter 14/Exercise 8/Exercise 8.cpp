#include <iostream>
#include <ctime>

#include "Array.hpp"


int main() {
    srand((unsigned int)time(0));
    const int SIZE = 10;

    Array<int> arrayInt(SIZE);
    for (int i = 0; i < SIZE; i++) {
        try {
            arrayInt[i] = rand() % 1000;
        }
        catch (Array<int>::IndexExept) {
            std::cout << "Index is out of range! ";
        }
    }
    arrayInt.display();

    Array<float> arrayFloat(SIZE);
    for (int i = -1; i < SIZE; i++) {
        try {
            arrayFloat[i] = (rand() % 100) / (float)(1 + (rand() % 100));
        }
        catch (Array<float>::IndexExept) {
            std::cout << "Index is out of range! ";
        }
    }
    arrayFloat.display();

    Array<double> arrayDouble(SIZE);
    for (int i = 0; i < SIZE; i++) {
        try {
            arrayDouble[i] = (rand() % 100) / ((double)1 + (rand() % 100));
        }
        catch (Array<double>::IndexExept) {
            std::cout << "Index is out of range! ";
        }
    }
    arrayDouble.display();

    Array<char> arrayChar(SIZE);
    for (int i = 0; i <= SIZE; i++) {
        try {
            arrayChar[i] = rand() % 256;
        }
        catch (Array<char>::IndexExept) {
            std::cout << "Index is out of range! ";
        }
    }
    arrayChar.display();


    return 0;
}