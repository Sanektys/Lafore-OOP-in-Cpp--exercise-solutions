#include <iostream>

struct Sterling
{
    int pounds;
    int shillings;
    int pence;
};

Sterling inputSterling();
Sterling sumOfSterling(Sterling summ1, Sterling summ2);
inline void outputSterling(Sterling sterling);

int main() {
    std::cout << "The program adds up two amounts in sterling\n";
    
    std::cout << "Enter first value...\n";
    Sterling firstSum = inputSterling();
    outputSterling(firstSum);

    std::cout << "Enter second value...\n";
    Sterling secondSum = inputSterling();
    outputSterling(secondSum);

    std::cout << "Total amount - ";
    outputSterling(sumOfSterling(firstSum, secondSum));

    return 0;
}

Sterling inputSterling() {
    Sterling sterling = { 0, 0, 0 };
    std::cout << "Enter the amount in sterling...\n";

    std::cout << "Enter pounds: ";
    std::cin >> sterling.pounds;

    bool incorrect = false;
    do {
        std::cout << "Enter shillings (not exceeding 20): ";
        std::cin >> sterling.shillings;
        incorrect = sterling.shillings < 0 || sterling.shillings > 20;
        if (incorrect)
            std::cout << "Wrong amount in shillings\n";
    } while (incorrect);

    do {
        std::cout << "Enter pence (not exceeding 12): ";
        std::cin >> sterling.pence;
        incorrect = sterling.pence < 0 || sterling.pence > 12;
        if (incorrect)
            std::cout << "Wrong amount in pence\n";
    } while (incorrect);

    return sterling;
}

Sterling sumOfSterling(Sterling summ1, Sterling summ2) {
    int totalPence1 = summ1.pounds * 240 + summ1.shillings * 12 + summ1.pence;
    int totalPence2 = summ2.pounds * 240 + summ2.shillings * 12 + summ2.pence;

    int totalPence = totalPence1 + totalPence2;
    Sterling sterling = { 0, 0, 0 };

    while (totalPence >= 240) {
        sterling.pounds++;
        totalPence -= 240;
    }
    while (totalPence >= 12) {
        sterling.shillings++;
        totalPence -= 12;
    }
    sterling.pence = totalPence;

    return sterling;
}

inline void outputSterling(Sterling sterling) {
    std::cout << "Money amount is equal "
              << sterling.pounds << '.' << sterling.shillings
              << '.' << sterling.pence << std::endl;
}