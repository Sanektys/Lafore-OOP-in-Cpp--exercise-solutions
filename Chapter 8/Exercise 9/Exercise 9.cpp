#include <iostream>

class SafeArray
{
    public :
        SafeArray() : _array(), _lowLimit(0), _topLimit(_LIMIT) {}
        SafeArray(int lowLimit, int topLimit);

        void putElement(int index, int argue);
        int getElement(int index) const;

        int& operator[](int index);

    private :
        static const int _LIMIT = 100;
        int _lowLimit;
        int _topLimit;
        int _array[_LIMIT];
};

int& SafeArray::operator[](int index) {
    if (index >= _lowLimit && index < _topLimit)
        return _array[index - _lowLimit];
    else
        return _array[0];
}

SafeArray::SafeArray(int lowLimit, int topLimit)
                     : _array(), _lowLimit(lowLimit) {
    if (lowLimit >= topLimit) {
        std::cout << "Array boundaries are set incorrectly\n";
        _lowLimit = 0;
        _topLimit = _LIMIT;
    }
    if (topLimit - lowLimit > 100)
        _topLimit = lowLimit + 100;
    else
        _topLimit = topLimit;
}

void SafeArray::putElement(int index, int argue) {
    if (index >= _lowLimit && index < _topLimit)
        _array[index - _lowLimit] = argue;
    else
        std::cout << "Incorrect range!";
}

int SafeArray::getElement(int index) const {
    if (index >= _lowLimit && index < _topLimit)
        return _array[index - _lowLimit];
    else
        std::cout << "Incorrect range!";
    return 0;
}

int main() {
    SafeArray array(75, 185);
    for (int i = 75; i < 185; i++) {
        array[i] = i;
    }

    std::cout << array[75] << ", " << array[174] << std::endl;

    return 0;
}