#include <iostream>
#include <conio.h>

int main() {
    std::cout << "Enter a number consisting of six figure: ";
    
    int number = 0;
    for (int i = 1; i <= 6; i++)
        number = number * 10 + (_getche() - '0');

    std::cout << "\nYou're entered " << number << std::endl;

    return 0;
}