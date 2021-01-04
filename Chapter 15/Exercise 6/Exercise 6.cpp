#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    std::vector<int> intVector;

    std::cout << "Enter some integer numbers in vector. Program will reverse this vector.\n";
    std::cout << "Type ctrl+z to finish the vector.\n";

    std::istream_iterator<int> inputIter(std::cin);
    std::istream_iterator<int> inputEnd;
    copy(inputIter, inputEnd, std::back_inserter(intVector));
    if (intVector.size() == 0)
        return 0;

    std::vector<int>::iterator firstIter = intVector.begin();
    std::cout << "Vector contain " << intVector.size() << " elements\n";
    while (firstIter != intVector.end())
        std::cout << *firstIter++ << " ";
    std::cout << std::endl;

    firstIter = intVector.begin();
    std::vector<int>::reverse_iterator secondIter = intVector.rbegin();
    for (int i = 0; i < intVector.size() / 2; i++) {
        int temp = *secondIter;
        *secondIter++ = *firstIter;       
        *firstIter++ = temp;
    }

    firstIter = intVector.begin();
    std::cout << "Reversing vector:\n";
    while (firstIter != intVector.end())
        std::cout << *firstIter++ << " ";
    std::cout << std::endl;


    return 0;
}