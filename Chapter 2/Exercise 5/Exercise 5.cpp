#include <iostream>

int main() {
	std::cout << "Enter one character\n";
	char symbol;
	std::cin >> symbol;
	std::cout << islower(symbol);

	return 0;
}