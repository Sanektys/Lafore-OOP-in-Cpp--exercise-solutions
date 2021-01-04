#pragma once

#include <iostream>


class Exeption
{
    public:
        Exeption() : feet(0), inches(0.0f), message() {}
        Exeption(std::string message, float inches = 0.0f, int feet = 0) : feet(feet), inches(inches),
        message(message) {}

    public:
        int feet;
        float inches;
        std::string message;
};

class DistanceOld
{
    public :
        DistanceOld() : _feet(0), _inches(0.0f) {}
        DistanceOld(int, float);

        class Exeption exeption;

        void showDist() const {
            std::cout << _feet << "'-" << _inches << '"';
        }
        void setDist();

    private :
        int _feet;
        float _inches;
};


int isFeet(std::string);