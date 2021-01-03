#include <iostream>

class Counter
{
    public :
        Counter() : _count(0) {}
        Counter(unsigned short c) : _count(c) {}

        unsigned short getCount() const { return _count; }

        Counter operator++() { return Counter(++_count); }

    protected :
        unsigned short _count;
};

class CounterDec : public Counter
{
    public :
        CounterDec() : Counter() {}
        CounterDec(unsigned short c) : Counter(c) {}
        
        CounterDec operator--() { return CounterDec(--_count); }

    private :

};

class CounterPost : public Counter
{
    public :
        CounterPost() : Counter() {}
        CounterPost(unsigned short c) : Counter(c) {}

        Counter operator++() { return Counter(++_count); }
        Counter operator++(int) { return Counter(_count++); }

    private :

};

class CounterDecPost : public CounterDec
{
    public :
        CounterDecPost() : CounterDec() {}
        CounterDecPost(unsigned short c) : CounterDec(c) {}

        Counter operator--(int) { return Counter(_count--); }
         Counter operator--() { return Counter(--_count); }

    private :
};

int main() {
    CounterPost counter = 20;
    CounterDecPost counterDec = 20;

    std::cout << "++counter++ " << counter.getCount() << std::endl;
    std::cout << "--counter-- " << counterDec.getCount() << std::endl;

    ++counter;
    counter++;
    Counter temp = counter++;
    std::cout << "++counter++ " << counter.getCount();  
    std::cout << " ++counter++ " << temp.getCount() << std::endl;

    --counterDec;
    counterDec--;
    temp = counterDec--;
    std::cout << "--counter-- " << counterDec.getCount();
    std::cout << " --counter-- " << temp.getCount() << std::endl;

    return 0;
}