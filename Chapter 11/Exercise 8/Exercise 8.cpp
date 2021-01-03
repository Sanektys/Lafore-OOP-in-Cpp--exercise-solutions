#include <iostream>

const int LEN = 80;
const int MAX = 20;

// Интерфейс (нет данных, а методы чистые виртуальные)
class Token
{
    public :
        virtual ~Token() {}

        virtual float getNumber() const = 0;
        virtual char getOperator() const = 0;
        virtual bool isOperator() const = 0;
        virtual float getMultiplier() const { return 0.0f; }

    private :
};

///////////////////////////////////////////////////////////////////////////////

class Operator : public Token
{
    public :
        Operator(char op) : _operator(op) {}
        ~Operator() override {}
        
        char getOperator() const override { return _operator; }
        float getNumber() const final { return 0.0f; }
        bool isOperator() const override { return true; }

    private :
        char _operator;
};

///////////////////////////////////////////////////////////////////////////////

class Number : public Token
{
    public :
        Number(float num, float mul = 10.0f) : _number(num), _multiplier(mul) {}
        ~Number() override {}

        float getNumber() const override { return _number; }
        char getOperator() const final { return ' '; }
        bool isOperator() const override { return false; }
        float getMultiplier() const override { return _multiplier; }

        void addNumber(float number, bool period = false);
        void setMultiplier(float mul) { _multiplier = mul; }

    private :
        float _number;
        float _multiplier;
};

void Number::addNumber(float number, bool period) {
    if (period) {
        _multiplier = 0.1f;
        return;
    }

    if (_multiplier >= 1) {   
        _number *= _multiplier;
        _number += number;
        _multiplier *= 10.0f;
    }
    else {
        _number += number * _multiplier;
        _multiplier *= 0.1f;
    }
}

///////////////////////////////////////////////////////////////////////////////

class Stack
{
    public :
        Stack() : _top(0), _token() {}
        ~Stack();

        void push(float num, bool period = false);
        void push(char op) {
            if (_token[_top + 1] != nullptr)
                delete _token[_top + 1];
            _token[++_top] = new Operator(op);
        }
        Token* pop() {
            return _token[_top--];
        }

        int getTop() const {
            return _top;
        }

    private :
        Token* _token[MAX];
        int _top;
};

Stack::~Stack() {
    for (int i = 0; i < MAX; i++)
        if (_token[i] != nullptr) {
            delete _token[i];
            _token[i] = nullptr;
        }
}

void Stack::push(float num, bool period) {
    if (_top == 0 || _token[_top]->isOperator()) {
        if (_token[_top + 1] != nullptr)
            delete _token[_top + 1];
        _token[++_top] = new Number(num);
    }
    else {
        Number number = _token[_top]->getNumber();
        number.setMultiplier(_token[_top]->getMultiplier());
            
        if (period)
            number.addNumber(0.0f, true);
        else
            number.addNumber(num);
            
        delete _token[_top];
        _token[_top] = new Number(number);
    }
}

///////////////////////////////////////////////////////////////////////////////

class Express
{
    public :
        Express(char* pointer) : _string(pointer) {
            _length = strlen(_string);
        }

        void parse();
        float solve();

    private :
        Stack _stack;
        char* _string;
        int _length;
};

void Express::parse() {
    char ch;
    float lastValue;
    char lastOperator;

    for (int i = 0; i < _length; i++) {
        ch = _string[i];

        if (ch == ' ')
            continue;

        if (ch >= '0' && ch <= '9')
            _stack.push(float(ch - '0'));
        else if (ch == '.')
            _stack.push(0.0f, true);
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (_stack.getTop() == 1)
                    _stack.push(ch);
                else {
                    lastValue = _stack.pop()->getNumber();
                    lastOperator = _stack.pop()->getOperator();

                    if ((ch == '*' || ch == '/')
                        && (lastOperator == '+' || lastOperator == '-')) {
                        _stack.push(lastOperator);
                        _stack.push(lastValue);
                    }
                    else {
                        switch (lastOperator) {
                            case '+' :
                                _stack.push(_stack.pop()->getNumber() + lastValue);
                                break;
                            case '-' :
                                _stack.push(_stack.pop()->getNumber() - lastValue);
                                break;
                            case '*' :
                                _stack.push(_stack.pop()->getNumber() * lastValue);
                                break;
                            case '/' :
                                _stack.push(_stack.pop()->getNumber() / lastValue);
                                break;
                            default :
                                std::cout << "\nUnknown operator";
                        }
                    }
                    _stack.push(ch);
                }
            }
            else {
                std::cout << "\nUnknown symbol";
                break;
            }
    }
}

float Express::solve() {
    float lastValue;
    while (_stack.getTop() > 1) {
        lastValue = _stack.pop()->getNumber();

        switch (_stack.pop()->getOperator()) {
            case '+' :
                _stack.push(_stack.pop()->getNumber() + lastValue);
                break;
            case '-' :
                _stack.push(_stack.pop()->getNumber() - lastValue);
                break;
            case '*' :
                _stack.push(_stack.pop()->getNumber() * lastValue);
                break;
            case '/' :
                _stack.push(_stack.pop()->getNumber() / lastValue);
                break;
            default :
                std::cout << "\nUnknow operator";
        }
    }
    return _stack.pop()->getNumber();
}

///////////////////////////////////////////////////////////////////////////////

int main() {
    char answer;
    char string[LEN];

    std::cout << "Enter arithmetic expression in form 2+3*4/2-2"
                 "\nNumbers must consist of one digit"
                 "\nDon't use space and brackets\n";

    do {
        std::cout << "\nExpression: ";
        std::cin.get(string, LEN);
        Express* express = new Express(string);
        express->parse();
        std::cout << "\nResult: " << express->solve();
        delete express;
        std::cout << "\nEnter another expression(y/n)? ";
        std::cin >> answer;
        std::cin.get();
    } while (answer == 'y');
    

    return 0;
}