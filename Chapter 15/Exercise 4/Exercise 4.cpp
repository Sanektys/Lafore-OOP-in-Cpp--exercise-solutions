#include <iostream>
#include <set>

#include "Person.h"
#include "ComparePersons.h"


int main() {
    std::multiset<Person*, ComparePersons> personSet;
    std::string answer;

    std::cout << "Enter few persons:\n";
    short count = 0;
    do {
        count++;
        std::cout << "Person " << count << ":\n";
        Person* person = new Person();
        person->setPerson();
        personSet.insert(person);

        std::cout << "Continue(yes/no)? ";
        do {
            std::cin >> answer;
            if (answer != "yes" && answer != "no"
                && answer != "Yes" && answer != "No")
                std::cin.clear(std::ios::failbit);
            if (!std::cin.good()) {
                std::cout << "Enter \"yes\" or \"no\": ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;       
            }
        } while (true);
    } while (answer != "no" && answer != "No");

    std::cout << "\nEntered " << personSet.size() << " persons.";
    std::multiset<Person*, ComparePersons>::iterator setIter = personSet.begin();
    while (setIter != personSet.end()) {
        (*setIter)->display();
        delete *setIter;
        personSet.erase(setIter++);
    }
    std::cout << "\n\nNow set contain " << personSet.size() << " persons.\n";


    return 0;
}