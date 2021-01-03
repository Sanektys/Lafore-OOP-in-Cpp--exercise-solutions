#include "pch.h"
#include <iostream>

#include "Verylong.h"

using namespace vlong;

Verylong::Verylong(const char s[SIZE]) {
	strcpy_s(_vlstr, s);
	_vlen = strlen(s);
}

Verylong::Verylong(const unsigned long n) {
	_ltoa_s(n, _vlstr, 10);
	_strrev(_vlstr);
	_vlen = strlen(_vlstr);
}

//-----------------------------------------------------------------------------
void Verylong::setvl() {
	bool haveMinus = false;
	while (true) {
		std::cin >> _vlstr;
		int i = 0;
		while (_vlstr[i] != '\0') {
			if (i == 0 && _vlstr[i] == '-') {
				i++;
				haveMinus = true;
				continue;
			}
			if (_vlstr[i] >= '0' && _vlstr[i] <= '9') {
				i++;
				continue;
			}
			else {
				std::cout << "Incorrect entered number, try again: ";
				std::cin.clear(std::ios::failbit);
				break;
			}
		}
		if (!std::cin.good()) {
			std::cin.ignore(1000, '\n');
			std::cin.clear();
			continue;
		}
		else {
			std::cin.ignore(1000, '\n');
			break;
		}
	}

	_vlen = strlen(_vlstr);
	_strrev(_vlstr);

	bool haveBeenChanged = false;
	int minusPosition = _vlen - 1;
	for (int i = _vlen - 1; i > 0; i--) {
		if (i == _vlen - 1 && haveMinus)
			continue;
		if (_vlstr[i] == '0') {
			_vlen--;
			_vlstr[i] = '\0';
			haveBeenChanged = true;
		}
		else
			break;
	}
	if (haveMinus && _vlen == 2 && _vlstr[0] == '0') {
		_vlstr[minusPosition] = '\0';
		_vlen--;
	}
	else if (haveMinus && haveBeenChanged) {
		_vlstr[minusPosition] = '\0';
		_vlstr[_vlen - 1] = '-';
	}
}

void Verylong::getvl() const {
	char temp[SIZE] = {};
	strcpy_s(temp, _vlstr);
	std::cout << _strrev(temp);
}

//-----------------------------------------------------------------------------
Verylong Verylong::_multDecimal(const Verylong& v) const {
	char temp[SIZE];
	for (int i = v._vlen - 1; i >= 0; i--)
	    *(temp + i + 1) = *(v._vlstr + i);
	*temp = '0';
	*(temp + v._vlen + 1) = '\0';
	
	return Verylong(temp);
}

Verylong Verylong::_multDigit(const int d2) const {
	bool oneHasMinus = _vlstr[_vlen - 1] == '-' ? true : false;
	int lengthOne = (oneHasMinus) ? _vlen - 1 : _vlen;

	char temp[SIZE] = {};
	int carry = 0;
	int i;
	for (i = 0; i < lengthOne; i++) {
		int d1 = *(_vlstr + i) - '0';
		int digitprod = d1 * d2;
		digitprod += carry;
		if (digitprod >= 10) {
			carry = digitprod / 10;
			digitprod -= carry * 10;
		}
		else
			carry = 0;
		*(temp + i) = digitprod + '0';
	}
	if (carry != 0)
		*(temp + i++) = carry + '0';
	*(temp + i) = '\0';

	return Verylong(temp);
}

bool Verylong::_isGreater(const Verylong& v) const {
	int lengthThis = (_vlstr[_vlen - 1] == '-') ? _vlen - 1 : _vlen;
	int lengthAnother = (v._vlstr[v._vlen - 1] == '-') ? v._vlen - 1 : v._vlen;

	if (lengthAnother > lengthThis)
		return true;
	else if (lengthAnother == lengthThis)
		for (int i = lengthAnother - 1; i >= 0; i--) {
			if (v._vlstr[i] == _vlstr[i])
				continue;
			if (v._vlstr[i] - '0' > _vlstr[i] - '0')
				return true;
			else
				return false;
		}

	return false;
}

bool Verylong::_loan(char string[], int i) const {
	if (string[i] == '\0')
		return false;

	if (string[i] - '0' >= 1) {
		string[i]--;
		return true;
	}
	else {
		if (_loan(string, i + 1)) {
			string[i] = 9 + '0';
			return true;
		}
		else
			return false;
	}
}

void Verylong::_shift(char v[], bool increase) const {
	int length = strlen(v);
	if (length >= SIZE)
		return;

	if (increase) {
		for (int i = length - 1; i >= 0; i--)
			v[i + 1] = v[i];
		v[0] = '?';
	}
	else {
		for (int i = 1; i < length; i++)
			v[i - 1] = v[i];
		v[length - 1] = '\0';
	}
}

//-----------------------------------------------------------------------------
Verylong Verylong::operator+(const Verylong& v) const {
	if (*this == "0")
		return v;
	else if (v == "0")
		return *this;

	bool oneHasMinus = _vlstr[_vlen - 1] == '-' ? true : false;
	bool twoHasMinus = v._vlstr[v._vlen - 1] == '-' ? true : false;
	if (!oneHasMinus && twoHasMinus) {
		Verylong temp = v;
		temp._vlstr[--temp._vlen] = '\0';

		return operator-(temp);
	}
	else if (oneHasMinus && !twoHasMinus) {
		Verylong swapedOne = v;
		Verylong swapedTwo = *this;
		swapedTwo._vlstr[--swapedTwo._vlen] = '\0';

		return swapedOne - swapedTwo;
	}

	char temp[SIZE] = {};
	int lengthOne = (oneHasMinus) ? _vlen - 1 : _vlen;
	int lengthTwo = (twoHasMinus) ? v._vlen - 1 : v._vlen;

	int maxLength = (lengthOne > lengthTwo) ? lengthOne : lengthTwo;
	int carry = 0;
	for (int i = 0; i < maxLength; i++) {
		int One = (i > lengthOne - 1) ? 0 : _vlstr[i] - '0';
		int Two = (i > lengthTwo - 1) ? 0 : v._vlstr[i] - '0';

		int digitSum = One + Two + carry;
		if (digitSum >= 10) {
			digitSum -= 10;
			carry = 1;
		}
		else
			carry = 0;

		temp[i] = digitSum + '0';
	}

	if (carry == 1)
		temp[maxLength++] = '1';
	if (oneHasMinus && twoHasMinus)
		temp[maxLength++] = '-';
	temp[maxLength] = '\0';

	return Verylong(temp);
}

Verylong Verylong::operator-(const Verylong& v) const {
	bool oneHasMinus = _vlstr[_vlen - 1] == '-' ? true : false;
	bool twoHasMinus = v._vlstr[v._vlen - 1] == '-' ? true : false;
	if (oneHasMinus && !twoHasMinus) {
		Verylong temp = v;
		temp._vlstr[temp._vlen] = '-';
		temp._vlstr[++temp._vlen] = '\0';

		return operator+(temp);
	}
	else if (!oneHasMinus && twoHasMinus) {
		Verylong temp = v;
		temp._vlstr[--temp._vlen] = '\0';

		return operator+(temp);
	}

	char result[SIZE] = {};
	Verylong tempOne;
	Verylong tempTwo;
	bool secondIsGreater = _isGreater(v);
	bool saveMinus = false;
	int maxLength = secondIsGreater ? v._vlen : _vlen;

	if (secondIsGreater) {
		tempOne = v;
		tempTwo = *this;
		if (oneHasMinus)
			tempTwo._vlen--;
		if (twoHasMinus)
			tempOne._vlen--;

		if (!oneHasMinus && !twoHasMinus)
			saveMinus = true;
	}
	else {
		tempOne = *this;
		tempTwo = v;
		if (oneHasMinus)
			tempOne._vlen--;
		if (twoHasMinus)
			tempTwo._vlen--;

		if (oneHasMinus)
			saveMinus = true;
	}

	maxLength = tempOne._vlen;
	for (int i = 0; i < maxLength; i++) {
		int One = (i > tempOne._vlen - 1) ? 0 : tempOne[i] - '0';
		int Two = (i > tempTwo._vlen - 1) ? 0 : tempTwo[i] - '0';

		if (One < Two)
			if (_loan(tempOne._vlstr, i + 1))
				One += 10;
			else {
				std::cerr << "Couldn't take a one!\n";
				return Verylong();
			}

		result[i] = (One - Two) + '0';
	}
	for (int i = maxLength - 1; i >= 0; i--)
		if (result[i] == '0')
			maxLength--;
		else
			break;

	if (maxLength == 0) 
		result[maxLength++] = '0';
	else if (maxLength > 0 && saveMinus)
		result[maxLength++] = '-';
	if (maxLength > 0)
		result[maxLength] = '\0';
	else
		result[0] = '\0';

	return Verylong(result);
}

Verylong Verylong::operator*(const Verylong& v) const {
	Verylong prod;
	Verylong tempSum;

	if (*this == "0" || v == "0")
		return Verylong(0ul);

	bool oneHasMinus = _vlstr[_vlen - 1] == '-' ? true : false;
	bool twoHasMinus = v._vlstr[v._vlen - 1] == '-' ? true : false;
	int lengthTwo = (twoHasMinus) ? v._vlen - 1 : v._vlen;

	for (int i = 0; i < lengthTwo; i++) {
		int digit = v._vlstr[i] - '0';
		prod = _multDigit(digit);
		for (int k = 0; k < i; k++)
			prod = _multDecimal(prod);
		tempSum = tempSum + prod;
	}

	if ((oneHasMinus && !twoHasMinus) || (!oneHasMinus && twoHasMinus)) {
		tempSum._vlstr[tempSum._vlen++] = '-';
		tempSum._vlstr[tempSum._vlen] = '\0';
	}

	return tempSum;
}

Verylong Verylong::operator/(const Verylong& v) const {
	if (v == "0") {
		std::cerr << "Division by zero\n";
		return Verylong();
	}
	else if (*this == "0")
		return Verylong(0ul);

	Verylong divident = *this;
	bool dividentHasMinus = (divident._vlstr[divident._vlen - 1] == '-') ? true : false;
	if (dividentHasMinus) {
		divident._vlstr[divident._vlen - 1] = '\0';
		divident._vlen--;
	}
	Verylong divider = v;
	bool dividerHasMinus = (divider._vlstr[divider._vlen - 1] == '-') ? true : false;
	if (dividerHasMinus) {
		divider._vlstr[divider._vlen - 1] = '\0';
		divider._vlen--;
	}

	char temp[SIZE] = {};

	int i = 0;
	int decimalPoint = 0;
	bool havePoint = false;
	Verylong multiplier;
	do {
		multiplier = 0;

		do {
			divident = divident - divider;
			if (divident._vlstr[divident._vlen - 1] == '-') {
				havePoint = true;
				break;
			}
			multiplier = multiplier + 1;
		} while (true);
		divident = (divident + divider) * 10;

		if (multiplier == "0") {
			_shift(temp, true);
			temp[0] = '0';			
		}
		else {
			for (int j = 0; j < multiplier._vlen; j++) {
				if (decimalPoint > 0) {
					i = 0;
					_shift(temp, true);
				}
				temp[i++] = multiplier._vlstr[j];
			}

			if (divident == "0")
				break;
		}

		if (decimalPoint == MAX_DECIMAL_POINT)
			break;

		if (decimalPoint > 0)
			decimalPoint++;
		else if (havePoint && decimalPoint == 0) {
			_shift(temp, true);
			temp[0] = '.';
			decimalPoint++;
		}
	} while (true);

	while (temp[0] == '0' || temp[0] == '.')
		_shift(temp, false);
	int length = strlen(temp);

	if ((dividentHasMinus && !dividerHasMinus) || (!dividentHasMinus && dividerHasMinus))
		temp[length++] = '-';
	temp[length] = '\0';

	return Verylong(temp);
}

char& Verylong::operator[](int index) {
	if (index >= 0 && index < SIZE)
		return this->_vlstr[index];

	std::cerr << " out of range access!\n";
	return _vlstr[0];
}

bool Verylong::operator==(const char number[]) const {
	Verylong same = *this;
	_strrev(same._vlstr);

	if (same._vlen == strlen(number)) {
		for (int i = 0; i < same._vlen; i++) {
			if (same._vlstr[i] != number[i])
				return false;
		}
	}
	else
		return false;

	return true;
}

void Verylong::operator=(const unsigned long n) {
	_ltoa_s(n, _vlstr, 10);
	_strrev(_vlstr);
	_vlen = strlen(_vlstr);
}