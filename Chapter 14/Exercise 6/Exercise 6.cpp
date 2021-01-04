#include <iostream>
#include <ctime>

#include "Array.hpp"



int main() {
    srand((unsigned int)time(0));
    const int SIZE = 10;

    Array<int> arrayInt(SIZE);
    for (int i = 0; i < SIZE; i++)
        arrayInt[i] = rand() % 1000;
    arrayInt.display();

    Array<float> arrayFloat(SIZE);
    for (int i = 0; i < SIZE; i++)
        arrayFloat[i] = (rand() % 100) / (float)(1 + (rand() % 100));
    arrayFloat.display();
    
    Array<double> arrayDouble(SIZE);
    for (int i = 0; i < SIZE; i++)
        arrayDouble[i] = (rand() % 100) / ((double)1 + (rand() % 100));
    arrayDouble.display();

    Array<char> arrayChar(SIZE);
    for (int i = 0; i < SIZE; i++)
        arrayChar[i] = rand() % 256;
    arrayChar.display();


    return 0;
}