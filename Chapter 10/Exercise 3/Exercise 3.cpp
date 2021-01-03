#include <iostream>

const int DAYS = 7;

void sort(const char**, int);
void order(const char**, const char**);

int main() {
    const char* arrayPointers[DAYS] = { "Monday", "Tuesday",
                                        "Wednesday", "Thurday",
                                        "Friday", "Saturday", "Sunday" };

    for (int i = 0; i < DAYS; i++)
        std::cout << arrayPointers[i] << std::endl;
    std::cout << std::endl;

    sort(arrayPointers, DAYS);

    for (int i = 0; i < DAYS; i++)
        std::cout << *(arrayPointers + i) << std::endl;

    return 0;
}

void sort(const char** array, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            order(array + i, array + j);
}

void order(const char** dayOne, const char** dayTwo) {
    if (**dayOne > **dayTwo) {
        const char* tempPointer = *dayOne;
        *dayOne = *dayTwo;
        *dayTwo = tempPointer;
    }
}