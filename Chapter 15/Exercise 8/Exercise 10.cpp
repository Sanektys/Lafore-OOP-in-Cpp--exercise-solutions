#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    std::vector<int> intVector;

    std::cout << "Enter some integer numbers in vector.\n";
    std::cout << "Type ctrl+z and double \"enter\" to finish the vector.\n";

    std::istream_iterator<int> inputIter(std::cin);
    std::istream_iterator<int> inputEnd;
    copy(inputIter, inputEnd, std::back_inserter(intVector));
    if (intVector.size() == 0)
        return 0;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<int>::iterator firstIter = intVector.begin();
    std::cout << "Vector contain " << intVector.size() << " elements\n";
    while (firstIter != intVector.end())
        std::cout << *firstIter++ << " ";
    std::cout << std::endl;

    std::cout << "Enter start and end element of copying from the vector,\n"
                 "and position of insert in vector:\n";
    short startElement = 0;
    do {
        std::cout << "Start element is ";  
        std::cin >> startElement;
        if (std::cin.good())
            if (startElement < 1 || startElement > (short)intVector.size()) {
                std::cout << "Start element out of vector range. ";
                std::cin.clear(std::ios::failbit);
            }
        if (!std::cin.good()) {
            std::cout << "Incorrect enter, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
    startElement--;
 
    short endElement = 0;
    do {
        std::cout << "End element is ";
        std::cin >> endElement;
        if (std::cin.good()) {
            if (endElement < 1 || endElement > (short)intVector.size()) {
                std::cout << "End element out of vector range. ";
                std::cin.clear(std::ios::failbit);
            }
            else if (endElement < startElement + 1) {
                std::cout << "End element located before start element. ";
                std::cin.clear(std::ios::failbit);
            }
        }
        if (!std::cin.good()) {
            std::cout << "Incorrect enter, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);

    short insertPosition = 0;
    do {
        std::cout << "Insert position is ";
        std::cin >> insertPosition;
        if (std::cin.good()) {
            if (insertPosition < 1 || insertPosition > (short)intVector.size() + 1) {
                std::cout << "Insert position out of vector range. ";
                std::cin.clear(std::ios::failbit);
            }
            else if (endElement - startElement >= insertPosition) {
                std::cout << "Copying beyond the beginning of the vector in case \"backward copy\". ";
                std::cin.clear(std::ios::failbit);
            }
        }
        if (!std::cin.good()) {
            std::cout << "Incorrect enter, try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
    insertPosition--;


    std::cout << "Result of standart copying:\n";
    std::vector<int> vectorSecond = intVector;
    std::copy(intVector.begin() + startElement, intVector.begin() + endElement,
              std::inserter(vectorSecond, vectorSecond.begin() + insertPosition));
    firstIter = vectorSecond.begin();
    while (firstIter != vectorSecond.end())
        std::cout << *firstIter++ << ' ';
    std::cout << std::endl;

    std::cout << "Result of backward copying:\n";
    std::vector<int> vectorThird = intVector;
    std::copy_backward(intVector.begin() + startElement, intVector.begin() + endElement,
                       vectorThird.begin() + insertPosition);
    firstIter = vectorThird.begin();
    while (firstIter != vectorThird.end())
        std::cout << *firstIter++ << ' ';
    std::cout << std::endl;


    return 0;
}