#include <iostream>
#include <string>

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

int main() {
    Pstring string;
    char arrayChar[100];
    for (int i = 0; i < 79; i++) {
        int letter = i / 10 + 1;
        switch (letter) {
            case 1 :
                arrayChar[i] = 'A';
                break;
            case 2:
                arrayChar[i] = 'B';
                break;
            case 3:
                arrayChar[i] = 'C';
                break;
            case 4:
                arrayChar[i] = 'D';
                break;
            case 5:
                arrayChar[i] = 'E';
                break;
            case 6:
                arrayChar[i] = 'F';
                break;
            case 7:
                arrayChar[i] = 'G';
                break;
            case 8:
                arrayChar[i] = 'H';
                break;
            case 9:
                arrayChar[i] = 'I';
                break;
        }
    }
    arrayChar[79] = '\0';
    string = arrayChar;
    string.display();
    std::cout << std::endl;

    arrayChar[79] = '@';
    arrayChar[80] = '\0';
    string = arrayChar;
    string.display();
    std::cout << std::endl;

    arrayChar[80] = '&';
    arrayChar[81] = '\0';
    string = arrayChar;
    string.display();
    std::cout << std::endl;

    return 0;
}