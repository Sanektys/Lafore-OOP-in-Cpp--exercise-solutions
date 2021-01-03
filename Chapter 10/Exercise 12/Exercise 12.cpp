#include <iostream>

float fmemory[100];
int fmem_top = 0;

int pmemory[100];
int pmem_top = 0;

class Float
{
    public :
        Float() : _addr(0) {}
        Float(float data) {
            fmemory[fmem_top] = data;
            _addr = fmem_top;
            fmem_top++;
        }

        int operator&() const {
            return _addr;
        }

    private :
        int _addr;
};

class PtrFloat
{
    public :
        PtrFloat(int pointer) {
            pmemory[pmem_top] = pointer;
            _addr = pmem_top;
            pmem_top++;
        }

        float& operator*() {
            return fmemory[pmemory[_addr]];
        }

    private :
        int _addr;
};

int main() {
    Float varOne = 6.25f;
    Float varTwo = 8.48f;
    PtrFloat pointOne = &varOne;
    PtrFloat pointTwo = &varTwo;
    std::cout << *pointOne << std::endl;
    std::cout << *pointTwo << std::endl;
    *pointOne = 14.88f;
    *pointTwo = 16.0f;
    std::cout << *pointOne << std::endl;
    std::cout << *pointTwo << std::endl;

    return 0;
}