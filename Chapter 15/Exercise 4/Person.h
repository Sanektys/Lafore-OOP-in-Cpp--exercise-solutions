#pragma once

#include <iostream>
#include <string>


class Person
{
    public :
        Person() : _firstName(), _secondName(), _phoneNumber(0ull) {}
        Person(std::string first, std::string second, unsigned long long phone)
              : _firstName(first), _secondName(second), _phoneNumber(phone) {}


        void setPerson();
        void display() const {
            std::cout << std::endl << _firstName << "  " << _secondName
                       << ",\tTelephone:  " << _phoneNumber;
        }
        int getPhone() const { return _phoneNumber; }

        bool operator<(const Person& pers) const {
            if (this->_firstName == pers._firstName)
                return (this->_secondName < pers._secondName) ? true : false;
            return (this->_firstName < pers._firstName) ? true : false;
        }
        bool operator==(const Person& pers) const {
            return (this->_firstName == pers._firstName &&
                    this->_secondName == pers._secondName) ? true : false;
        }
        friend std::istream& operator>>(std::istream&, Person&);
        friend std::istream& operator>>(std::istream&, Person*);

    private :
        std::string _firstName;
        std::string _secondName;
        unsigned long long _phoneNumber;
};