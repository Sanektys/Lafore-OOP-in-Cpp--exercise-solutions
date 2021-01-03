#include <iostream>
#include <fstream>

const int LEN = 32;
const int MAXEM = 100;

enum class EmployeeType
{
    NONE,
    MANAGER,
    SCIENTIST,
    LABORER
};

///////////////////////////////////////////////////////////////////////////////

class Employee
{
   public :
       Employee() : _name(), _number(0) {}
       virtual ~Employee() {};

       virtual void setData();
       virtual void getData() const {
           std::cout << "\nSurname: " << _name;
           std::cout << "\nNumber: " << _number;
       }

       virtual EmployeeType getType() const;

       static void add();
       static void display();
       static void read();
       static void write();
       static void find();

   private :
       char _name[LEN];
       unsigned int _number;
       static int _n;
       static Employee* _arrap[];
};

///////////////////////////////////////////////////////////////////////////////

class Manager : public Employee
{
    public :
        Manager() : Employee(), _title(), _dues(0.0) {}
        virtual ~Manager() override {};

        void setData() override {
            Employee::setData();
            std::cout << "Enter title: ";
            std::cin >> _title;
            std::cout << "Enter dues: ";
            std::cin >> _dues;
        }
        void getData() const override {
            Employee::getData();
            std::cout << "\nTitle: " << _title
                      << "\nGolf-club dues: " << _dues;
        }

    private :
        char _title[LEN];
        double _dues;
};

///////////////////////////////////////////////////////////////////////////////

class Scientist : public Employee
{
    public :
        Scientist() : Employee(), _pubs(0) {}
        virtual ~Scientist() override {}

        void setData() override {
            Employee::setData();
            std::cout << "Enter number of publications: ";
            std::cin >> _pubs;
        }
        void getData() const override {
            Employee::getData();
            std::cout << "\nNumber of publications: " << _pubs;
        }

    private :
        int _pubs;
};

///////////////////////////////////////////////////////////////////////////////

class Laborer : public Employee 
{};

///////////////////////////////////////////////////////////////////////////////

int Employee::_n;
Employee* Employee::_arrap[MAXEM];

void Employee::setData() {
    std::cin.ignore(10, '\n');
    std::cout << "Enter surname: ";
    std::cin >> _name;
    std::cout << "Enter number: ";
    std::cin >> _number;
}

void Employee::add() {
    char ch;
    std::cout << "press 'm' for add manager\n"
                 "press 's' for add scientist\n"
                 "press 'l' for add laborer\n"
                 "Your choice: ";
    std::cin >> ch;
    switch (ch) {
        case 'm': 
            _arrap[_n] = new Manager;
            break;
        case 's' :
            _arrap[_n] = new Scientist;
            break;
        case 'l' :
            _arrap[_n] = new Laborer;
            break;
        default :
            std::cout << "Unknow kind of employee\n";
    }
    _arrap[_n++]->setData();
}

void Employee::display() {
    for (int j = 0; j < _n; j++) {
        std::cout << j + 1;
        switch (_arrap[j]->getType()) {
            case EmployeeType::MANAGER :
                std::cout << ". Type: Manager";
                break;
            case EmployeeType::SCIENTIST :
                std::cout << ". Type: Scientist";
                break;
            case EmployeeType::LABORER :
                std::cout << ". Type: Laborer";
                break;
            default :
                std::cout << ". Unknow type";
        }
        _arrap[j]->getData();
        std::cout << std::endl;
    }
}

EmployeeType Employee::getType() const {
    if (typeid(*this) == typeid(Manager))
        return EmployeeType::MANAGER;
    else if (typeid(*this) == typeid(Scientist))
        return EmployeeType::SCIENTIST;
    else if (typeid(*this) == typeid(Laborer))
        return EmployeeType::LABORER;
    else {
        std::cerr << "Incorrect kind of employee";
        return EmployeeType::NONE;
    }
    return EmployeeType::NONE;
}

void Employee::write() {
    int size = 0;
    std::cout << "There are " << _n << " employees on record.\n";
    std::ofstream outputFile;
    EmployeeType empType;

    outputFile.open("Employee.dat", std::ios::trunc | std::ios::binary);
    if (!outputFile.good()) {
        std::cerr << "Impossible to read file!\n";
        return;
    }
    for (int j = 0; j < _n; j++) {
        empType = _arrap[j]->getType();

        outputFile.write((char*)&empType, sizeof(empType));
        switch (empType) {
            case EmployeeType::MANAGER : 
                size = sizeof(Manager);
                break;
            case EmployeeType::SCIENTIST :
                size = sizeof(Scientist);
                break;
            case EmployeeType::LABORER :
                size = sizeof(Laborer);
                break;
        }
        outputFile.write((char*)(_arrap[j]), size);
        if (!outputFile.good()) {
            std::cerr << "Record on file is impossible\n";
            return;
        }
    }
}

void Employee::read() {
    int size;
    EmployeeType empType;
    std::ifstream inputFile;
    inputFile.open("Employee.dat", std::ios::binary);
    if (!inputFile.good()) {
        std::cerr << "Impossible to read file\n";
        return;
    }
    _n = 0;
    while (true) {
        inputFile.read((char*)&empType, sizeof(empType));
        if (inputFile.eof())
            break;
        if (!inputFile.good()) {
            std::cerr << "Impossible to read current type\n";
            return;
        }
        switch (empType) {
            case EmployeeType::MANAGER :
                _arrap[_n] = new Manager;
                size = sizeof(Manager);
                break;
            case EmployeeType::SCIENTIST :
                _arrap[_n] = new Scientist;
                size = sizeof(Scientist);
                break;
            case EmployeeType::LABORER :
                _arrap[_n] = new Laborer;
                size = sizeof(Laborer);
                break;
            default :
                std::cout << "Unknow kind of employee in file\n";
                return;
        }
        inputFile.read((char*)_arrap[_n], size);
        if (!inputFile.good()) {
            std::cerr << "Reading data from file is impossible\n";
            return;
        }
        _n++;
    }
    std::cout << "There is a reading for " << _n << " employees\n";
}

void Employee::find() {
    std::ifstream inputFile("Employee.dat", std::ios::binary);
    if (!inputFile) {
        std::cerr << "File doesn't exist or spoiled.\n";
        return;
    }

    std::cout << "Enter employee number who you want to find: ";
    unsigned int number;
    std::cin >> number;

    Employee* employee = nullptr;
    int size = 0;
    EmployeeType empType;

    while (true) {
        inputFile.read((char*)&empType, sizeof(empType));
        if (inputFile.eof())
            break;
        if (!inputFile) {
            std::cerr << "Unexpected error during read file.\n";
            return;
        }
        switch (empType) {
            case EmployeeType::MANAGER :
                employee = new Manager;
                size = sizeof(Manager);
                break;
            case EmployeeType::SCIENTIST :
                employee = new Scientist;
                size = sizeof(Scientist);
                break;
            case EmployeeType::LABORER :
                employee = new Laborer;
                size = sizeof(Laborer);
                break;
            default :
                std::cerr << "Wrong readed type of employee.\n";
                return;
        }
        inputFile.read((char*)employee, size);
        
        if (employee->_number == number) {
            std::cout << "Number " << number << " from list of employee is:";
            employee->getData();
            std::cout << std::endl;
            delete employee;
            return;
        }

        delete employee;
        employee = nullptr;
    }

    std::cout << "Employee not found.\n";
    if (employee)
        delete employee;
}

///////////////////////////////////////////////////////////////////////////////

int main() {
    char ch;
    while (true) {
        std::cout << "Press 'a' - for add data of employee\n"
                     "Press 'd' - for display data about all employees\n"
                     "Press 'w' - for record all data in file\n"
                     "Press 'r' - for read all data from file\n"
                     "Press 'f' - for search employee from file by number\n"
                     "Press 'x' - for exit\n"
                     "Your choice: ";
        std::cin >> ch;
        switch (ch) {
            case 'a' :
                Employee::add();
                break;
            case 'd' :
                Employee::display();
                break;
            case 'w' :
                Employee::write();
                break;
            case 'r' :
                Employee::read();
                break;
            case 'f' :
                Employee::find();
                break;
            case 'x' :
                break;
            default :
                std::cout << "Unknow command\n";
        }
        if (ch == 'x')
            break;
    }

    return 0;
}