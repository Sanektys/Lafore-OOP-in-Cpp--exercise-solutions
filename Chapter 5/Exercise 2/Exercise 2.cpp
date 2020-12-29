#include <iostream>

double power(double n, int p = 2);

int main() {
    std::cout << "Enter the number and the required number degree: ";
    double number;
    int degree;
    std::cin >> number >> degree;
    
    std::cout << "Number in the second power: " << power(number) << std::endl;
    std::cout << number << " in " << degree << " power is "
              << power(number, degree) << std::endl;

    return 0;
}

double power(double n, int p) {
    if (p > 1)
        return n * power(n, --p);
    else
        return n;
}