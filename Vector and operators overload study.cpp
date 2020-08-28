#include <iostream>
#include <vector>
#include <algorithm>
#include "String.h"
//using namespace std; Its not a good idea!

//funções e variáveis fora de classes com static, quer dizer que só vai ser usado naquele header ou arquivo normal, ele não é declarado globalmente, ou seja
//outros headers não terão acesso.

class Vector2 {
private:
	float x;
	float y;
public:
	Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
	~Vector2() {}
	void print()
	{
		std::cout << x << ' ' << y << std::endl;
	}

	Vector2 operator+(Vector2& vector)
	{
		return Vector2(this->x + vector.x, this->y + vector.y);
	}

	Vector2 operator-(Vector2& vector)
	{
		return Vector2(this->x - vector.x, this->y - vector.y);
	}

	Vector2 operator*(Vector2& vector)
	{
		//return Vector2(this->x * vector.x, this->y * vector.y); This is going to work either
		this->x *= vector.x;
		this->y *= vector.y;
		return *this;
	}

	Vector2 operator*=(Vector2& vector) //const no final da função significa que não irá modificar a classe, não irá ter permissão para isso
	{
		return *this*vector; //utiliza a definição de * já feita acima
	}

	bool operator==(Vector2& vector)
	{
		return vector.x == x && vector.y == y;
	}

	bool operator!=(Vector2& vector)
	{
		return !(vector == *this); //"this" is a pointer to the class, it returns the opposite of the operator ==
	}
	
	float operator[](int position)
	{
		return position == 1 ? x : y;
	}

	float at(int position)
	{
		return operator[](position);
	}

	float GetY() { return this->y; }
	float GetX() { return this->x; }
};

std::ostream& operator<<(std::ostream& stream, Vector2& vector)
{
	stream << vector.GetX() << ' ' << vector.GetY() << std::endl;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, std::vector<int>& vector)
{
	for (auto& i : vector)
		stream << i << ' ';
	stream << std::endl;
	return stream;
}

/*void reverse(std::vector<int>& vector)
{
	if (vector.size() > 0)
	{
		int end = vector.size();
		std::cout << "end : " << end << std::endl;
		std::vector<int>::iterator aux = vector.begin();
		end += -1;
		for (int begin = 0; begin <= end; begin++)
		{
			std::cout << *(vector.begin() + begin) << ' ' << *((vector.begin()+end));
			aux = (vector.begin() + begin);
			(vector.begin() + begin) = (vector.begin() + end);
			(vector.begin() + end) = aux;
			end--;
		}
		std::cout << vector;
	}
}*/

void VectorStudies()
{
	int a = 24;
	//std::vector<elementType> vectorName;
	std::vector<int> vector;
	std::vector<int> vector2;
	bool test;
	test = a;
	std::cout << "test = " << test << std::endl; //True if its different than 0, otherwise false
	vector.assign(10, 5); //Puts the integer 5 ten times in the vector
	a = vector.front(); //It returns the first element
	a = vector.back(); //It returns the last element
	int test6 = *vector.begin(); //vetor.begin() returns a pointer to the first element
	std::vector<int>::iterator b = vector.begin(); //It returns the reference to the first element
	std::cout << *b; //How to print an iterator
	b = vector.begin(); //It returns an iterator to the first element
	b = vector.end(); //It returns an iterator to the last element
	std::cout << "Vector front : " << vector.front() << std::endl; //It returns the value in the fast position
	std::cout << "Vector back : " << vector.back() << std::endl; //It returns the value in the last position
	vector.push_back(4); //Puts 4 at the back of the vector
	vector.emplace(vector.begin(), a = 0); //It puts 0 in the beginning
	vector.emplace(vector.begin() + 1, 3); //It puts 3 in the second position

	for (auto& i : vector) //how to print it
		std::cout << i << ' ';
	std::cout << std::endl;
	vector2 = vector; //It copies the vector to the vector2
	std::cout.put('\n');
	for (auto& i : vector2)
		std::cout << i << ' ';
	vector.size(); //It returns the size of vector, how many elements it has
	vector.insert(vector.end(), 5); //It puts 5 at the end
	vector.pop_back(); //It removes the last element
	vector.erase(vector.begin()); //removes the first element, you need to pass a reference to the position that you want to remove
	vector.clear(); //removes all the elements from vector

	std::vector<int> vector3({ 1,2,3,4,5,6,7,8,9 });
	//std::reverse(vector3.begin(), vector3.end());
	std::cout << std::endl << vector3 << std::endl;
	std::cout << "Reverse : " << std::endl;
	std::reverse(vector3.begin(),vector3.end()); //revert a vector
	std::cout << vector3;
	std::sort(vector3.begin(), vector3.end()); //sort a vector
	std::cout << vector3;

}


int main()
{
	VectorStudies();
	bool a = true;
	std::cout << std::endl << std::boolalpha << a << std::endl; //printing bool as true or false in the compiler
	//Vector2 vetor = parameter; //when it has a constructor that recieves "parameter" as a parameter, like Vector2(type parameter)
	//Vector2 vetor;
	//Vector2 vetor = vetor; //when it has the default construtor
	//Vector2 vetor = new vetor; when it has the default constructor
	//Vector2 vetor = vetor(parameters);
	//Vector2 vetor = new vetor(parameters);
	//Vector2 vector(parameters);
	std::cout << std::endl << "Vector2 Studies below" << std::endl;
	Vector2 vetor(2.0f, 2.0f);
	Vector2 vetor2(2.0f, 2.0f);
	vetor = vetor + vetor2;
	vetor2.print();
	vetor = vetor * vetor2;
	vetor *= vetor2;
	
	//vetor.print();
	std::cout << vetor << std::endl;
	std::cout << vetor[1];
	std::cout << vetor[2];

	std::cout.getloc();

	
}