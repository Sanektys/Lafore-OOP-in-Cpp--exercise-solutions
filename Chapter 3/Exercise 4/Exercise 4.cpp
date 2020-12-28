#include <iostream>
#include <conio.h>

int main() {
    do {
        std::cout << "\nEnter first operand, operation character and second operand: ";
        float firstOp;
        char opChar;
        float secondOp;
        std::cin >> firstOp >> opChar >> secondOp;

        switch (opChar) {
        case '+':
            std::cout << "Result: " << firstOp + secondOp << std::endl;
            break;
        case '-':
            std::cout << "Result: " << firstOp - secondOp << std::endl;
            break;
        case '*':
            std::cout << "Result: " << firstOp * secondOp << std::endl;
            break;
        case '/':
            std::cout << "Result: " << firstOp / secondOp << std::endl;
            break;
        default:
            std::cout << "Entered incorrect operation" << std::endl;
        }

        std::cout << "Try another operation (y/n)? ";
    } while (_getche() != 'n');

    return 0;
}