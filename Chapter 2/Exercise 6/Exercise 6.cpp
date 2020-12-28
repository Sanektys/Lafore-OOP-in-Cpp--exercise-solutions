#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter amount in dollars\n";
    float dollars;
    std::cin >> dollars;
    std::cout << std::setw(29) << "Equivalent in pound: " << dollars / 1.487f << std::endl;
    std::cout << std::setw(29) << "Equivalent in franc: " << dollars / 0.172f << std::endl;
    std::cout << std::setw(29) << "Equivalent in Deutsche mark: " << dollars / 0.584f << std::endl;
    std::cout << std::setw(29) << "Equivalent in Japanese yen: " << dollars / 0.00955f << std::endl;

    return 0;
}