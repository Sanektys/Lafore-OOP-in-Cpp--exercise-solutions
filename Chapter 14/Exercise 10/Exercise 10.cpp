#include <iostream>

#include "DistanceOld.h"


int main() {
    DistanceOld distance;
    char answer = '\0';
    do {
        try {
            distance.setDist();
        }
        catch (Exeption& exept) {
            if (exept.message.size() != 0)
                std::cout << exept.message << std::endl;
            std::cout << "Try enter data again\n";
            continue;
        }
        std::cout << "\nDistance = ";
        distance.showDist();
        std::cout << "\nTry again(y/n)? ";
        std::cin >> answer;
        std::cin.ignore(10, '\n');
    } while (answer != 'n');


    return 0;
}