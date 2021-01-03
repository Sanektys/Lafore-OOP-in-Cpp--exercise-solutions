#include <iostream>

class String
{
    public :
        String(const char* str) {
            int length = strlen(str);
            _string = new char[length + 1];
            strcpy(_string, str);
        }
        ~String() {
            std::cout << "Deleting string.\n";
            delete[] _string;
        }

        void upit();

        void display() const {
            std::cout << _string << std::endl;
        }

    private :
        char* _string;
};

void String::upit() {
    int length = strlen(_string);
    for (int i = 0; i < length; i++)
        *(_string + i) = toupper(*(_string + i));
}

int main() {
    String string = "I don't want to set the world on fire...";
    std::cout << "string = ";
    string.display();
    
    string.upit();
    string.display();

    return 0;
}