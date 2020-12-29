#include <iostream>

struct point {
	short x;
	short y;
};

int main() {
	std::cout << "Enter coordinates of the point p1: ";
	point p1;
	std::cin >> p1.x >> p1.y;
	std::cout << "Enter coordinates of the point p2: ";
	point p2;
	std::cin >> p2.x >> p2.y;

	point p3;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	std::cout << "Coordinate of point p1 + p2 equal " << p3.x << ' ' << p3.y << std::endl;
   
	return 0;
}