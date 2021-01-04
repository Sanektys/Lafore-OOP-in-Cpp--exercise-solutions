#include "DistanceOld.h"


DistanceOld::DistanceOld(int feet, float inches) {
	if (feet < -999 || feet > 999)
		throw Exeption("Feets must be in range from -999 to 999", inches, feet);
	if (inches < 0.0f || inches >= 12.0f)
		throw Exeption("Inches must be between 0.0 and 11.99", inches);
	_feet = feet;
	_inches = inches;
}

void DistanceOld::setDist() {
	std::string inputString;

	std::cout << "Enter feets: ";
	std::cin.unsetf(std::ios::skipws);
	std::cin >> inputString;
	bool thisFeet = false;
	if (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		throw Exeption("Incorrect entered feets");
	}
	try {
		thisFeet = isFeet(inputString);
	}
	catch (Exeption& exept) {
		std::cout << exept.message;
		if (exept.feet != 0)
			std::cout << " you enter " << exept.feet << " feets";
		std::cout << std::endl;

		std::cin.ignore(10, '\n');
		throw Exeption();
	}
	if (isFeet(inputString)) {
		std::cin.ignore(10, '\n');
		_feet = atoi(inputString.c_str());
	}

	std::cout << "Enter inches: ";
	std::cin.unsetf(std::ios::skipws);
	std::cin >> _inches;	
	if (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		throw Exeption("Incorrect entered inches");
	}
	else if (_inches >= 12.0f || _inches < 0.0f) {
		std::cin.ignore(10, '\n');
		throw Exeption("Inches must be between 0.0 and 11.99", _inches);		
	}
	else
		std::cin.ignore(10, '\n');
}


int isFeet(std::string string) {
	int stringLength = string.size();
	if (stringLength == 0 || stringLength > 5)
		throw Exeption("Zero or too many characters in feets");
	for (int i = 0; i < stringLength; i++)
		if ((string[i] < '0' || string[i] > '9') && string[i] != '-')
			throw Exeption("Wrong characters in feets, use numbers and minus");
	double n = atof(string.c_str());
	if (n < -999.0 || n > 999.0)
		throw Exeption("Feets must be in range from -999 to 999", 0.0f, (int)n);
	return 1;
}