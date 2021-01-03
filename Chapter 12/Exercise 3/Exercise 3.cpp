#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect number of arguments.\n"
                     "Argument must be one (full name "
                     "of the file being checked)\n";
        return 0;
    }

    std::ifstream inputFile;
    inputFile.open(argv[1], std::ios::binary);
    if (!inputFile.good()) {
        std::cout << argv[1] << " doesn't exist!\n";
        return 0;
    }

    inputFile.seekg(0, std::ios::end);

    //unsigned int byte = 0;
    //while (!inputFile.eof()) {
    //    inputFile.get();
    //    byte++;
    //}
    //byte--;

    std::cout << "Size of " << argv[1] << " is " << inputFile.tellg() << " bytes\n";

    return 0;
}