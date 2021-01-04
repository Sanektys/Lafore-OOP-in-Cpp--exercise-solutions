#include <iostream>
#include <fstream>


int main() {
    std::cout << "Program will copy integer numbers from one file to another file\n"
                 "Enter the name of the source file: ";
    std::string sourceFile;
    std::cin.unsetf(std::ios::skipws);
    std::cin >> sourceFile;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ifstream inputFile(sourceFile + ".int");
    if (!inputFile.good()) {
        std::cout << "Can not open the file!\n";
        return 0;
    }
    std::istream_iterator<int> inputIter(inputFile);
    std::istream_iterator<int> inputEnd;


    std::cout << "Enter the name of the destination file: ";
    std::string destFile;
    std::cin >> destFile;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.setf(std::ios::skipws);

    std::ofstream outputFile(destFile + ".int");
    std::ostream_iterator<int> outputIter(outputFile, " ");

    while (inputIter != inputEnd)
        *outputIter++ = *inputIter++;


    return 0;
}