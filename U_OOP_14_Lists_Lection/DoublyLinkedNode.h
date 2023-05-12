#pragma once

namespace data_structures
{
	/*
	Doubly Linked List Node Implementation
	Author: Serdechny V.S.
	Date: 12.05.2023
	*/
	template <typename Type>
	class DoublyLinkedNode
	{
	private:
		Type _value{ Type() };			//node value
		DoublyLinkedNode<Type>* _next;	//pointer to next node
		DoublyLinkedNode<Type>* _prev;	//pointer to previous node

	public:
		//Constructors
		//**************************************

		//1. Initializes the node with the specified value and a pointers to the next and previous nodes
		DoublyLinkedNode(const Type& value, DoublyLinkedNode<Type>* prev, DoublyLinkedNode<Type>* next)
			:_value(value), _next(next), _prev(prev)
		{}
		//2. Initializes the node with the specified value but without pointers
		DoublyLinkedNode(const Type& value)
			:_value(value), _next(nullptr), _prev(nullptr)
		{}
		//3. Initalize the node witout specified value
		DoublyLinkedNode()
			:_next(nullptr), _prev(nullptr)
		{}

		//**************************************
		//Access methods
		//**************************************

		//Returns a pointer to the next node
		DoublyLinkedNode<Type>* next() { return _next; }
		//Returns a pointer to the previous node
		DoublyLinkedNode<Type>* prev() { return _prev; }
		//Returns a constant reference to the value of the node
		const Type& value()const { return _value; }

		//Assigns a pointer to the next node to the address of the corresponding node
		void set_next(DoublyLinkedNode<Type>* node) { _next = node; }
		//Assigns a pointer to the previous node to the address of the corresponding node
		void set_prev(DoublyLinkedNode<Type>* node) { _prev = node; }
		//Assigns the corresponding value to the node
		void set_value(const Type& value) { _value = value; }
	};
}