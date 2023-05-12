#pragma once
#include <stdexcept>
#include "SinglyLinkedNode.h"

namespace singly_linked_list
{
	/*
	Singly Linked List Implementation
	Author: Serdechny V.S.
	Date: 12.05.2023
	*/

	template <typename Type>
	class SinglyLinkedList
	{
	private:
		SinglyLinkedNode<Type>* _head{ nullptr };		//pointer to the head of the list
		size_t _size{ 0 };

	public:
		//Constructors and destructor
		//**************************************
		
		//Default constructor
		SinglyLinkedList() {}
		//Constructor that takes as an argument the number of nodes and reserves space for them
		SinglyLinkedList(size_t count)
			:_size(count)
		{
			_head = new SinglyLinkedNode<Type>();

			auto node = _head;
			for (size_t i = 1; i < count; i++)
			{
				node->set_next(new SinglyLinkedNode<Type>());
				node = node->next();
			}
		}
		//Destructor that removes all nodes
		~SinglyLinkedList()
		{
			if (_head == nullptr)
				return;

			auto node = _head;

			while (node != nullptr)
			{
				auto next = node->next();
				delete node;
				node = next;
			}

			_head = nullptr;
			_size = 0;
		}

		//**************************************
		//Methods that receive information about the size of the list
		//**************************************
		
		//Returns true if the list is empty
		bool is_empty()const { return _head == nullptr; }
		//Returns the number of nodes in the list
		size_t size()const
		{
			return _size;
		}

		//**************************************
		//Access methods
		//**************************************

		//Returns the value from the node at the specified position
		const Type& value_at(size_t index)const
		{
			if (_head == nullptr || index >= _size)
				throw std::out_of_range("Index out of range!");

			auto node = _head;
			for (size_t i = 0; i < index; i++)
				node = node->next();

			return node->value();
		}
		//Assigns a value to the node at the specified position
		void set_value(size_t index, const Type& value)
		{
			if (_head == nullptr || index >= _size)
				throw std::out_of_range("Index out of range!");

			auto node = _head;
			for (size_t i = 0; i < index; i++)
				node = node->next();

			node->set_value(value);
		}

		//**************************************
		//Add and remove methods
		//**************************************

		//Adds a new node to the end of the list
		void push_back(const Type& value)
		{
			_size++;

			if (_head == nullptr)
			{
				_head = new SinglyLinkedNode<Type>(value);
				return;
			}

			auto node = _head;
			while (node->next() != nullptr)
				node = node->next();

			node->set_next(new SinglyLinkedNode<Type>(value));
		}
		//Removes the end node of the list
		void pop_back()
		{
			if (_head == nullptr)
				return;

			_size--;

			if (_head->next() == nullptr)
			{
				delete _head;
				_head = nullptr;
				return;
			}

			auto node = _head;
			while (node->next()->next() != nullptr)
				node = node->next();

			delete node->next();
			node->set_next(nullptr);
		}
		//Inserts a new node with the corresponding value at the specified position
		void insert(size_t index, const Type& value)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range!");

			_size++;

			if (index == 0)
			{
				auto node = new SinglyLinkedNode<Type>(value, _head);
				_head = node;
				return;
			}

			auto node = _head;
			for (size_t i = 0; i < index-1; i++)
				node = node->next();

			auto new_node = new SinglyLinkedNode<Type>(value, node->next());
			node->set_next(new_node);
		}
		//Removes the node at the specified position
		void remove_at(size_t index)
		{
			if (_head == nullptr || index >= _size)
				throw std::out_of_range("Index out of range!");

			_size--;

			if (index == 0)
			{
				auto node_to_del = _head;
				_head = _head->next();
				delete node_to_del;
				return;
			}

			auto node = _head;
			for (size_t i = 0; i < index - 1; i++)
				node = node->next();

			if (node->next()->next() == nullptr)
			{
				delete node->next();
				node->set_next(nullptr);
			}
			else
			{
				auto node_to_del = node->next();
				node->set_next(node->next()->next());
				delete node_to_del;
			}
		}
		//Clears the list
		void clear()
		{
			this->~SinglyLinkedList();
		}
	};
}