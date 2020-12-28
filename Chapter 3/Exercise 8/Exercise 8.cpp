#include <iostream>
#include <conio.h>

int main() {
    do {
        std::cout << "\nEnter the first sum of money: ";
        short firstFeet;
        short firstShilling;
        short firstPenny;
        std::cin >> firstFeet >> firstShilling >> firstPenny;

        std::cout << "Enter the second sum of money: ";
        short secondFeet;
        short secondShilling;
        short secondPenny;
        std::cin >> secondFeet >> secondShilling >> secondPenny;

        short totalFeet;
        short totalShilling;
        short totalPenny;
        if (firstPenny + secondPenny > 11) {
            secondShilling++;
            totalPenny = firstPenny + secondPenny - 12;
        }
        else
            totalPenny = firstPenny + secondPenny;
        if (firstShilling + secondShilling > 19) {
            secondFeet++;
            totalShilling = firstShilling + secondShilling - 20;
        }
        else
            totalShilling = firstShilling + secondShilling;
        totalFeet = firstFeet + secondFeet;

        std::cout << "Total " << totalFeet << ' ' << totalShilling << ' ' << totalPenny << std::endl;
        std::cout << "Continue(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}