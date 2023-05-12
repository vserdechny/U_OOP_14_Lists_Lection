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

	public:
		//Constructors and destructor
		//**************************************
		
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
		}

		//**************************************
		//Methods that receive information about the size of the list
		//**************************************
		
		//Returns true if the list is empty
		bool is_empty()const { return _head == nullptr; }
		//Returns the number of nodes in the list
		size_t size()const
		{
			if (_head == nullptr)
				return 0;

			size_t count = 1;

			auto node = _head;
			while (node->next() != nullptr)
			{
				node = node->next();
				count++;
			}

			return count;
		}

		//**************************************
		//Access methods
		//**************************************

		const Type& value_at(size_t index)const
		{
			if (_head == nullptr)
				throw std::out_of_range("Index out of range!");

			auto node = _head;
			for (size_t i = 0; i < index; i++)
			{
				node = node->next();
				if (node == nullptr)
					throw std::out_of_range("Index out of range!");
			}
			return node->value();
		}

		//**************************************
		//Add and remove methods
		//**************************************

		//Adds a new node to the end of the list
		void push_back(const Type& value)
		{
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
	};
}