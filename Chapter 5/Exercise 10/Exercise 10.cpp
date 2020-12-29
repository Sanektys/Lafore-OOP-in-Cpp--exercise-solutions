#include <iostream>

inline void callCount();

int main() {
    std::cout << "The program calculates the number of calls "
                 "to a specific function\n";

    for (int i = 0; i < 10; i++)
        callCount();

    return 0;
}

inline void callCount() {
    static int callCount = 0;
    std::cout << callCount++ << std::endl;
}