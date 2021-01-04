#include <iostream>
#include <algorithm>

int main() {
    const int SIZE = 6;
    const int TEXT_SIZE = 40;
    std::string array[SIZE];

    std::cout << "Enter six strings:\n";
    for (int s = 0; s < SIZE; s++) {
        std::cout << s + 1 << ":  ";
        char temp[TEXT_SIZE] = {};
        std::cin >> temp;
        for (int i = 0; i < TEXT_SIZE; i++) {
            if (temp[i] == '\0')
                break;
            array[s].push_back(temp[i]);
        }
    }

    sort(array, array + SIZE, std::greater<std::string>());

    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << i + 1 << ":  ";
        for (int j = 0; j < array[i].size(); j++)
            std::cout << array[i][j];
        std::cout << std::endl;
    }


    return 0;
}