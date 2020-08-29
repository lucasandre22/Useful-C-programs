#include <iostream>
#include <algorithm>

namespace List {

	template <class T>

	class List {
	private:
		class Node {
		public:
			T value;
			Node* next;
			Node(T value) { this->value = value; this->next = nullptr; }
			~Node() { delete this; }
			void setValue(T value) { this->value = value; }
			T GetValue() { return this->value; }
		};
		Node* Head;
		int Size;
	public:
		List() { this->Head = nullptr; this->Size = 0; }
		T GetHead() { return this->Head; }
		void Print() { for (Node* aux = this->Head; aux != nullptr; aux = aux->next) std::cout << aux->GetValue() << std::endl; }
		void Include(T value) { Node* aux = new Node(value); aux->next = this->Head; this->Head = aux; this->Size++; }
		int GetSize() { return this->Size; }
	};

}

int main()
{
	List::List<int> a;
	a.Include(1);
	a.Include(2);
	a.Include(3);
	a.Include(4);
	a.Print();

}