#include <iostream>

class Employee
{
    public :
        void setData();
        void getData() const {
            std::cout << "\nSecond name: " << _name;
            std::cout << "\nNumber: " << _number;
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
    std::cout << "Enter number: ";
    std::cin >> _number;
}

enum class Period
{
    NO_DATA,
    PER_HOURS,
    PER_WEEKS,
    PER_MONTH
};

class Employee2 //: public Employee
{
    public :
        void setData();
        void getData() const;

    private :
        double _compensation;
        Period _period;
};

void Employee2::setData() {
    //Employee::setData();
    std::cout << "Enter employee compensation: ";
    std::cin >> _compensation;
    std::cout << "Enter compensation period(hours - h, weeks - w, month - m): ";
    char letter;
    std::cin >> letter;
    switch (letter) {
        case 'h' :
            _period = Period::PER_HOURS;
            break;
        case 'w' :
            _period = Period::PER_WEEKS;
            break;
        case 'm' :
            _period = Period::PER_MONTH;
            break;
        default :
            _period = Period::NO_DATA;
    }
}

void Employee2::getData() const {
    //Employee::getData();
    std::cout << "\nEmployee compensation: " << _compensation;
    std::cout << ", for period - ";
    switch (_period) {
        case Period::PER_HOURS :
            std::cout << "hours";
            break;
        case Period::PER_WEEKS :
            std::cout << "weeks";
            break;
        case Period::PER_MONTH :
            std::cout << "month";
            break;
        case Period::NO_DATA :
            std::cout << "(no data)";
            break;
    }
}

class Manager : public Employee
{
    public :
        void setData();
        void getData() const;

    private :
        char _title[_LEN];
        double _dues;
};

void Manager::setData() {
    Employee::setData();
    std::cout << "\nEnter position: ";
    std::cin >> _title;
    std::cout << "\nAmount of dues in the golf-club: ";
    std::cin >> _dues;
}

void Manager::getData() const {
    Employee::getData();
    std::cout << "\nPosition: " << _title;
    std::cout << "\nAmount of dues in the golf-club: " << _dues;
}

class Scientist : public Employee
{
    public :
        void setData();
        void getData() const {
            Employee::getData();
            std::cout << "\nNumber of publications " << _pubs;
        }

    private :
        int _pubs;
};

void Scientist::setData() {
    Employee::setData();
    std::cout << "Enter number of publications: ";
    std::cin >> _pubs;
}

class Laborer : public Employee
{

};

class Manager2 : public Employee2, public Manager
{
    public :
        void setData() {
            Manager::setData();
            Employee2::setData();
        }
        void getData() const {
            Manager::getData();
            Employee2::getData();
        }

    private :
};

class Scientist2 : public Employee2, public Scientist
{
    public :
        void setData() {
            Scientist::setData();
            Employee2::setData();
        }
        void getData() const {
            Scientist::getData();
            Employee2::getData();
        }

    private :
};

class Laborer2 : public Employee2, public Laborer
{
    public :
        void setData() {
            Laborer::setData();
            Employee2::setData();
        }
        void getData() const {
            Laborer::getData();
            Employee2::getData();
        }

    private :
};

int main() {
    Manager2 manager;
    manager.setData();

    Scientist2 scientist;
    scientist.setData();

    Laborer2 laborer;
    laborer.setData();

    std::cout << std::endl;
    manager.getData();
    scientist.getData();
    laborer.getData();

    return 0;
}