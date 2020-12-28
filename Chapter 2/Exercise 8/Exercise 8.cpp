#include <iostream>
#include <iomanip>

int main() {
    int populOne   = 8425785;
    int populTwo   = 47;
    int populThree = 9761;

    std::cout << std::setfill('_')
              << std::setw(9) << "City"      << std::setw(12) << "Population" << std::endl
              << std::setw(9) << "Moscow"    << std::setw(12) << populOne     << std::endl
              << std::setw(9) << "Kirov"     << std::setw(12) << populTwo     << std::endl
              << std::setw(9) << "Ygrumovka" << std::setw(12) << populThree   << std::endl;

    return 0;
}