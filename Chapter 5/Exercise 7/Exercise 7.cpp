#include <iostream>

double power(double n, int p = 2);
char power(char c, int p = 2);
int power(int n, int p = 2);
long power(long n, int p = 2);
float power(float n, int p = 2);

int main() {
    std::cout << "Enter the number and the required number degree: ";
    double number;
    int degree;
    std::cin >> number >> degree;

    std::cout << "Number in the second power: " << power(number) << std::endl;
    std::cout << number << " in " << degree << " power is "
              << power(number, degree) << std::endl;

    std::cout << "...and also:\n";
    
    std::cout << "& in 2 power is "
              << power('&') << std::endl;
    std::cout << "12 in " << degree << " power is "
              << power(12, degree) << std::endl;
    std::cout << "14 in " << degree << " power is "
              << power(14l, degree) << std::endl;
    std::cout << "88.386 in " << degree << " power is "
              << power(88.386f, degree) << std::endl;

    return 0;
}

double power(double n, int p) {
    if (p > 1)
        return n * power(n, --p);
    else
        return n;
}

char power(char c, int p) {
    if (p > 1)
        return c * power(c, --p);
    else
        return c;
}

int power(int n, int p) {
    if (p > 1)
        return n * power(n, --p);
    else
        return n;
}

long power(long n, int p) {
    if (p > 1)
        return n * power(n, --p);
    else
        return n;
}

float power(float n, int p) {
    if (p > 1)
        return n * power(n, --p);
    else
        return n;
}