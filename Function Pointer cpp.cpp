#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

int lowerInteger(int a, int b)
{
    return a < b ? a : b;
}

int higherInteger(int a, int b)
{
    return a > b ? a : b;
}

//vector functions

void print(int& a)
{
    std::cout << "Value = " << a << std::endl;
}

void addOne(int& a)
{
    a += 1;
}

void ForEach(std::vector<int>& vector, void(*function)(int&))
{
    for (auto& value : vector)
        function(value);
}

std::ostream& operator<<(std::ostream& stream, std::vector<int>& a)
{
    for (auto i : a)
        stream << i << ' ';
    return stream;
}

std::ostream& operator<<(std::ostream& stream, std::vector<float>& a)
{
    for (auto i : a)
        stream << i << '-';
    return stream;
}

int main()
{
    //function pointer
    int (*ptr) (int, int) = lowerInteger; //This is the syntax to a pointer to a function
    std::vector<int> vector({ 1, 2, 8, 0, 5, 6 });
    std::vector<float> vector1({ 1.0f, 2.0f, 8.0f, 0.0f, 5.0f, 6.0f });

    std::cout << vector << std::endl;
    std::cout << vector1 << std::endl;

    //function pointer
    auto function = [](int i) { std::cout << i << ' '; };
    void(*ptr1)(int) = function;
    std::for_each(vector.begin(), vector.end(), function);


    ForEach(vector, print);
    ForEach(vector, addOne);
    std::cout << std::endl;
    ForEach(vector, print);
    ForEach(vector, [](int& value) {std::cout << "One " << std::endl; });//lambda function
    //auto function = lowerInteger(int, int);
    std::cout << ptr(higherInteger(0, 2), ptr(40, 3)) << std::endl;
    return 0;
}
