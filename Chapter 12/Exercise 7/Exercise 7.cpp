#include <iostream>
#include <fstream>

class Name
{
    public :
        Name() : _firstName(), _secondName(), _patronymic(), _number(0) {}

        void setData();
        void getData() const {
            std::cout << "Person " << _number <<  ": first name - " << _firstName
                      << ", second name - " << _secondName
                      << ", patronymic - " << _patronymic << std::endl;
        }

        void exportData() const;
        void importData(int item = 0);

        static void open();
        static void resetPointer() {
            if (_file.good())
                _file.seekg(0);
        }
        static bool isEndOfFile();

    private :
        std::string _firstName;
        std::string _secondName;
        std::string _patronymic;
        unsigned int _number;

        static std::fstream _file;
};

void Name::setData() {
    std::cout << "Enter the employee's surname, first name and patronymic,\n"
                 "as well as his consecutive number.\n";

    std::cin.unsetf(std::ios::skipws);
    std::cout << "\n...first name: ";
    while (true) {
        std::cin >> _firstName;
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
        std::cin >> _secondName;
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
        std::cin >> _patronymic;
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
        std::cin >> _number;
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
}

void Name::exportData() const {
    if (_file.good())
        _file << _number << ' ' << _firstName << ' '
              << _secondName << ' ' << _patronymic << ' ';
    else
        std::cerr << "Failure write data!\n";
}

void Name::importData(int item) {
    int backupNumber = _number;
    std::string backupFirstName = _firstName;
    std::string backupSecondName = _secondName;
    std::string backupPatronymic = _patronymic;

    if (_file.good()) {
        _file >> _number >> _firstName
              >> _secondName >> _patronymic;
        if (item == 0)
            return;
        else if (item == _number)
            return;
        
        while (!_file.eof()) {
            _file >> _number >> _firstName
                  >> _secondName >> _patronymic;
            if (item == _number)
                return;
        }

        std::cout << "Element not found.\n";
        _number = backupNumber;
        _firstName = backupFirstName;
        _secondName = backupSecondName;
        _patronymic = backupPatronymic;
    }
    else
        std::cerr << "File opening failure!\n";
}

void Name::open() {
    _file.open("Person.dat", std::ios::in | std::ios::out
                             | std::ios::ate | std::ios::app);
    if (!_file.good()) {
        std::cerr << "File open failure\n";
        _file.close();
    }
}

bool Name::isEndOfFile() {
    int currPosition = _file.tellg();
    _file.seekg(0, std::ios::end);
    int endPosition = _file.tellg();
    _file.seekg(currPosition);
    if (currPosition + 1 >= endPosition)
        return true;
    else
        return false;
}

std::fstream Name::_file;

int main() {
    Name person;
    person.setData();

    Name::open();
    person.exportData();
    Name::resetPointer();
    person.importData(6);

    person.getData();

    std::cout << std::endl;
    Name::resetPointer();
    while (!Name::isEndOfFile()) {
        person.importData();
        person.getData();
    }

    return 0;
}