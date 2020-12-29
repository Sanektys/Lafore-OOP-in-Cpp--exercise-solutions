#include <iostream>

struct Date
{
    short day;
    short month;
    short year;
};

enum Etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

struct Employee
{
    int employeeNumber;
    float salary;
    Etype etype;
    Date acceptancesDate;
};

int main() {
    std::cout << "Enter information about three employee in this format:\n"
              << "employee number, salary, position (l, s, m, a, e, r), date acceptance (dd/mm/yyyy)\n";
    char position;
    char comma;
    char slash;
    Employee employee1;
    std::cout << "Enter employee: ";
    std::cin >> employee1.employeeNumber >> comma >> employee1.salary >> comma >> position
        >> comma >>  employee1.acceptancesDate.day >> slash >> employee1.acceptancesDate.month
        >> slash >> employee1.acceptancesDate.year;
    switch (position) {
        case 'l' :
            employee1.etype = laborer;
            break;
        case 's' :
            employee1.etype = secretary;
            break;
        case 'm' :
            employee1.etype = manager;
            break;
        case 'a' :
            employee1.etype = accountant;
            break;
        case 'e' :
            employee1.etype = executive;
            break;
        case 'r' :
            employee1.etype = researcher;
            break;
        default :
            std::cout << "Entered incorrect position!\n";
            return 0;
    }

    Employee employee2;
    std::cout << "Enter employee: ";
    std::cin >> employee2.employeeNumber >> comma >> employee2.salary >> comma >> position 
             >> comma >> employee2.acceptancesDate.day >> slash >> employee2.acceptancesDate.month
             >> slash >> employee2.acceptancesDate.year;
    switch (position) {
        case 'l' :
            employee2.etype = laborer;
            break;
        case 's' :
            employee2.etype = secretary;
            break;
        case 'm' :
            employee2.etype = manager;
            break;
        case 'a' :
            employee2.etype = accountant;
            break;
        case 'e' :
            employee2.etype = executive;
            break;
        case 'r' :
            employee2.etype = researcher;
            break;
        default :
            std::cout << "Entered incorrect position!\n";
            return 0;
    }

    Employee employee3;
    std::cout << "Enter employee: ";
    std::cin >> employee3.employeeNumber >> comma >> employee3.salary >> comma >> position 
        >> comma >> employee3.acceptancesDate.day >> slash >> employee3.acceptancesDate.month
        >> slash >> employee3.acceptancesDate.year;
    switch (position) {
        case 'l' :
            employee3.etype = laborer;
            break;
        case 's' :
            employee3.etype = secretary;
            break;
        case 'm' :
            employee3.etype = manager;
            break;
        case 'a' :
            employee3.etype = accountant;
            break;
        case 'e' :
            employee3.etype = executive;
            break;
        case 'r' :
            employee3.etype = researcher;
            break;
        default :
            std::cout << "Entered incorrect position!\n";
            return 0;
    }

    std::cout << "First employee: " << employee1.employeeNumber << ", "
              << employee1.salary << ", ";
    switch (employee1.etype) {
        case laborer :
            std::cout << "laborer";
            break;
        case secretary :
            std::cout << "secretary";
            break;
        case manager :
            std::cout << "manager";
            break;
        case accountant :
            std::cout << "accountant";
            break;
        case executive :
            std::cout << "executive";
            break;
        case researcher :
            std::cout << "researcher";
            break;
    }
    std::cout << ", " << employee1.acceptancesDate.day << '/'
              << employee1.acceptancesDate.month << '/' << employee1.acceptancesDate.year
              << std::endl;

    std::cout << "Second employee: " << employee2.employeeNumber << ", "
              << employee2.salary << ", ";
    switch (employee2.etype) {
        case laborer :
            std::cout << "laborer";
            break;
        case secretary :
            std::cout << "secretary";
            break;
        case manager :
            std::cout << "manager";
            break;
        case accountant :
            std::cout << "accountant";
            break;
        case executive :
            std::cout << "executive";
            break;
        case researcher :
            std::cout << "researcher";
            break;
    }
    std::cout << ", " << employee2.acceptancesDate.day << '/'
              << employee2.acceptancesDate.month << '/' << employee2.acceptancesDate.year
              << std::endl;

    std::cout << "Third employee: " << employee3.employeeNumber << ", "
              << employee3.salary << ", ";
    switch (employee3.etype) {
        case laborer :
            std::cout << "laborer";
            break;
        case secretary :
            std::cout << "secretary";
            break;
        case manager :
            std::cout << "manager";
            break;
        case accountant :
            std::cout << "accountant";
            break;
        case executive :
            std::cout << "executive";
            break;
        case researcher :
            std::cout << "researcher";
            break;
    }
    std::cout << ", " << employee3.acceptancesDate.day << '/'
              << employee3.acceptancesDate.month << '/' << employee3.acceptancesDate.year
              << std::endl;

    return 0;
}