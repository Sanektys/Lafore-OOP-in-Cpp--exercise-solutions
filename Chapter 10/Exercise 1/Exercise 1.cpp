#include <iostream>
#include <conio.h>

int main() {
    std::cout << "The program calculates the average value "
                 "of the entered numbers (up to 10).\n";
    std::cout << "Enter \"0\" to stop enter\n";
    float** numbArray = new float*[10];
    short count = 0;
    do {
        std::cout << "Enter number: ";
        float* number = new float;
        std::cin >> *number;
        if (*number == 0) {
            delete number;
            break;
        }
        *(numbArray + count) = number;
        count++;
    } while (count < 10 );

    float* result = new float;
    *result = 0.0f;
    for (int i = 0; i < count; i++)
        *result += **(numbArray + i);
    *result /= count;

    std::cout << "Result: " << *result << std::endl;

    for (int i = 0; i < count; i++)
        delete *(numbArray + i);
    delete result;
    delete[] numbArray;

    return 0;
}