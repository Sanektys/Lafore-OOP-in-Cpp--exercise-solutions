#include <iostream>

class Int
{
    public :
        Int() : _int(0) {};
        Int(int i) : _int(i) {};

        void getInt() const {
            std::cout << "Number equival: " << _int << std::endl;
        }

        Int addInt(Int i) {
            Int temp;
            temp._int = i._int + _int;
            return temp;
        }

    private :
        int _int;
};

int main() {
    Int int1(122);
    Int int2(1023);

    Int int3(int1.addInt(int2));

    int3.getInt();

    return 0;
}