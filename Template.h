#include <iostream>
#pragma once

namespace List {
	template <class T>
	class List {
	private:
		template <class T1>
		class Node {
		private:
			T1 value;
			Node<T1>* next;
			Node<T1>* previous;
		public:
			Node(T1 value) { this->value = value; this->next = nullptr; this->previous = nullptr; }
			~Node() { }
			T1 GetValue() const { return this->value; }
			Node<T1>* GetNext() const { return this->next; }
			void SetNext(Node<T>* next) { this->next = next; }
			Node<T1>* GetPrevious() const { return this->previous; }
			void SetPrevious(Node<T>* previous) { this->previous = previous; }
		};
		Node<T>* head;
		int size;
	public:
		template <class T2> friend class Iterator;
		List() { this->head = nullptr; this->size = 0; }
		~List() { Delete(); }
		void Delete() { for (Node<T>* aux = this->head; aux != nullptr; aux = this->head) { this->head = aux->GetNext(); delete aux; } }
		void Include(T value);
		void Remove(T value);
		int GetSize() const { return this->size; }
		Node<T>* GetHead() const { return this->head; }
	};

	template <class T2>
	class Iterator {
	private:
		List<T2>::Node<T2>* iterator;
		List<T2>* list;
	public:
		Iterator(List<T2>* list = nullptr) { this->list = list; this->iterator = nullptr; }
		~Iterator() { }
		void SetIteratorHead() { this->iterator = this->list->GetHead(); }
		T2 GetValue() const { return this->iterator->GetValue(); }
		bool IteratorNull() const { return this->iterator == nullptr ? true : false; }
		void operator++() { this->iterator = this->iterator->next; }
		//void operator=(List<T2>& list) { this->list = list; this->iterator = nullptr; } //posso chamar explicitamente a construtora?
		void ForEach() { } //to implement
	};

	template <class T>
	void List<T>::Include(T value)
	{
		Node<T>* aux = new Node<T>(value);
		aux->SetNext(this->head);
		if (this->head)
			this->head->SetPrevious(aux);
		this->head = aux;
		this->size++;
	}

	template <class T>
	void List<T>::Remove(T value)
	{
		Node<T>* aux = this->head;
		for (; aux != nullptr && aux->GetValue() != value; aux = aux->GetNext()) {}
		if (aux == nullptr)
			return;
		if (aux->GetNext() != nullptr)
			aux->GetNext()->SetPrevious(aux->previous);
		if (aux->GetPrevious() != nullptr)
			aux->GetPrevious->SetNext(aux->next);
		if (this->head == aux)
			this->head = aux->GetNext();
		this->size--;
		delete* aux;
	}
}