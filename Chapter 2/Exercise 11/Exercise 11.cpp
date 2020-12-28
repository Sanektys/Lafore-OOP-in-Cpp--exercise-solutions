#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "Second name" << std::setw(12) << "Name"
        << std::setw(20) << "Adress" << std::setw(18) << "City" << std::endl;
    std::cout << std::setfill('-') << std::setw(66) << '-' << std::setfill(' ') << std::endl;
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "Shesterov" << std::setw(12) << "Ilya"
        << std::setw(20) << "Bering 4/1" << std::setw(18) << "Tomsk" << std::endl;
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "Petrofanov" << std::setw(12) << "Andrei"
        << std::setw(20) << "Berdskaya 8" << std::setw(18) << "Habarovsk" << std::endl;
    std::cout << std::setiosflags(std::ios::left) << std::setw(16) << "Shelyponchikov" << std::setw(12) << "Kavai"
        << std::setw(20) << "Wide street 11" << std::setw(18) << "Bubltown" << std::endl;

    return 0;
}