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

        virtual bool isOversize() const { return false; }

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

///////////////////////////////////////////////////////////////////////////////

class Book : public Publication
{
    public :
        Book() : Publication(), _numberOfPage(0) {}

        virtual void setData() override;
        virtual void getData() const override {
            Publication::getData();
            std::cout << ", number of page: " << _numberOfPage;
        }

        virtual bool isOversize() const override;

    private :
        int _numberOfPage;
};

void Book::setData() {
    Publication::setData();
    std::cout << "...number of page: ";
    std::cin >> _numberOfPage;
    std::cin.get();
}

bool Book::isOversize() const {
    if (_numberOfPage > 800) {
        std::cout << " Oversize! ";
        return true;
    }
    else
        return false;
}

///////////////////////////////////////////////////////////////////////////////

class Tape : public Publication
{
    public :
        Tape() : Publication(), _minute(0.0f) {}

        virtual void setData() override;
        virtual void getData() const override {
            Publication::getData();
            std::cout << ", minutes: " << _minute;
        }

        bool isOversize() const override;

    private :
        float _minute;
};

void Tape::setData() {
    Publication::setData();
    std::cout << "...minute: ";
    std::cin >> _minute;
    std::cin.get();
}

bool Tape::isOversize() const {
    if (_minute > 90) {
        std::cout << " Oversize! ";
        return true;
    }
    else
        return false;
}

///////////////////////////////////////////////////////////////////////////////

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
        publArray[i]->isOversize();
        std::cout << std::endl;
        delete publArray[i];
    }

    return 0;
}