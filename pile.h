#pragma once

template <class T>
class Pile {
private:
	template <class T1>
	class Node {
	private:
		T1 data;
		Node<T>* previous;
	public:
		Node(T1 data) { this->data = data; this->previous = nullptr; }
		~Node() { this->previous = nullptr; }
		T1 getData() const { return this->data; }
		Node* getPrevious() const { return this->previous; }
		void setPrevious(Node* prev) { this->previous = prev; }
	};
private:
	Node<T>* top;
	int size;
	int max_size;
public:
	Pile() { this->top = nullptr; this->size = 0; this->max_size = -1; }
	Pile(int max_size) { this->top = nullptr; this->size = 0; this->max_size = max_size; }
	~Pile() { delete_pile(); }
	void delete_pile() {}
	void push(T d);
	void pop();
	T getTop() { return this->top->getData(); }
	int getSize() { return this->size; }
	bool isEmpty() { return this->top == nullptr ? true : false; }
	bool isFull() { if (max_size != -1) { return this->size == this->max_size ? true : false; } return false; }
};

template <class T>
inline void Pile<T>::push(T d)
{
	Node<T>* aux = new Node<T>(d);
	aux->setPrevious(this->top);
	this->top = aux;
	this->size++;
}

template <class T>
inline void Pile<T>::pop()
{
	if (this->top != nullptr)
	{
		Node<T>* aux = this->top;
		this->top = this->top->getPrevious();
		this->size--;
		delete aux;
	}
}
