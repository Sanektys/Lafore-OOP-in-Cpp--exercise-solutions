#include <iostream>

struct Pair
{
    int x;
    int y;
};

class Stack
{
    public :
        Stack() : _top(-1), _stack() {}

        void push(int var) { _stack[++_top] = var; }
        int pop() { return _stack[_top--]; }

    protected :
        static const int MAX = 8;
        int _stack[MAX];
        int _top;
};

class Stack2 : private Stack
{
    public :
        Stack2() : Stack() {}

        void push(int var);
        int pop();
};

void Stack2::push(int var) {
    if (_top >= MAX - 1) {
        std::cout << "\nError: Stack is full!";
        return;
    }

    Stack::push(var);
}

int Stack2::pop() {
    if (_top < 0) {
        std::cout << "\nError: stack is empty! ";
        return 0;
    }

    Stack::pop();
}

class PairStack : private Stack2
{
    public :
        PairStack() : Stack2(), _pair() {}

        void push(Pair pair) {
            Stack2::push(pair.x);
            Stack2::push(pair.y);
        }
        Pair pop() {
            int y = Stack2::pop();
            int x = Stack2::pop();
            return { x, y };
        }

    private :
        Pair _pair;
};

void inline showPair(Pair pair);

int main() {
    Stack2 stack;

    stack.push(11);
    stack.push(22);
    stack.push(33);
    stack.push(44);

    std::cout << std::endl << stack.pop();
    std::cout << std::endl << stack.pop();
    std::cout << std::endl << stack.pop();
    std::cout << std::endl << stack.pop();
    std::cout << std::endl;

    PairStack pairStack;
    pairStack.push({ 10, 12 });
    pairStack.push({ 88, 20 });
    pairStack.push({ 64, 32 });
    pairStack.push({ 13, 7 });
    pairStack.push({ 5, 6 });

    std::cout << std::endl;
    showPair(pairStack.pop());
    showPair(pairStack.pop());
    showPair(pairStack.pop());
    showPair(pairStack.pop());
    showPair(pairStack.pop());

    return 0;
}

void inline showPair(Pair pair) {
    std::cout << pair.x << ", " << pair.y << std::endl;
}