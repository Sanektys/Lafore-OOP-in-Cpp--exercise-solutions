#include <iostream>

int compstr(char*, char*);

int main() {
    char* stringOne = (char*)"What you're looking for";
    char* stringTwo = (char*)"What you're doing";

    int compare = compstr(stringOne, stringTwo);
    if (compare < 0)
        std::cout << "The first line goes before the second line\n";
    else if (compare > 0)
        std::cout << "the second line goes before the first line\n";
    else if (compare == 0)
        std::cout << "Line are equal";

    std::cout << std::endl;
    stringOne = stringTwo;
    compare = compstr(stringOne, stringTwo);
    if (compare < 0)
        std::cout << "The first line goes before the second line\n";
    else if (compare > 0)
        std::cout << "the second line goes before the first line\n";
    else if (compare == 0)
        std::cout << "Line are equal";

    std::cout << std::endl;

    return 0;
}

int compstr(char* stringOne, char* stringTwo) {
    while (*stringOne != '\0' && *stringTwo != '\0') {
        if (*stringOne < *stringTwo)
            return -1;
        else if (*stringOne > *stringTwo)
            return 1;
        
        ++stringOne;
        stringTwo++;
    }

    return 0;
}