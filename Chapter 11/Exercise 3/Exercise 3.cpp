#include <iostream>

class Distance
{
    public :
        Distance() : _feet(0), _inches(0.0f) {}
        Distance(float dist) {
            _feet = (int)dist;
            _inches = (dist - _feet) * 12.0f;
        }
        Distance(int fe, float in) : _feet(fe), _inches(in) {}

        void showDist() {
            std::cout << _feet << "\'-" << _inches << "\"";
        }

        friend Distance operator*(Distance, Distance);

    private :
        int _feet;
        float _inches;
};

Distance operator*(Distance distOne, Distance distTwo) {
    Distance temp;

    if (distOne._feet == 0 || distTwo._feet == 0)
        temp._feet = distOne._feet + distTwo._feet;
    else
        temp._feet = distOne._feet * distTwo._feet;
    
    if (distOne._inches == 0 || distTwo._inches == 0)
        temp._inches = distOne._inches + distTwo._inches;
    else
        temp._inches = distOne._inches * distTwo._inches;

    while (temp._inches >= 12.0f) {
        temp._feet++;
        temp._inches -= 12.0f;
    }
    
    return temp;
}

int main() {
    Distance distOne(22, 8.6);
    Distance distTwo;

    distTwo = 7.5 * distOne;
    distTwo.showDist();
    std::cout << std::endl;

    distOne = distTwo * 2;
    distOne.showDist();
    std::cout << std::endl;

    distOne = 7.5 * 2;
    distOne.showDist();
    std::cout << std::endl;

    return 0;
}