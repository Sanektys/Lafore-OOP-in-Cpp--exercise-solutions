#include <iostream>

enum Etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

int main() {
    std::cout << "Enter the first letter of the position(l, s, m, a, e, r): ";
    char letter;
    std::cin >> letter;

    Etype etype;
    switch (letter) {
        case 'l' :
            etype = laborer;
            break;
        case 's' :
            etype = secretary;
            break;
        case 'm' :
            etype = manager;
            break;
        case 'a' :
            etype = accountant;
            break;
        case 'e' :
            etype = executive;
            break;
        case 'r' :
            etype = researcher;
            break;
        default :
            std::cout << "Entered incorrect letter!\n";
            return 0;
    }

    std::cout << "Full name of position: ";
    switch (etype) {
        case laborer :
            std::cout << "laborer\n";
            break;
        case secretary :
            std::cout << "secretary\n";
            break;
        case manager :
            std::cout << "manager\n";
            break;
        case accountant :
            std::cout << "accountant\n";
            break;
        case executive :
            std::cout << "executive\n";
            break;
        case researcher :
            std::cout << "researcher\n";
            break;
    }

    return 0;
}