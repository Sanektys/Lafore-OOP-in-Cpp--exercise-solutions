#pragma once

#include "Person.h"


class ComparePersons
{
    public :
        bool operator()(const Person* pointerOne, const Person* pointerTwo) const {
            return *pointerOne < *pointerTwo;
        }
};

