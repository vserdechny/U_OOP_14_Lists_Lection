#pragma once

namespace data_structures
{
	/*
	Singly Linked List Node Implementation
	Author: Serdechny V.S.
	Date: 12.05.2023
	*/
	template <typename Type>
	class SinglyLinkedNode
	{
	private:
		Type _value{ Type() };			//node value
		SinglyLinkedNode<Type>* _next;		//pointer to next node

	public:
		//Constructors
		//**************************************
		
		//1. Initializes the node with the specified value and a pointer to the next node
		SinglyLinkedNode(const Type& value, SinglyLinkedNode<Type>* next)
			:_value(value), _next(next)
		{}
		//2. Initializes the node with the specified value but without a pointer to the next node
		SinglyLinkedNode(const Type& value)
			:_value(value), _next(nullptr)
		{}
		//3. Initalize the node witout specified value
		SinglyLinkedNode()
			:_next(nullptr)
		{}

		//**************************************
		//Access methods
		//**************************************

		//Returns a pointer to the next node
		SinglyLinkedNode<Type>* next()const { return _next; }
		//Returns a constant reference to the value of the node
		const Type& value()const { return _value; }

		//Assigns a pointer to the next node to the address of the corresponding node
		void set_next(SinglyLinkedNode<Type>* node) { _next = node; }
		//Assigns the corresponding value to the node
		void set_value(const Type& value) { _value = value; }
	};
}