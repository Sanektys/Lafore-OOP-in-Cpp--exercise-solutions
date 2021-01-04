#pragma once

#include <fstream>


class DoFile
{
    public :
        DoFile();
        DoFile(const char[]);
        ~DoFile() { _file.close(); }

        class Exeption {
            public :
                Exeption() : message() {}
                Exeption(std::string mes) : message(mes) {}

            public :
                std::string message;
        };

        void readFile(int[], int);
        void writeFile(int[], int);
        void resetPointer() { _file.seekg(0, std::ios::beg); }

    private :
        std::fstream _file;
};

