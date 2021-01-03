#include <iostream>

int main() {
    int array1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int array2[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    int array3[10] = { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 };
    int array4[10] = { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 };
    int array5[10] = { 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 };
    int array6[10] = { 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };
    int array7[10] = { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 };
    int array8[10] = { 70, 71, 72, 73, 74, 75, 76, 77, 78, 79 };
    int array9[10] = { 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 };
    int array10[10] = { 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };

    int* arrayPointers[10] = { array1, array2, array3, array4, array5,
                               array6, array7, array8, array9, array10 };

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << *(*(arrayPointers + i) + j) << " ";
        std::cout << std::endl;
    }

    return 0;
}