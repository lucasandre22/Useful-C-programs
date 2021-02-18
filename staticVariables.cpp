#include <iostream>

class Test{
private:
    int n;
    static int n1;

public:
    Test(const n1) { this->n = n1++;}
    ~Test() {}
    const int GetN() const { return this->n; }
    static int GetN1() const { return this->n1; }
};

int Test::n1 = 1;

int main()
{
    Test t1,t2,t3,t4,t5;

    std::cout << t1.GetN() << std::endl;
    std::cout << t2.GetN() << std::endl;
    std::cout << t3.GetN() << std::endl;
    std::cout << t4.GetN() << std::endl;
    std::cout << t5.GetN() << std::endl;
}
