#include <iostream>

inline float circarea(float rad);

int main() {
    std::cout << "Enter radius of circle: ";
    float rad;
    std::cin >> rad;
    float area = circarea(rad);
    std::cout << "Area of circle equal: " << area << std::endl;

    return 0;
}

inline float circarea(float rad) {
    const float PI = 3.14159f;
    return PI * rad * rad;
}