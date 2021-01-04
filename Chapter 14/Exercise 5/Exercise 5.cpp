#include <iostream>


template <typename T>
T amax(const T[], int);

int main() {
    int intArray[10] = { 8, 2, 29, 23, 22, 16, 10, 9, 6, 1 };
    std::cout << amax(intArray, 10) << std::endl;

    float floatArray[6] = { 16.22f, 18.2f, 9.20f, 17.0f, 5.86f, 10.10f };
    std::cout << amax(floatArray, 6) << std::endl;

    double doubleArray[5] = { 14.17, 18.20, 16.45, 12.80, 15.5 };
    std::cout << amax(doubleArray, 5) << std::endl;


    return 0;
}

template <typename T>
T amax(const T array[], int size) {
    T max = 0;
    for (int i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}