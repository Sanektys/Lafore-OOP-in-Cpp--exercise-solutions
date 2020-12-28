#include <iostream>
#include <conio.h>

int main() {
    do {
        std::cout << "\nEnter two fractional operands and an operation on them:\n";
        short firstNumer;
        short firstDenomi;
        short secondNumer;
        short secondDenomi;
        char operand;
        char operation;
        std::cin >> firstNumer >> operand >> firstDenomi >> operation
                 >> secondNumer >> operand >> secondDenomi;

        short resultNumer;
        short resultDenomi;
        switch (operation) {
            case '+' :
                resultNumer = firstNumer * secondDenomi + secondNumer * firstDenomi;
                resultDenomi = firstDenomi * secondDenomi;
                std::cout << "Result: " << resultNumer << '/' << resultDenomi << std::endl;
                break;
            case '-' :
                resultNumer = firstNumer * secondDenomi - secondNumer * firstDenomi;
                resultDenomi = firstDenomi * secondDenomi;
                std::cout << "Result: " << resultNumer << '/' << resultDenomi << std::endl;
                break;
            case '*' :
                resultNumer = firstNumer * secondNumer;
                resultDenomi = firstDenomi * secondDenomi;
                std::cout << "Result: " << resultNumer << '/' << resultDenomi << std::endl;
                break;
            case '/' :
                resultNumer = firstNumer * secondDenomi;
                resultDenomi = firstDenomi * secondNumer;
                std::cout << "Result: " << resultNumer << '/' << resultDenomi << std::endl;
                break;
            default :
                std::cout << "Entered incorrect operation!\n";
        }

        std::cout << "Try another operation(y/n)? ";
    } while (_getche() != 'n');
    
    return 0;
}