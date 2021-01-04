#include <iostream>
//#include <algorithm>
#include <numeric>
#include <list>

#include "Airtime.h"


int main() {
    char answer = 'n';
    Airtime temp;
    Airtime sum;
    std::list<Airtime> airList;

    do {
        temp.set();
        airList.push_back(temp);

        do {
            std::cout << "Continue(y/n)? ";
            std::cin >> answer;
            if (answer != 'y' && answer != 'n')
                std::cin.clear(std::ios::failbit);
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        } while (true);
    } while (answer != 'n');

    sum = std::accumulate(airList.begin(), airList.end(), Airtime(0, 0));

    std::cout << "\nSum = ";
    sum.display();
    std::cout << std::endl;
    

    return 0;
}
