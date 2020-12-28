#include <iostream>

int main() {
    std::cout << "Enter temperature in Celsius: ";
    float celsius;
    std::cin >> celsius;
    std::cout << "\nSame temperature in Fahrenheit - " << celsius * 9 / 5 + 32 << std::endl;
    
    return 0;
}