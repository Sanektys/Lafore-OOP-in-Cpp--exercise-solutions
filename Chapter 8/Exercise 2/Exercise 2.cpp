#include <iostream>
#include <string>

class String
{
    public:
        String() { strcpy_s(string, ""); }
        String(char s[]) { strcpy_s(string, s); }

        void display() const { std::cout << string; }

        String operator+(String str) const;
        String operator+=(String str);

    private:
        static const int SIZE = 80;
        char string[SIZE];
};

String String::operator+(String str) const {
    String temp;
    if (strlen(string) + strlen(str.string) < SIZE) {
        strcpy_s(temp.string, string);
        strcat_s(temp.string, str.string);
    }
    else
        std::cout << "\nOut of range";
    
    return temp;
}

String String::operator+=(String str) {
    if (strlen(string) + strlen(str.string) < SIZE)
        strcat_s(string, str.string);
    else
        std::cout << "\nOut of range";

    return String(string);
}

int main() {
    String s1 = (char*)"\nMerry Cristmas ";
    String s2 = (char*)"and Happy New Year!";
    String s3;

    s1.display();
    s2.display();
    s3.display();

    s3 = s1 + s2;

    s3.display();
    std::cout << std::endl;

    s3 += s2;
    s1 = s2 += s2;

    s3.display();
    std::cout << std::endl;
    s1.display();
    std::cout << std::endl;

    return 0;
}