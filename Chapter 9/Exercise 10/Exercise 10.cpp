#include <iostream>

class Student
{
    public :
        Student() : _school("Null"), _degree("Null") {}
        
        void setEducation();
        void getEducation() const {
            std::cout << "educational institution: " << _school;
            std::cout << ", degree - " << _degree;
        }

    private :
        static const int _LEN = 80;
        char _school[_LEN];
        char _degree[_LEN];
};

void Student::setEducation() {
    std::cout << "\nEnter name of educational unstitution: ";
    std::cin >> _school;
    std::cout << "Enter a higher education degree\n"
                 "(incomplete higher education, bachelor, master, PhD): ";
    std::cin >> _degree;
}

class Employee
{
    public :
        Employee() : _name("N/A"), _number(0) {}

        void setData();
        void getData() const {
            std::cout << "second name: " << _name;
            std::cout << ", employee number: " << _number;
        }

    protected :
        static const int _LEN = 80;

    private :
        char _name[_LEN];
        unsigned int _number;
};

void Employee::setData() {
    std::cout << "\nEnter second name: ";
    std::cin >> _name;
    std::cout << "Enter employee number: ";
    std::cin >> _number;
}

class Manager : private Employee, private Student
{
    public :
        Manager() : Employee(), Student(), _title("N/A"), _dues(0.0) {}

        void setData();
        void getData() const;

    private :
        char _title[Employee::_LEN];
        double _dues;
};

void Manager::setData() {
    Employee::setData();
    std::cout << "\nEnter position: ";
    std::cin >> _title;
    std::cout << "Enter golf club fee: ";
    std::cin >> _dues;
    Student::setEducation();
}

void Manager::getData() const {
    Employee::getData();
    std::cout << ", position: " << _title;
    std::cout << ", golf club fee: " << _dues << ", ";
    Student::getEducation();
}

class Executive : private Manager
{
    public :
        Executive() : Manager(), _annualBonus(0.0f), _numberOfShares(0.0f) {}

        void setData();
        void getData() const;

    private :
        float _annualBonus;
        float _numberOfShares;
};

void Executive::setData() {
    Manager::setData();
    std::cout << "\nEnter annual bonus: ";
    std::cin >> _annualBonus;
    std::cout << "\nEnter number of shares: ";
    std::cin >> _numberOfShares;
}

void Executive::getData() const {
    Manager::getData();
    std::cout << ", annual bonus: $" << _annualBonus;
    std::cout << ", number of shares: " << _numberOfShares << '%';
}

class Scientist : private Employee, private Student
{
    public :
        Scientist() : Employee(), Student(), _publications(0) {}

        void setData();
        void getData() const;

    private :
        int _publications;
};

void Scientist::setData() {
    Employee::setData();
    std::cout << "\nEnter number of publications: ";
    std::cin >> _publications;
    Student::setEducation();
}

void Scientist::getData() const {
    Employee::getData();
    std::cout << ", publications: " << _publications << ", ";
    Student::getEducation();
}

class Laborer : public Employee
{

};

int main() {
    Executive executive;

    std::cout << "Enter information about executive employee:\n";
    executive.setData();
    std::cout << std::endl;

    std::cout << "You entered following information:\n";
    executive.getData();
    std::cout << std::endl;

    return 0;
}