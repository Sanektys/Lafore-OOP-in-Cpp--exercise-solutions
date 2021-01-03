#include <iostream>
#include <string>

class Date
{
    public :
        Date() : _day(0), _month(0), _year(0)
        { };

        void setDate();
        void showDate() const {
            std::cout << _day << '/' << _month << '/' << _year;
        }

    private :
        short _day;
        short _month;
        short _year;
};

void Date::setDate() {
    std::cout << "Enter the required date:\n";
    do {
        std::cout << "...day: ";
        std::cin >> _day;
    } while (_day <= 0 || _day > 31);
    do {
        std::cout << "...month: ";
        std::cin >> _month;
    } while (_month <= 0 || _month > 12);
    do {
        std::cout << "...year: ";
        std::cin >> _year;
    } while (_year < 0 || _year > 99);
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
    getline(std::cin, _title);
    std::cout << "...price: ";
    std::cin >> _price;
    std::cin.get();
}

class Publication2 : public Publication
{
    public :
        Publication2() : Publication() {}

        void setData();
        void getData() const {
            Publication::getData();
            std::cout << ", publication date: ";
            _date.showDate();
        }

    private :
        Date _date;
};

void Publication2::setData() {
    Publication::setData();
    std::cout << "...publication data: ";
    _date.setDate();
    std::cin.get();
}

class Book : public Publication2
{
    public :
        Book() : Publication2(), _numberOfPage(0) {}

        void setData();
        void getData() const {
            Publication2::getData();
            std::cout << ", number of page: " << _numberOfPage;
        }

    private :
        int _numberOfPage;
};

void Book::setData() {
    Publication2::setData();
    std::cout << "...number of page: ";
    std::cin >> _numberOfPage;
    std::cin.get();
}

class Type : public Publication2
{
    public :
        Type() : Publication2(), _minute(0.0f) {}

        void setData();
        void getData() const {
            Publication2::getData();
            std::cout << ", minutes: " << _minute;
        }

    private :
        float _minute;
};

void Type::setData() {
    Publication2::setData();
    std::cout << "...minute: ";
    std::cin >> _minute;
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