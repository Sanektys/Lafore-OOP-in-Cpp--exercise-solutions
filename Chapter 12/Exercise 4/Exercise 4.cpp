#include <iostream>
#include <fstream>

int main() {
    std::cout << "Enter the employee's surname, first name and patronymic,\n"
                 "as well as his consecutive number.\n";
    std::string firstName;
    std::string secondName;
    std::string patronymic;
    unsigned int number;

    std::ofstream outFile;
    outFile.open("Person.dat", std::ios::app);

    char answer;
    do {
        std::cin.unsetf(std::ios::skipws);
        std::cout << "\n...first name: ";
        while (true) {
            std::cin >> firstName;
            if (!std::cin.good()) {
                std::cerr << "Error in entering name, try again: ";
                std::cin.clear();
                std::cin.get();
                continue;
            }
            else {
                std::cin.get();
                break;
            }
        }
        std::cout << "...second name: ";
        while (true) {
            std::cin >> secondName;
            if (!std::cin.good()) {
                std::cerr << "Error in entering second name, try again: ";
                std::cin.clear();
                std::cin.get();
                continue;
            }
            else {
                std::cin.get();
                break;
            }
        }
        std::cout << "...patronymic: ";
        while (true) {
            std::cin >> patronymic;
            if (!std::cin.good()) {
                std::cerr << "Error in entering patronymic, try again: ";
                std::cin.clear();
                std::cin.get();
                continue;
            }
            else {
                std::cin.get();
                break;
            }
        }
        std::cout << "...consecutive number: ";
        while (true) {
            std::cin >> number;
            if (!std::cin.good()) {
                std::cerr << "Error in entering consecutive number, try again: ";
                std::cin.clear();
                std::cin.ignore(10, '\n');
                continue;
            }
            else {
                std::cin.ignore(10, '\n');
                break;
            }
        }
        std::cin.setf(std::ios::skipws);

        outFile << firstName << ' ' << secondName << ' ' << patronymic << ' ' << number << ' ';

        std::cout << "Continue enter(y/n)? ";
        std::cin >> answer;
        std::cin.ignore(2, '\n');
    } while (answer != 'n');
    outFile.close();
    std::cout << std::endl;

    std::ifstream inFile;
    inFile.open("Person.dat");
    if (inFile.good()) {
        inFile >> firstName >> secondName >> patronymic >> number;
        short count = 1;
        while (!inFile.eof()) {
            std::cout << "Person " << count << ": first name - " << firstName
                      << ", second name - " << secondName << ", patronymic - " << patronymic
                      << ", consecutive number: " << number << std::endl;
            inFile >> firstName >> secondName >> patronymic >> number;
            count++;
        }
    }

    return 0;
}