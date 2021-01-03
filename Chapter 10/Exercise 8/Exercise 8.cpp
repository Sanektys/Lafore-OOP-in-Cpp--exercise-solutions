#include <iostream>

struct Link
{
    int data;
    Link* next;
};

class LinkList
{
    public :
        LinkList() : _first(nullptr) {}
        ~LinkList();

        void addItem(int data);
        void display() const;

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
        while (finiteElement) {
            if (finiteElement->next == nullptr)
                break;
            finiteElement = finiteElement->next;
        }
        Link* newLink = new Link;
        finiteElement->next = newLink;
        newLink->data = data;
        newLink->next = nullptr;
    }
}

void LinkList::display() const {
    Link* current = _first;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

int main() {
    LinkList link;

    link.addItem(11);
    link.addItem(22);
    link.addItem(33);
    link.addItem(44);
    link.addItem(55);
    link.addItem(66);

    link.display();

    return 0;
}