#include <iostream>
#include <conio.h>

int main() {
    do {
        std::cout << "\nEnter quantity of guests: ";
        short guests;
        std::cin >> guests;
        std::cout << "Enter quantity of seats: ";
        short seats;
        std::cin >> seats;

        if (seats > guests) {
            std::cout << "There are no problems with placement\n"
                      << "Try another case(y/n)? ";
            if (_getch() == 'n')
                break;
            else
                continue;
        }

        int variants = 1;
        for (int i = guests; i > guests - seats; i--)
            variants *= i;

        std::cout << "Total variations of placement - " << variants << std::endl;
        std::cout << "Try another case(y/n)? ";
            if (_getch() == 'n')
                break;
    } while (true);

    return 0;
}