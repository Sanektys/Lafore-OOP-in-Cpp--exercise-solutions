#include <iostream>
#include <iomanip>

int main() {
    short number;
    do {
        std::cout << "Enter number of the multiplication table: ";
        std::cin >> number;
    } while (number < 1 || number > 9);

    short result = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 10; j++) {
            result += number;
            std::cout << std::setw(5) << result;
        }
        std::cout << std::endl;
    }

    return 0;
}