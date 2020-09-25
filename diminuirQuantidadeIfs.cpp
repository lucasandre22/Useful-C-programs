#include <string>
#include <map>
#include <iostream>


void function1()
{
	std::cout << "executando function 1" << std::endl;
}

void function2()
{
	std::cout << "executando function 2" << std::endl;
}

void function3()
{
	std::cout << "executando function 3" << std::endl;
}

void function4()
{
	std::cout << "executando function 4" << std::endl;
}




int main()
{
	std::string string;
	std::map<std::string, void(*)()> mapa;
	mapa["function1"] = &function1;
	mapa["function2"] = &function2;
	mapa["function3"] = &function3;
	mapa["function4"] = &function4;
	std::cin >> string;
	(mapa[string])();
}