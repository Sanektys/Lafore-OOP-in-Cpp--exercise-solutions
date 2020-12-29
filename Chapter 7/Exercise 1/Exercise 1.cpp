#include <iostream>

const int MAX_ARRAY = 60;

void reversit(char string[]);

int main() {
    char str[MAX_ARRAY];

    std::cout << "The programm will reverse the entered line\n";
    std::cout << "Enter a sentence: ";
    std::cin.get(str, MAX_ARRAY);

    reversit(str);

    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}

void reversit(char string[]) {
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}