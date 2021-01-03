#include <iostream>
#include <string>

class Publication
{
    public :
        Publication() : _title("null"), _price(0.0f) {}

        virtual void setData();
        virtual void getData() const {
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

class Tape : public Publication
{
    public :
        Tape() : Publication(), _minute(0.0f) {}

        void setData();
        void getData() const {
            Publication::getData();
            std::cout << ", minutes: " << _minute;
        }

    private :
        float _minute;
};

void Tape::setData() {
    Publication::setData();
    std::cout << "...minute: ";
    std::cin >> _minute;
    std::cin.get();
}

int main() {
    Publication* publArray[10];

    std::cout << "Enter data on books or tapes, "
                 "but not more than ten in total.\n";
    int count = 0;
    std::string type;
    char choise = 'y';
    
    do {
        std::cout << "Enter a book or tape? ";
        getline(std::cin, type);

        if (type == "book")
            publArray[count++] = new Book;
        else if (type == "tape")
            publArray[count++] = new Tape;
        else {
            std::cout << "Incorrect type!\n";
            continue;
        }

        publArray[count - 1]->setData();

        std::cout << "Enter another publication(y/n)? ";
        std::cin >> choise;
        std::cin.get();
    } while (choise == 'y' && count < 10);

    std::cout << "You entered following publications:\n";

    for (int i = 0; i < count; i++) {
        publArray[i]->getData();
        std::cout << std::endl;
        delete publArray[i];
    }

    return 0;
}