#include <iostream>

class SafeArray
{
    public :
        SafeArray() : _array() {}

        void putElement(int index, int argue);
        int getElement(int index) const;

    private :
        static const int _LIMIT = 60;
        int _array[_LIMIT];
};

void SafeArray::putElement(int index, int argue) {
    if (index >= 0 && index < _LIMIT)
        _array[index] = argue;
    else
        std::cout << "Incorrect range!";
}

int SafeArray::getElement(int index) const {
    if (index >= 0 && index < _LIMIT)
        return _array[index];
    else
        std::cout << "Incorrect range!";
    return 0;
}

int main() {
    SafeArray array;
    std::cout << array.getElement(-1);
    std::cout << array.getElement(60);
    std::cout << std::endl;

    int temp = 567;
    array.putElement(8, temp);
    temp = array.getElement(8);
    std::cout << temp << std::endl;

    array.putElement(60, temp);
    temp = array.getElement(60);
    std::cout << temp << std::endl;

    return 0;
}