#include <iostream>

class ArrayPointers
{
    public :
        ArrayPointers() {
            for (int i = 0; i < SIZE; i++)
                *(_array + i) = new int[10];
        }

        void fillArray();
        void showArray() const;

        int& operator[](int) const;

    private :
        static const int SIZE = 10;
        int* _array[SIZE];
};

void ArrayPointers::fillArray() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < 10; j++)
            *(*(_array + i) + j) = i * 10 + j;
}

void ArrayPointers::showArray() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << *(*(_array + i) + j) << " ";
        std::cout << std::endl;
    }
}

int& ArrayPointers::operator[](int n) const {
    if (n >= 0 && n < SIZE * 10) {
        int i = 0;
        while (n >= 10) {
            n -= 10;
            i++;
        }
        int j = n;
        return *(*(_array + i) + j);
    }
    else
        return *(*(_array));
}

int main() {
    ArrayPointers array;

    array.fillArray();
    array.showArray();

    std::cout << array[20] << ", " << array[32] << ", " << array[56] << std::endl;

    array[0] = 115;
    array[1] = 86;
    array[9] = 42;
    array[10] = 96;
    array[11] = 64;

    array.showArray();

    return 0;
}