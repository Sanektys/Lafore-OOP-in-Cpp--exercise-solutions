#include <iostream>
#include <fstream>

struct Link
{
    int data;
    Link* next;
};

class LinkList
{
    public :
        LinkList() : _first(nullptr) {}
        LinkList(const LinkList& linkTwo) : _first(nullptr) {
            operator=(linkTwo);
        }
        ~LinkList();

        void addItem(int data);
        void addItem();
        void display() const;

        void writeInFile() const;
        void readFromFile();

        LinkList& operator=(const LinkList& linkList);

    private :
        Link* _first;
};

LinkList::~LinkList() {
    Link* current = _first;
    while (current) {
        std::cout << "delete " << current->data << std::endl;
        Link* temp = current->next;
        delete current;
        current = temp;
    }
    std::cout << "deleting complete.\n";
}

void LinkList::addItem(int data) {
    if (_first == nullptr) {
        Link* newLink = new Link;
        newLink->data = data;
        newLink->next = nullptr;
        _first = newLink;
    }
    else {
        Link* finiteElement = _first;
        while (finiteElement->next)
            finiteElement = finiteElement->next;
        Link* newLink = new Link;
        finiteElement->next = newLink;
        newLink->data = data;
        newLink->next = nullptr;
    }
}

void LinkList::addItem() {
    std::cout << "Enter a integer number: ";
    int number;
    std::cin.unsetf(std::ios::skipws);
    while (true) {
        std::cin >> number;
        if (!std::cin.good()) {
            std::cout << "Incorrect entered number. Try again: ";
            std::cin.clear();
            std::cin.ignore(11, '\n');
            continue;
        }
        else {
            std::cin.ignore(11, '\n');
            break;
        }
    }
    std::cin.setf(std::ios::skipws);
    addItem(number);
}

void LinkList::display() const {
    Link* current = _first;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

LinkList& LinkList::operator=(const LinkList& linkList) {
    Link* linkTwo = linkList._first;
    while (linkTwo) {
        addItem(linkTwo->data);
        linkTwo = linkTwo->next;
    }

    return *this;
}

void LinkList::writeInFile() const {
    std::ofstream outputFile;
    outputFile.open("Link.dat", std::ios::binary | std::ios::trunc);
    if (outputFile.good()) {
        Link* current = _first;
        while (current) {
            outputFile.write((char*)&current->data, sizeof(current->data));
            current = current->next;
            if (!outputFile.good()) {
                std::cerr << "Writing file error!\n";
                break;
            }
        }
    }
}

void LinkList::readFromFile() {
    std::ifstream inputFile;
    inputFile.open("Link.dat", std::ios::binary);
    if (inputFile.good()) {
        Link* current = _first;
        Link* previous = nullptr;
        while (current) {
            inputFile.read((char*)&current->data, sizeof(current->data));
            if (inputFile.eof())
                break;
            if (inputFile.fail()) {
                std::cerr << "Reading file error!\n";
                break;
            }
            previous = current;
            current = current->next;
        }

        if (previous && current) {
            previous->next = nullptr;
            previous = current;
            while (previous) {
                current = previous->next;
                delete previous;
                previous = current;
            }
        }

        if (!current && !inputFile.eof()) {
            Link temp;
            while (true) {
                inputFile.read((char*)&temp.data, sizeof(Link::data));
                if (inputFile.eof())
                    break;
                addItem(temp.data);
            }
        }
    }
}

int main() {
    LinkList* linkOne = new LinkList();

    char answer;
    do {
        std::cout << "\nChoose one of four options for the program:"
                     "\nadd - add an element to the list"
                     "\ndis - display the entire list"
                     "\nwri - write the list to a file"
                     "\nrea - read the list from a file"
                     "\nEnter (add/dis/wri/rea): ";
        char choose[5];
        std::cin.unsetf(std::ios::skipws);        
        while (true) {
            std::cin.get(choose, 5);
            bool conditionTwo = _stricmp(choose, "add") &&
                                _stricmp(choose, "dis") &&
                                _stricmp(choose, "wri") &&
                                _stricmp(choose, "rea");
            if (!std::cin.good() || conditionTwo) {
                std::cout << "Incorrect enter, try again (add/dis/wri/rea): ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        switch (choose[0]) {
            case 'a' :
                linkOne->addItem();
                break;
            case 'd' :
                linkOne->display();
                break;
            case 'w' :
                linkOne->writeInFile();
                break;
            case 'r' :
                linkOne->readFromFile();
                break;
            default :
                std::cout << "Unknow command\n";
        }
        
        while (true) {
            std::cout << "Enter another command(y/n)? ";
            std::cin >> answer;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if (answer != 'n' && answer != 'y') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter ONLY \"y\" or \"n\"\n";
                continue;
            }
            else {
                std::cin.ignore(2, '\n');
                break;
            }
        }
        std::cin.setf(std::ios::skipws);
    } while (answer != 'n');

    return 0;
}