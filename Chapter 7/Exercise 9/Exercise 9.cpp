#include <iostream>
#include <conio.h>

class Queue
{
    public :
        Queue() : _queue(), _head(-1), _tail(0), _currentSize(0) {}

        void put(int var);
        int get();
        int getSize() const { return SIZE; }

    private :
        static const int SIZE = 10;
        int _queue[SIZE];
        int _head;
        int _tail;
        int _currentSize;
};

void Queue::put(int var) {
    if (_currentSize == SIZE) {
        std::cout << "Queue is full!\n";
        return;
    }
    if (_head == SIZE - 1)
        _head = -1;
    _currentSize++;
    _queue[++_head] = var;
}

int Queue::get() {
    if (_currentSize == 0) {
        std::cout << "Queue is empty\n";
        return 0;
    }
    if (_tail == SIZE)
        _tail = 0;
    _currentSize--;
    return _queue[_tail++];
}

int main() {
    Queue que;

    std::cout << "Place an integer number in queue (press 'p'),\n"
                 "extract one number from the queue (press 'g') "
                 "or extract all numbers (press 'a').\n";
    std::cout << "(for exit press 'q')\n";
    char command;
    do {
        std::cout << "Enter command: ";
        command = _getche();
        std::cout << std::endl;
        switch (command) {
            case 'p' :
                std::cout << "Enter a number: ";
                int temp;
                std::cin >> temp;
                que.put(temp);
                break;
            case 'g' :
                std::cout << "Extracted: " << que.get() << std::endl;
                break;
            case 'a' :
                std::cout << "Queue: ";
                for (int i = 0; i < que.getSize(); i++)
                    std::cout << que.get() << "  ";
                std::cout << std::endl;
        }
    } while (command != 'q');

    return 0;
}