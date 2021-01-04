#include <iostream>

#include "DoFile.h"


const int MAX = 1000;
int buff[MAX];

int main() {
    for (int i = 0; i < MAX; i++)
        buff[i] = i;

    DoFile* fileP = 0;
    try {
        fileP = new DoFile("Edata.dat");
        fileP->writeFile(buff, MAX);
    }
    catch (DoFile::Exeption& exept) {
        std::cerr << exept.message << std::endl;
    }
    
    for (int i = 0; i < MAX; i++)
        buff[i] = 0;
    fileP->resetPointer();

    try {
        fileP->readFile(buff, MAX);
    }
    catch (DoFile::Exeption& exept) {
        std::cerr << exept.message << std::endl;
    }
    delete fileP;
    fileP = nullptr;

    for (int i = 0; i < MAX; i++)
        if (buff[i] != i) {
            std::cerr << "Incorrect data\n";
            return 0;
        }
    std::cout << "Correct data";


    return 0;
}