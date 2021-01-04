#include <iostream>
#include <algorithm>

int main() {
    const int SIZE = 8;
    float array[SIZE] = {};

    std::cout << "Enter eight float elements on the array:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> array[i];
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try again: ";
            i--;
            continue;
        }
        else
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < SIZE; ++i)
        std::cout << array[i] << ' ';

    std::sort(array, array + SIZE);
    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
        std::cout << *(array + i) << ' ';

    
    return 0;
}