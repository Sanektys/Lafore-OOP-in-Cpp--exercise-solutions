#pragma once

namespace vlong {
    const int SIZE = 1000;
    const int MAX_DECIMAL_POINT = 20;

    class Verylong
    {
        public:
            Verylong() : _vlen(0), _vlstr() {}
            Verylong(const char s[SIZE]);
            Verylong(const unsigned long n);

            void setvl();
            void getvl() const;
            Verylong operator+(const Verylong&) const;
            Verylong operator-(const Verylong&) const;
            Verylong operator*(const Verylong&) const;
            Verylong operator/(const Verylong&) const;
            void operator=(const unsigned long n);
            char& operator[](int);
            bool operator==(const char[]) const;

        private:
            Verylong _multDigit(const int) const;
            Verylong _multDecimal(const Verylong&) const;
            bool _isGreater(const Verylong&) const;
            bool _loan(char[], int) const;
            void _shift(char[], bool) const;

        private:
            char _vlstr[SIZE];
            int _vlen;
    };
}