#pragma once

namespace data_structures
{
	/*
	Base abstract class for all type of lists
	Author: Serdechny V.S.
	Date: 13.05.2023
	*/

	template <typename Type>
	class List
	{
	protected:
		size_t _size{ 0 };

	public:
		//Constructors and destructor
		//**************************************
		List() {}
		List(size_t count)
			:_size(count)
		{}

		virtual ~List() {}

		//**************************************
		//Methods that receive information about the size of the list
		//**************************************

		//Returns true if the list is empty
		virtual bool is_empty()const { return _size == 0; }
		//Returns the number of nodes in the list
		virtual size_t size()const { return _size; }

		//**************************************
		//Access methods
		//**************************************

		//Returns the value from the node at the specified position
		virtual const Type& value_at(size_t index)const = 0;
		//Assigns a value to the node at the specified position
		virtual void set_value(size_t index, const Type& value) = 0;
		//**************************************
		//Add and remove methods
		//**************************************

		//Adds a new node to the end of the list
		virtual void push_back(const Type& value) = 0;
		//Adds a new node to the front of the list
		virtual void push_front(const Type& value) = 0;
		//Removes the end node of the list
		virtual void pop_back() = 0;
		//Removes the first node of the list
		virtual void pop_front() = 0;
		//Inserts a new node with the corresponding value at the specified position
		virtual void insert(size_t index, const Type& value) = 0;
		//Removes the node at the specified position
		virtual void remove_at(size_t index) = 0;
		//Clears the list
		virtual void clear() = 0;
	};
}