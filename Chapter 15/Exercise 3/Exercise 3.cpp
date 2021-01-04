#include <iostream>
#include <algorithm>
#include <list>


int main() {
    std::list<int> intList;

    std::cout << "Enter some integer numbers in list. Program will reverse this list.\n";
    std::cout << "Type ctrl+z to finish the list.\n";

    std::istream_iterator<int> inputIter(std::cin);
    std::istream_iterator<int> inputEnd;
    copy(inputIter, inputEnd, std::back_inserter(intList));
    if (intList.size() == 0)
        return 0;

    std::list<int>::iterator firstIter = intList.begin();
    std::cout << "List contain " << intList.size() << " elements\n";
    while (firstIter != intList.end())
        std::cout << *firstIter++ << " ";
    std::cout << std::endl;

    firstIter = intList.begin();
    std::list<int>::iterator secondIter = intList.end();
    do {
        int temp = *--secondIter;
        if (firstIter == secondIter)
            break;
        *secondIter = *firstIter;    
        *firstIter++ = temp;
    } while (firstIter != secondIter);

    firstIter = intList.begin();
    std::cout << "Reversing list:\n";
    while (firstIter != intList.end())
        std::cout << *firstIter++ << " ";
    std::cout << std::endl;


    return 0;
}