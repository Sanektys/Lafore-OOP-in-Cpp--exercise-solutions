#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "\nEntered wrong amount of arguments!\n"
                     "In addition to the program directory, "
                     "enter the name of the file from where\n"
                     "to copy and the name of the file to "
                     "which to copy.\n";
        return 0;
    }

    std::ifstream inputFile;
    std::ofstream outputFile;

    inputFile.open(argv[2]);
    if (!inputFile.good()) {
        std::cerr << argv[2] << " doesn't exist!\n";
        return 0;
    }
    inputFile.close();

    inputFile.open(argv[1], std::ios::binary);
    if (!inputFile.good()) {
        std::cerr << argv[1] << " doesn't exist!\n";
        return 0;
    }
    outputFile.open(argv[2], std::ios::binary | std::ios::trunc);
    

    outputFile << inputFile.rdbuf();

    return 0;
}