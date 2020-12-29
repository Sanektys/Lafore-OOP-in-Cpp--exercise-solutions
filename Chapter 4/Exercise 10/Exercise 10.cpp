#include <iostream>

struct Sterling
{
    int pounds;
    int shillings;
    int pence;
};

int main() {
    std::cout << "Enter the amount of money in the decimal pounds: ";
    float decPounds;
    std::cin >> decPounds;

    Sterling sterling = { 0, 0, 0 };
    sterling.pounds = static_cast<int>(decPounds);
    decPounds -= sterling.pounds;
    decPounds *= 2.4f * 100;
    while (static_cast<int>(decPounds) > 12) {
        sterling.shillings++;
        decPounds -= 12;
    }
    sterling.pence = static_cast<int>(decPounds);

    std::cout << "Equivalent in legacy form: " << sterling.pounds << '.'
              << sterling.shillings << '.' << sterling.pence << std::endl;

    return 0;
}