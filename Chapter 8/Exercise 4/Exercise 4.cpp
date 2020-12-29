#include <iostream>

class Int
{
    public :
        Int() : _int(0) {};
        Int(int i) : _int(i) {};

        void getInt() const {
            std::cout << "Number equival: " << _int;
        }

        Int operator+(Int i) const;
        Int operator-(Int i) const;
        Int operator*(Int i) const;
        Int operator/(Int i) const;
    private :
        int _int;
};

Int Int::operator+(Int i) const {
    long long temp = (long long)_int + (long long)i._int;
    if (temp >= 2147483648 || temp <= -2147483648) {
        std::cout << "Out of range!\n";
        return Int(0);
    }
    return Int((int)temp);
}

Int Int::operator-(Int i) const {
    long long temp = (long long)_int - (long long)i._int;
    if (temp >= 2147483648 || temp <= -2147483648) {
        std::cout << "Out of range!\n";
        return Int(0);
    }
    return Int((int)temp);
}

Int Int::operator*(Int i) const {
    long long temp = (long long)_int * (long long)i._int;
    if (temp >= 2147483648 || temp <= -2147483648) {
        std::cout << "Out of range!\n";
        return Int(0);
    }
    return Int((int)temp);
}

Int Int::operator/(Int i) const {
    double temp = (double)_int / (double)i._int;
    if (temp >= 2147483648.0f || temp <= -2147483648.0f) {
        std::cout << "Out of range!\n";
        return Int(0);
    }
    return Int((int)temp);
}

int main() {
    Int intOne(2147483647);
    intOne.getInt();
    std::cout << std::endl;

    Int intTwo(1);
    Int intThree;
    intThree = intOne + intTwo;
    intThree.getInt();
    std::cout << std::endl;

    intOne = 1488;
    intTwo = 1556;
    intThree = intOne - intTwo;
    intThree.getInt();
    std::cout << std::endl;

    intThree = intOne * intTwo;
    intThree.getInt();
    std::cout << std::endl;

    intOne = 12846;
    intThree = intOne / intTwo;
    intThree.getInt();
    std::cout << std::endl;

    return 0;
}