#include <iostream>
#include <Verylong.h>

typedef vlong::Verylong vylong;

int main() {
    vylong firstNumber;
    vylong secondNumber;
    char answer;

    do {
        std::cout << "Enter first number: ";
        firstNumber.setvl();
        std::cout << "Enter second number: ";
        secondNumber.setvl();

        vylong result;
        std::cout << "\nSum of entered numbers = ";
        result = firstNumber + secondNumber;
        result.getvl();

        std::cout << "\nDifference of entered numbers = ";
        result = firstNumber - secondNumber;
        result.getvl();

        std::cout << "\nMultiplication of entered numbers = ";
        result = firstNumber * secondNumber;
        result.getvl();

        std::cout << "\nDivision of entered numbers = ";
        result = firstNumber / secondNumber;
        result.getvl();

        std::cout << std::endl << std::endl;
        while (true) {
            std::cout << "Want to enter another numbers(y/n)? ";
            std::cin >> answer;
            if (answer != 'n' && answer != 'y')
                std::cin.clear(std::ios::failbit);
            if (!std::cin.good()) {
                std::cin.ignore(1000, '\n');
                std::cin.clear();
                continue;
            }
            else {
                std::cin.ignore(1000, '\n');
                break;
            }
        }
        std::cout << std::endl;
    } while (answer != 'n');


    return 0;
}