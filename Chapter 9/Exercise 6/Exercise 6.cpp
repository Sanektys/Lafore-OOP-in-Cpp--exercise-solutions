#include <iostream>

class Safearray
{
    public :
        Safearray() : _array() {}
        
        int& operator[](int n);

    protected :
        static const int _LIMIT = 100;

    private :
        int _array[_LIMIT];
};

int& Safearray::operator[](int n) {
    if (n < 0 || n >= _LIMIT) {
        std::cout << "Incorrect range! ";
        return _array[0];
    }
    return _array[n];
}

class Safehilo : public Safearray
{
    public :
        Safehilo() : Safearray(), _lowLimit(0), _topLimit(_LIMIT) {}
        Safehilo(int lowLimit, int topLimit);

        int& operator[](int index);

    private :
        int _lowLimit;
        int _topLimit;
};

int& Safehilo::operator[](int index) {
    if (index >= _lowLimit && index < _topLimit)
        return Safearray::operator[](index - _lowLimit);
    else
        return Safearray::operator[](0);
}

Safehilo::Safehilo(int lowLimit, int topLimit)
                   : Safearray(), _lowLimit(lowLimit) {
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

int main() {
    Safehilo array(75, 185);
    for (int i = 75; i < 185; i++) {
        array[i] = i;
    }

    std::cout << array[75] << ", " << array[174] << std::endl;

    return 0;
}