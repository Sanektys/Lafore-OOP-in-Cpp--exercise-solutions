#include <iostream>

struct Distance
{
    int feet;
    float inches;
};

struct Volume
{
    Distance width;
    Distance length;
    Distance height;
};

int main() {
    Volume volume = { {12, 3.25f}, {20, 4.0f}, {6, 1.75f} };

    float w = volume.width.feet + volume.width.inches / 12;
    float l = volume.length.feet + volume.length.inches / 12;
    float h = volume.height.feet + volume.height.inches / 12;

    float vol = w * l * h;
    std::cout << "Volume equal: " << vol << std::endl;

    return 0;
}