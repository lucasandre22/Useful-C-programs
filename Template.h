#include <iostream>

namespace List {

	template <class T>

	class List {
	private:
		class Node {
		public:
			T value;
			Node* next;
			Node(T value) { this->value = value; this->next = nullptr; }
			~Node() { }
			void setValue(T value) { this->value = value; }
			T GetValue() { return this->value; }
		};
		Node* Head;
		int Size;
	public:
		List() { this->Head = nullptr; this->Size = 0; }
		~List() { for (Node* aux = this->Head; aux != nullptr; aux = this->Head) { this->Head = this->Head->next; delete aux; } }
		T GetHead() { return this->Head; }
		void Print() { for (Node* aux = this->Head; aux != nullptr; aux = aux->next) std::cout << aux->GetValue() << std::endl; }
		void Include(T value) { Node* aux = new Node(value); aux->next = this->Head; this->Head = aux; this->Size++; }
		int GetSize();

	};

	template <class T> //important, all the functions must be declared in the header!
	inline int List<T>::GetSize()
	{
		return this->size;
	}
}
