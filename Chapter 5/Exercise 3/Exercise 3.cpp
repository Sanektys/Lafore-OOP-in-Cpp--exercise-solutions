#include <iostream>

void zeroSmaller(int& firstNumb, int& secondNumb);

int main() {
    std::cout << "Enter two numbers and program will reset the smaller one: ";
    int firstNumb;
    int secondNumb;
    std::cin >> firstNumb >> secondNumb;

    zeroSmaller(firstNumb, secondNumb);

    std::cout << "Processing result: " << firstNumb << " " << secondNumb << std::endl;

    return 0;
}

void zeroSmaller(int& firstNumb, int& secondNumb) {
    if (firstNumb < secondNumb)
        firstNumb = 0;
    else
        secondNumb = 0;
}