#include <iostream>

class String
{
    public :
        String() : _string() {}
        String(char str[]) { strcpy(_string, str); }

        void display() const { std::cout << _string; }
        operator char*() { return _string; }

    protected :
        static const int _SIZE = 80;
        char _string[_SIZE];
};

class Pstring : public String
{
    public :
        Pstring() : String() {}
        Pstring(char str[]);

    private :
};

Pstring::Pstring(char str[]) {
    if (strlen(str) >= _SIZE - 1)
        strncpy(_string, str, _SIZE - 1);
    else
        strcpy(_string, str);
}

class Pstring2 : public Pstring
{
    public :
        Pstring2() : Pstring() {}
        Pstring2(char str[]) : Pstring(str) {}

        Pstring2& left(Pstring2& stringOne, int n);
        Pstring2& middle(Pstring2& stringOne, int start, int n);
        Pstring2& right(Pstring2& stringOne, int n);

    private :
        void _clear() {
            for (int i = 0; i < _SIZE; i++)
                _string[i] = ' ';
        }
};

Pstring2& Pstring2::left(Pstring2& stringOne, int n) {
    if (n <= 0)
        return stringOne;
    int lenght = strlen(stringOne._string);
    if (n > lenght)
        n = lenght;

    _clear();
    for (int i = 0; i < n; i++) {
        _string[i] = stringOne._string[i];
    }
    _string[n] = '\0';

    return stringOne;
}

Pstring2& Pstring2::middle(Pstring2& stringOne, int start, int n) {
    if (n <= 0 || start < 0)
        return stringOne;
    int lenght = strlen(stringOne._string);
    if (start > lenght)
        return stringOne;
    if (start + n > lenght + 1)
        n = lenght - start + 1;

    _clear();
    for (int i = start - 1, j = 0; i < n + start - 1; i++, j++) {
        _string[j] = stringOne._string[i];
    }
    _string[n] = '\0';

    return stringOne;
}

Pstring2& Pstring2::right(Pstring2& stringOne, int n) {
    if (n <= 0)
        return stringOne;
    int lenght = strlen(stringOne._string);
    if (n > lenght)
        n = lenght;

    _clear();
    for (int i = lenght - n, j = 0; i < lenght; i++, j++) {
        _string[j] = stringOne._string[i];
    }
    _string[n] = '\0';

    return stringOne;
}

int main() {
    Pstring2 stringOne = (char*)"Test message";
    Pstring2 stringTwo;
    Pstring2 stringThree = (char*)"Hello!";

    stringTwo.left(stringOne, 4) = stringTwo;
    stringOne.display();
    std::cout << std::endl;
    stringTwo.display();
    std::cout << std::endl << std::endl;

    stringTwo.left(stringThree, 5) = stringOne;
    stringTwo.display();
    std::cout << std::endl;
    stringThree.display();
    std::cout << std::endl << std::endl;

    stringOne = (char*)"and Happy New Year";
    stringTwo = (char*)"Merry Cristmas";

    stringThree.middle(stringOne, 5, 6);
    std::cout << stringThree;
    stringThree.right(stringTwo, 8);
    std::cout << stringThree << std::endl;

    return 0;
}