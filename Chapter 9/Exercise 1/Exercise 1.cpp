#include <iostream>
#include <string>

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

class Book : public Publication
{
    public :
        Book() : Publication(), _numberOfPage(0) {}

        void setData();
        void getData() const {
            Publication::getData();
            std::cout << ", number of page: " << _numberOfPage;
        }

    private :
        int _numberOfPage;
};

void Book::setData() {
    Publication::setData();
    std::cout << "...number of page: ";
    std::cin >> _numberOfPage;
    std::cin.get();
}

class Type : public Publication
{
    public :
        Type() : Publication(), _minute(0.0f) {}

        void setData();
        void getData() const {
            Publication::getData();
            std::cout << ", minutes: " << _minute;
        }

    private :
        float _minute;
};

void Type::setData() {
    Publication::setData();
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