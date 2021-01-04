#include <iostream>
#include <conio.h>

#include "Queue.hpp"


template <typename T>
void setup(Queue<T>&);

template <typename T>
void display(Queue<T>&);

int main() {
    std::cout << "The program saves the selected data type in a queue\n"
                 "of up to ten elements.\n";
    char answer = '\0';
    do {
        std::cout << "Choose a data type\n"
            "(i - integer, f - float, d - double, c - char): ";
        char type = '\0';
        while (true) {
            std::cin >> type;
            if (type != 'i' && type != 'f' && type != 'd' && type != 'c')
                std::cin.clear(std::ios::failbit);
            if (!std::cin.good()) {
                std::cin.clear();
                std::cout << "Incorrect type, try again(i, f, d, c): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        switch (type) {
            case 'i' : {
                Queue<int> queue;
                setup(queue);
                display(queue);
                break;
            }
        case 'f' : {
                Queue<float> queue;
                setup(queue);
                display(queue);
                break;
            }
        case 'd' : {
                Queue<double> queue;
                setup(queue);
                display(queue);
                break;
            }
        case 'c' : {
                Queue<char> queue;
                setup(queue);
                display(queue);
                break;
            }
        }


        while (true) {
            std::cout << "Want to enter another numbers(y/n)? ";
            std::cin >> answer;
            if (answer != 'n' && answer != 'y')
                std::cin.clear(std::ios::failbit);
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        std::cout << std::endl;
    } while (answer != 'n');


    return 0;
}

template <typename T>
void setup(Queue<T>& queue) {
    std::cout << "Enter data or press ENTER two times for exit\n";
    std::cin.unsetf(std::ios::skipws);
    int i = 0;
    while (true) {
        i++;
        std::cout << i << ": ";
        T data = '\0';
        std::cin >> data;
        if (typeid(queue) == typeid(Queue<char>))
            if (data == '\n') {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        if (!std::cin.good()) {
            std::cin.clear();
            if (typeid(queue) != typeid(Queue<char>))
                if (std::cin.peek() == '\n') {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
            i--;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try {
            queue.put(data);
        }
        catch (typename Queue<T>::FullExept) {
            std::cout << "Input element " << i << " failure. Queue is full\n";
            break;
        }
    }
    std::cin.setf(std::ios::skipws);
}

template <typename T>
void display(Queue<T>& queue) {
    std::cout << "Complete or elemental data output(comp/elem)? ";
    char answer[6] = {};
    while (true) {
        std::cin >> answer;
        if (strcmp(answer, "comp") && strcmp(answer, "elem"))
            std::cin.clear(std::ios::failbit);
        if (!std::cin.good()) {
            std::cin.clear();
            std::cout << "Try enter again (comp/elem): ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    if (!strcmp(answer, "comp")) {
        const int size = queue.getSize();
        for (int i = 1; i <= size; i++)
            std::cout << queue.get() << ", ";
        std::cout << std::endl;
    }
    else if (!strcmp(answer, "elem")) {
        std::cout << "Press SPACE for output one element or any another key for exit:\n";
        char ans = '\0';
        while (true) {
            ans = _getch();
            if (ans == ' ') {
                try {
                    std::cout << queue.get() << ", ";
                }
                catch (typename Queue<T>::EmptyExept) {
                    std::cerr << "Queue is empty!";
                    break;
                }
            }
            else
                break;
        }
        std::cout << std::endl;
    }
}