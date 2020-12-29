#include <iostream>
#include <conio.h>
#include <Windows.h>

class TollBooth
{
    public :
        TollBooth() : _countAuto(0), _totalIncome(0) {};

        void payingCar() {
            _countAuto++;
            _totalIncome += 0.5f;
        }

        void nopayCar() { _countAuto++; }

        void display() const {
            std::cout << "All cars driven by: " << _countAuto
                      << ", total proceeds: " << _totalIncome << " cents\n";
        }

    private :
        unsigned int _countAuto;
        double _totalIncome;
};

int main() {
    std::cout << "The program counts the number of cars that "
                 "passed through the post and how much they paid for "
                 "the journey\n";
    std::cout << "If a paid car has driven by, press Enter\n"
                 "Or if the car passed without payment, press Space\n"
                 "(press Esc for exit):\n";
    
    TollBooth tollBooth;
    bool isRun = true;
    do {
        switch (_getch()) {
            case VK_RETURN :
                tollBooth.payingCar();
                break;
            case VK_SPACE :
                tollBooth.nopayCar();
                break;
            case VK_ESCAPE :
                isRun = false;
                break;
        }
    } while (isRun);

    tollBooth.display();

    return 0;
}