#include <iostream>

const int SIZE = 10;

void addArrays(float*, float*, float*, int);

int main() {
    float arrayOne[SIZE] = { 1.2, 3.4, 18.8, 33.1, 81, 9.9, 8.2, 1.1, 2.5, 5.6 };
    float arrayTwo[SIZE] = { 1.2, 8.4, 6.5, 14.3, 6.6, 80, 18.4, 11.11, 2.8, 7.5 };
    float arrayThree[SIZE] = {};

    addArrays(arrayOne, arrayTwo, arrayThree, SIZE);

    for (int i = 0; i < SIZE; i++)
        std::cout << *(arrayThree + i) << "; ";
    std::cout << std::endl;

    return 0;
}

void addArrays(float* firstArray, float* secondArray,
               float* targetArray, int size) {
    for (int i = 0; i < size; i++)
        *(targetArray + i) = *(firstArray + i) + *(secondArray + i);
}