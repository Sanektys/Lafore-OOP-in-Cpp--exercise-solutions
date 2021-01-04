#include <iostream>

#include "Fraction.hpp"


template <typename T>
char inputFraction(Fraction<T>&, Fraction<T>&);

template <typename T>
void calculateFraction(Fraction<T>&, Fraction<T>&, Fraction<T>&, char);

int main() {
    char answer[3] = {};
    do {
        std::cout << "Select the type of data in which the fraction will be stored:\n"
                     "Available types - char, short, int. Enter one of them: ";
        std::string type = "";
        do {
            std::cin >> type;
            if (type != "char" && type != "short" && type != "int") {
                std::cin.clear(std::ios::failbit);
                std::cout << "Incorrect type, available - char, short, int. ";
            }
            if (!std::cin.good()) {
                std::cin.clear();
                std::cout << "Try again: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        } while (true);

        if (type == "char") {
            Fraction<char> fractOne;
            Fraction<char> fractTwo;
            Fraction<char> result;
            char op = inputFraction(fractOne, fractTwo);
            calculateFraction(fractOne, fractTwo, result, op);
        }
        else if (type == "short") {
            Fraction<short> fractOne;
            Fraction<short> fractTwo;
            Fraction<short> result;
            char op = inputFraction(fractOne, fractTwo);
            calculateFraction(fractOne, fractTwo, result, op);
        }
        else if (type == "int") {
            Fraction<int> fractOne;
            Fraction<int> fractTwo;
            Fraction<int> result;
            char op = inputFraction(fractOne, fractTwo);
            calculateFraction(fractOne, fractTwo, result, op);
        }

        while (true) {
            std::cout << "Enter another expression(y/n)? ";
            std::cin.get(answer, 3);
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if (_strcmpi(answer, "y") && _strcmpi(answer, "n")) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter ONLY \"y\" or \"n\"\n";
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    } while (strcmp(answer, "n"));

    return 0;
}

template <typename T>
char inputFraction(Fraction<T>& fractOne, Fraction<T>& fractTwo) {
    std::cout << "Enter two fractional operands(in format 99/99) and an operation on them[+,-,*,/]:\n";

    char operation = '?';

    std::cin.unsetf(std::ios::skipws);
    while (true) {
        std::cin >> fractOne >> operation >> fractTwo;
        if (!std::cin.good()) {
            std::cerr << "Incorrect entered expression! Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    std::cin.setf(std::ios::skipws);

    return operation;
}

template <typename T>
void calculateFraction(Fraction<T>& fractOne, Fraction<T>& fractTwo, Fraction<T>& result, char operation) {
    switch (operation) {
        case '+' :
            result = fractOne + fractTwo;
            std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
            break;
        case '-' :
            result = fractOne - fractTwo;
            std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
            break;
        case '*' :
            result = fractOne * fractTwo;
            std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
            break;
        case '/' :               
            result = fractOne / fractTwo;
            std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
            break;
        default :
            std::cout << "Entered incorrect operation!\n";
    }
    std::cout << std::endl;
}