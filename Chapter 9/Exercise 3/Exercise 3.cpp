﻿#include <iostream>
#include <string>

class Sales
{
    public :
        Sales() : _totalSales() {}

        void setData();
        void getData() const;

    private :
        static const short _MONTH = 3;
        float _totalSales[_MONTH];
};

void Sales::setData() {
    std::cout << "Total sales for each of the last three months:\n";
    for (int i = 0; i < _MONTH; i++) {
        switch (i + 1) {
            case 1 :
                std::cout << "...current month: ";
                break;
            case 2 :
                std::cout << "...second month: ";
                break;
            case 3 :
                std::cout << "...third month: ";
                break;
        }
        std::cin >> _totalSales[i];
    }
}

void Sales::getData() const {
    std::cout << "Total sales for: ";
    for (int i = 0; i < _MONTH; i++) {
        switch (i + 1) {
            case 1 :
                std::cout << "current month - $";
                break;
            case 2 :
                std::cout << ", second month - $";
                break;
            case 3 :
                std::cout << ", third month - $";
                break;
        }
        std::cout << _totalSales[i];
    }
}

class Publication
{
    public :
        Publication() : _title("null"), _price(0.0f) {}

        void setData();
        void getData() const {
            std::cout << "Title: \"" << _title << "\", price - $" << _price;
        }

    private :
        std::string _title;
        float _price;
};

void Publication::setData() {
    std::cout << "Enter the information about publication:\n";
    std::cout << "...title: ";
    getline(std::cin, _title, '.');
    std::cout << "...price: ";
    std::cin >> _price;
    std::cin.get();
}

class Book : public Publication, public Sales
{
    public :
        Book() : Publication(), Sales(), _numberOfPage(0) {}

        void setData();
        void getData() const {
            Publication::getData();
            std::cout << ", number of page: " << _numberOfPage << ". ";
            Sales::getData();
        }

    private :
        int _numberOfPage;
};

void Book::setData() {
    Publication::setData();
    std::cout << "...number of page: ";
    std::cin >> _numberOfPage;
    Sales::setData();
    std::cin.get();
}

class Type : public Publication, public Sales
{
    public :
        Type() : Publication(), Sales(), _minute(0.0f) {}

        void setData();
        void getData() const {
            Publication::getData();
            std::cout << ", minutes: " << _minute << ". ";
            Sales::getData();
        }

    private :
        float _minute;
};

void Type::setData() {
    Publication::setData();
    std::cout << "...minute: ";
    std::cin >> _minute;
    Sales::setData();
    std::cin.get();
}

int main() {
    Type type;
    type.setData();

    Book book;
    book.setData();

    std::cout << std::endl;
    type.getData();
    std::cout << std::endl;
    book.getData();
    std::cout << std::endl;

    return 0;
}