#include <iostream>

#include "DoFile.h"


DoFile::DoFile() {
	_file.open("Edata.dat", std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
	if (!_file.good())
		throw Exeption("Open file failure");
}

DoFile::DoFile(const char fileName[]) {
    _file.open(fileName, std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
    if (!_file.good()) {
        std::string message;
        message += "Open ";
        message += fileName;
        message += " failure";
        throw Exeption(message);
    }
}

void DoFile::readFile(int array[], int size) {
    std::cout << "Read in process...\n";
    _file.read(reinterpret_cast<char*>(array), (long long)size * sizeof(int));
    if (!_file.good())
        throw Exeption("Failure during read file");
}

void DoFile::writeFile(int array[], int size) {
    std::cout << "Record in process...\n";
    _file.write(reinterpret_cast<char*>(array), (long long)size * sizeof(int));
    if (!_file.good())
        throw Exeption("Failure during write file");
}