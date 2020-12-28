#include <iostream>
#include <conio.h>

int main() {
    do {
        std::cout << "\nSelect the required operation for monetary amounts(+/-/*): ";
        
        switch (_getche()) {
            case '+' : {
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
                break;
            }
            case '-' : {
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
                if (firstPenny - secondPenny < 0) {
                    firstShilling--;
                    totalPenny = firstPenny - secondPenny + 12;
                }
                else
                    totalPenny = firstPenny - secondPenny;
                if (firstShilling - secondShilling < 0) {
                    firstFeet--;
                    totalShilling = firstShilling - secondShilling + 20;
                }
                else
                    totalShilling = firstShilling - secondShilling;
                totalFeet = firstFeet - secondFeet;

                std::cout << "Total " << totalFeet << ' ' << totalShilling << ' ' << totalPenny << std::endl;
                break;
            }
            case '*': {
                std::cout << "\nEnter the sum of money: ";
                float feet;
                short shilling;
                float penny;
                std::cin >> feet >> shilling >> penny;

                std::cout << "Enter multiplier: ";
                float multiplier;
                std::cin >> multiplier;

                float coefficient = 100.0f / (12.0f * 20.0f);
                penny += shilling * 12;
                penny *= coefficient;

                if (penny >= 100) {
                    feet++;
                    penny -= 100;
                }
                penny /= 100.0f;
                feet += penny;
                feet *= multiplier;

                penny = (feet - (int)feet) * 100;
                feet = (int)feet;
                coefficient = 240.0f / 100.0f;
                penny *= coefficient;
                shilling = ((int)penny - ((int)penny % 12) / 12);
                penny = (int)penny % 12;
                while (shilling >= 20) {
                    shilling -= 20;
                    feet++;
                }

                std::cout << "Total: " << feet << ' ' << shilling << ' ' << penny << std::endl;
                break;
            }
            default :
                std::cout << "Entered incorrect operation!" << std::endl;
        }
        std::cout << "Continue(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}