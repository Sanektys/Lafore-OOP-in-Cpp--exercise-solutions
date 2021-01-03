#include <iostream>

int main() {
    int* arrayPointers[10] = {};

    for (int i = 0; i < 10; i++)
        *(arrayPointers + i) = new int[10];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            *(*(arrayPointers + i) + j) = i * 10 + j;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << *(*(arrayPointers + i) + j) << " ";
        std::cout << std::endl;
    }

    return 0;
}