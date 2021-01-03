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
        LinkList(const LinkList& linkTwo) : _first(nullptr) {
            operator=(linkTwo);
        }
        ~LinkList();

        void addItem(int data);
        void display() const;

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

LinkList& LinkList::operator=(const LinkList& linkList) {
    Link* linkTwo = linkList._first;
    while (linkTwo) {
        addItem(linkTwo->data);
        linkTwo = linkTwo->next;
    }

    return *this;
}

int main() {
    LinkList* linkOne = new LinkList();

    linkOne->addItem(11);
    linkOne->addItem(22);
    linkOne->addItem(33);
    linkOne->addItem(44);
    linkOne->addItem(55);
    linkOne->addItem(66);

    linkOne->display();

    LinkList* linkTwo = new LinkList(*linkOne);
    linkTwo->addItem(77);
    linkTwo->addItem(88);
    delete linkOne;

    linkTwo->display();

    LinkList* linkThree = new LinkList();
    linkThree->addItem(99);
    linkThree->addItem(111);
    *linkThree = *linkTwo;

    delete linkTwo;
    linkThree->display();
    delete linkThree;

    return 0;
}