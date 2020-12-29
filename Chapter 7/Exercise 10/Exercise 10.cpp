#include <iostream>

class SafeMatrix
{
    public :
        SafeMatrix() : _array(), _rangeOne(_LIMIT), _rangeTwo(_LIMIT) {}
        SafeMatrix(int rangeOne, int rangeTwo) : _array(),
                  _rangeOne(rangeOne), _rangeTwo(rangeTwo) {}

        void putElement(int indexOne, int indexTwo, int argue);
        int getElement(int indexOne, int indexTwo) const;

    private :
        static const int _LIMIT = 10;
        int _array[_LIMIT][_LIMIT];
        int _rangeOne;
        int _rangeTwo;
};

void SafeMatrix::putElement(int indexOne, int indexTwo, int argue) {
    bool conditionOne = indexOne >= 0 && indexOne < _rangeOne;
    bool conditionTwo = indexTwo >= 0 && indexTwo < _rangeTwo;
    if (conditionOne && conditionTwo)
        _array[indexOne][indexTwo] = argue;
    else
        std::cout << "Incorrect range!";
}

int SafeMatrix::getElement(int indexOne, int indexTwo) const {
    bool conditionOne = indexOne >= 0 && indexOne < _rangeOne;
    bool conditionTwo = indexTwo >= 0 && indexTwo < _rangeTwo;
    if (conditionOne && conditionTwo)
        return _array[indexOne][indexTwo];
    else
        std::cout << "Incorrect range!";
    return 0;
}

int main() {
    SafeMatrix matrix(5, 6);
    std::cout << matrix.getElement(-1, 2);
    std::cout << matrix.getElement(4, 10);
    std::cout << std::endl;

    int temp = 567;
    matrix.putElement(4, 5, temp);
    temp = matrix.getElement(4, 5);
    std::cout << temp << std::endl;

    matrix.putElement(6, 5, temp);
    temp = matrix.getElement(6, 5);
    std::cout << temp << std::endl;

    return 0;
}