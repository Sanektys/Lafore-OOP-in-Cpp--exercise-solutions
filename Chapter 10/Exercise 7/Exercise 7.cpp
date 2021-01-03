#include <iostream>

class Person
{
    public :
        Person() : _name(), _salary(0.0f) {}

        void setData();

        void printData() const {
            std::cout << "Name: " << _name
                      << ", salary: $" << _salary << std::endl;
        }

        std::string getName() const { return _name; }
        float getSalary() const { return _salary; }

    protected :
        std::string _name;
        float _salary;
};

void Person::setData() {
    std::cout << "Enter the name: ";
    std::cin >> _name;
    std::cout << "enter salary: ";
    std::cin >> _salary;
    std::cin.get();
}

void salarySort(Person**);

int main() {
    Person* persArray[10] = {};
    char choice;

    for (int i = 0; i < 10; i++) {
        persArray[i] = new Person;
        persArray[i]->setData();
        
        std::cout << "Continue enter(y/n)? ";
        std::cin >> choice;
        if (choice == 'n')
            break;
    }

    salarySort(persArray);

    for (int i = 0; i < 10; i++) {
        if (*(persArray + i) == NULL)
            break;
        (*(persArray + i))->printData();
        delete *(persArray + i);
    }

    return 0;
}

void salarySort(Person** array) {
    for (int i = 0; i < 9; i++) {
        if (*(array + i) == nullptr)
            break;
        for (int j = i + 1; j < 10; j++) {
            if (*(array + j) == nullptr)
                break;
            if ((*(array + i))->getSalary() > (*(array + j))->getSalary()) {
                Person* temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
}