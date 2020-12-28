#include <iostream>

int main() {
    float cubicFootInGallons = 7.481f;
    std::cout << "Enter number of gallons\n";
    short gallons;
    std::cin >> gallons;
    float cubicFoots = static_cast<float>(gallons) / cubicFootInGallons;
    std::cout << "This is the " << cubicFoots << " in cubic foots";

    return 0;
}