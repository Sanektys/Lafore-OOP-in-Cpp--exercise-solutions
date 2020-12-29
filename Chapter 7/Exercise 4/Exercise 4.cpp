#include <iostream>
#include <conio.h>

int maxint(int[], int);

int main() {
    std::cout << "Enter integers (max 60 numbers) and "
                 "the program will print the largest number "
                 "of entered integers\n";
    const int SIZE = 60;
    int numbers[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Continue(y/n)? ";
        if (_getche() == 'n')
            break;
        std::cout << "\nEnter number " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    int index = maxint(numbers, SIZE);
    std::cout << "\nThe largest number is " << index + 1 << " - "
              << numbers[index] << std::endl;

    return 0;
}

int maxint(int array[], const int SIZE) {
    int largeNumb = array[0];
    int index = 0;
    for (int i = 1; i < SIZE; i++) {
        if (largeNumb < array[i]) {
            largeNumb = array[i];
            index = i;
        }
    }

    return index;
}