#include <iostream>

int main() {
    char option;
    do {
        std::cout << "Enter 1 to conver the Celsius scale to the Fahrenheit scale\n"
                     "or 2 to convert the Fahrenheit scale to the Celsius scale: ";
        std::cin >> option;
    } while (option != '1' && option != '2');

    float temperature;
    if (option == '1') {
        std::cout << "Enter temperature in Fahrenheit: ";
        std::cin >> temperature;

        temperature = (temperature - 32.0f) * (5.0f / 9.0f);
        std::cout << "Value in Celsius: " << temperature;
    }
    else if (option == '2') {
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> temperature;

        temperature = temperature * (9.0f / 5.0f) + 32.0f;
        std::cout << "Value in Fahrenheit: " << temperature;
    }

    return 0;
}