#include <iostream>


class String
{
    public:
        String() : string() { strcpy_s(string, ""); }
        String(char s[]) : string() {
            operator=(s);
        }

        class Exeption {
            public :
                Exeption() : message() {}
                Exeption(std::string mes) : message(mes) {}

            public :
                std::string message;
        };

        void display() const { std::cout << string; }

        String operator+(const String& str) const;
        String operator+=(const String& str);
        void operator=(const char str[]) {
            if (strlen(str) >= 80)
                throw Exeption("Entered string is too length!");
            strcpy_s(string, str);
        }

    private:
        static const int SIZE = 80;
        char string[SIZE];
};

String String::operator+(const String& str) const {
    String temp;
    if (strlen(string) + strlen(str.string) < SIZE) {
        strcpy_s(temp.string, string);
        strcat_s(temp.string, str.string);
    }
    else
        throw Exeption("Length of concatenation strings is too big!");
    
    return temp;
}

String String::operator+=(const String& str) {
    String temp;
    if (strlen(string) + strlen(str.string) < SIZE) {
        strcat_s(temp.string, string);
        strcat_s(temp.string, str.string);
        *this = temp;
    }
    else
        throw Exeption("Length of concatenation strings is too big!");

    return temp;
}

int main() {
    String s1;
    String s2;
    String s3;
    try {
        s1 = "\nMerry Cristmas ";
        s2 = "and Happy New Year!";
    }
    catch (String::Exeption& exept) {
        std::cout << exept.message << std::endl;
    }

    s1.display();
    s2.display();
    s3.display();

    try {
        s3 = s1 + s2;
    }
    catch (String::Exeption& exept) {
        std::cout << exept.message << std::endl;
    }

    s3.display();
    std::cout << std::endl;

    try {
        s3 += s2;
        s1 = s2 += s2;
    }
    catch (String::Exeption& exept) {
        std::cout << exept.message << std::endl;
    }

    s3.display();
    std::cout << std::endl;
    s1.display();
    std::cout << std::endl;

    try {
        s3 += s1;
    }
    catch (String::Exeption& exept) {
        std::cout << exept.message << std::endl;
    }

    s3.display();
    std::cout << std::endl;

    try {
        s1 = "Hello, my name is Ilya, and I newbie in programming..."
             "\nBut i hope i will be better =)";
    }
    catch (String::Exeption& exept) {
        std::cout << exept.message << std::endl;
    }


    return 0;
}