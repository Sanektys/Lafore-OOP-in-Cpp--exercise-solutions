#include <iostream>

class Count
{
    public :
        Count() {
            _count++;
            _sequentialNumber = _count;
        }

        void showSeqNumber() const {
            std::cout << "My sequentialNumber is " << _sequentialNumber << std::endl;
        }

    private :
        static int _count;
        int _sequentialNumber;
};

int Count::_count = 0;

int main() {
    Count countOne;
    Count countTwo;
    Count countThree;

    countOne.showSeqNumber();
    countTwo.showSeqNumber();
    countThree.showSeqNumber();

    return 0;
}