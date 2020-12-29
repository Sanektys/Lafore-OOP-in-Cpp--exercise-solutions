#include <iostream>

void swap(int& valueOne, int& valueTwo);

int main() {
    std::cout << "Enter two number and the program will swap them: ";
    int valueOne;
    int valueTwo;
    std::cin >> valueOne >> valueTwo;

    swap(valueOne, valueTwo);

    std::cout << "Result: " << valueOne << ' ' << valueTwo;

    return 0;
}

void swap(int& valueOne, int& valueTwo) {
    int temp = valueOne;
    valueOne = valueTwo;
    valueTwo = temp;
}