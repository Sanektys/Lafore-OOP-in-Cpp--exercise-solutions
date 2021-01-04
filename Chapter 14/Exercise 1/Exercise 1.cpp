#include <iostream>


template <typename T>
T average(T array[], int size) {
    T result = 0;
    for (int i = 0; i < size; i++)
        result += array[i];
   
    return result / size;
}

int main() {
    int arrayInt[10] = { 1, 3, 5, 9, 2, 9, 3, 1, 4, 8 };
    std::cout << average(arrayInt, 10) << std::endl;

    float arrayFloat[6] = { 2.34f, 4.99f, 17.4f, 5.14f, 7.22f, 10.10f };
    std::cout << average(arrayFloat, 6) << std::endl;

    double arrayDouble[6] = { 8.42, 9.19, 14.89, 1.00, 13.30, 6.41 };
    std::cout << average(arrayDouble, 6) << std::endl;

    char arrayChar[5] = { '1', '9', '3', '8', '2' };
    std::cout << average(arrayChar, 5) << std::endl;


    return 0;
}