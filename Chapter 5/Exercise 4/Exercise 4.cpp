#include <iostream>

struct Distance
{
    int feet;
    float inches;
};

Distance largerDistance(Distance dist1, Distance dist2);

int main() {
    std::cout << "The program indicates the greater importance "
                 "of two English measures\n";
    std::cout << "Enter the first value:\n";
    Distance dist1;
    std::cout << "Enter the number of feet: ";
    std::cin >> dist1.feet;
    std::cout << "Enter the number of inches: ";
    std::cin >> dist1.inches;

    std::cout << "Enter the second value:\n";
    Distance dist2;
    std::cout << "Enter the number of feet: ";
    std::cin >> dist2.feet;
    std::cout << "Enter the number of inches: ";
    std::cin >> dist2.inches;

    Distance result = largerDistance(dist1, dist2);
    std::cout << "The greater of the two values is - "
              << result.feet << "\'-" << result.inches << "\"\n";
    
    return 0;
}

Distance largerDistance(Distance dist1, Distance dist2) {
    float inchesDist1 = dist1.feet * 12 + dist1.inches;
    float inchesDist2 = dist2.feet * 12 + dist2.inches;

    if (inchesDist1 > inchesDist2)
        return dist1;
    else
        return dist2;
}