#include <iostream>
#include <vector>
#include <algorithm>

namespace lucas {
    class Test {
    private:
        static int n1;
        int n;

    public:
        Test() { n = n1++; }
        ~Test() {}
        int GetN() const { return this->n; }
        int GetN1() const { return this->n1; }
    };

}

int lucas::Test::n1 = 1; //specificing that I'm using the n1 integer from lucas namespace

int max(const std::vector<int>& vector)
{
    int maximum = 0;
    int max = 0;
    for (auto i : vector)
    {
        if (i > maximum)
            maximum = i;
    }
    for (auto i : vector)
    {
        if (i == maximum)
            max++;
    }
    return max;
}

int main()
{
    std::vector<int> vector;
    for (int i = 0; i < 10; i++) {
        vector.push_back(i);
    }

    std::cout << std::max({ 4,5,6,7,8,9,9 }) << std::endl;
    std::cout << max({ 4,5,6,7,8,9,9 }) << std::endl;
       
    lucas::Test t1, t2, t3, t4, t5;

    
    std::cout << t1.GetN() << std::endl;
    std::cout << t2.GetN() << std::endl;
    std::cout << t3.GetN() << std::endl;
    std::cout << t4.GetN() << std::endl;
    std::cout << t5.GetN() << std::endl;
}
