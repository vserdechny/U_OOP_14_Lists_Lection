#pragma once
#include <stdexcept>
#include "List.h"
#include "SinglyLinkedNode.h"

namespace data_structures
{
	/*
	Singly Linked List Implementation
	Author: Serdechny V.S.
	Date: 12.05.2023
	*/

	template <typename Type>
	class SinglyLinkedList : public List<Type>
	{
	private:
		SinglyLinkedNode<Type>* _head{ nullptr };		//pointer to the head of the list
		SinglyLinkedNode<Type>* _tail{ nullptr };		//pointer to the tail of the list

	public:
		//Constructors and destructor
		//**************************************
		
		//Default constructor
		SinglyLinkedList() {}
		//Constructor that takes as an argument the number of nodes and reserves space for them
		SinglyLinkedList(size_t count)
			:List<Type>(count)
		{
			_head = new SinglyLinkedNode<Type>();

			auto node = _head;
			for (size_t i = 1; i < count; i++)
			{
				node->set_next(new SinglyLinkedNode<Type>());
				node = node->next();
			}

			_tail = node;
		}
		//Destructor that removes all nodes
		~SinglyLinkedList() override
		{
			if (!_head)
				return;

			auto node = _head;
			while (node != nullptr)
			{
				auto next = node->next();
				delete node;
				node = next;
			}

			_head = _tail = nullptr;
			List<Type>::_size = 0;
		}

		//**************************************
		//Access methods implementation
		//**************************************

		//Returns the value from the node at the specified position
		const Type& value_at(size_t index)const override
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == List<Type>::_size - 1)
				return _tail->value();

			auto node = _head;
			for (size_t i = 0; i < index; i++)
				node = node->next();

			return node->value();
		}
		//Assigns a value to the node at the specified position
		void set_value(size_t index, const Type& value) override
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == List<Type>::_size - 1)
				_tail->set_value(value);

			auto node = _head;
			for (size_t i = 0; i < index; i++)
				node = node->next();

			node->set_value(value);
		}

		//**************************************
		//Add and remove methods
		//**************************************

		//Adds a new node to the end of the list
		void push_back(const Type& value) override
		{
			if (!_head)
			{
				_head = new SinglyLinkedNode<Type>(value);
				_tail = _head;
			}
			else
			{
				_tail->set_next(new SinglyLinkedNode<Type>(value));
				_tail = _tail->next();
			}
			List<Type>::_size++;
		}
		//Adds a new node to the front of the list
		void push_front(const Type& value) override
		{
			auto node = new SinglyLinkedNode<Type>(value, _head);
			_head = node;
			List<Type>::_size++;
		}
		//Removes the end node of the list
		void pop_back() override
		{
			if (!_head)
				return;

			if (!_head->next())
			{
				delete _head;
				_head = _tail = nullptr;
			}
			else
			{
				auto node = _head;
				while (node->next() != _tail)
					node = node->next();

				delete node->next();
				node->set_next(nullptr);
				_tail = node;
			}

			List<Type>::_size--;
		}
		//Removes the first node of the list
		void pop_front() override
		{
			if (!_head)
				return;

			auto node_to_del = _head;
			_head = _head->next();
			delete node_to_del;
			List<Type>::_size--;
		}
		//Inserts a new node with the corresponding value at the specified position
		void insert(size_t index, const Type& value) override
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == 0)
				push_front(value);
			else
			{
				auto node = _head;
				for (size_t i = 0; i < index - 1; i++)
					node = node->next();

				auto new_node = new SinglyLinkedNode<Type>(value, node->next());
				node->set_next(new_node);

				List<Type>::_size++;
			}
		}
		//Removes the node at the specified position
		void remove_at(size_t index) override
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == 0)
				pop_front();
			else if (index == List<Type>::_size - 1)
				pop_back();
			else
			{
				auto node = _head;
				for (size_t i = 0; i < index - 1; i++)
					node = node->next();

				auto node_to_del = node->next();
				node->set_next(node->next()->next());
				delete node_to_del;

				List<Type>::_size--;
			}
		}
		//Clears the list
		void clear() override
		{
			this->~SinglyLinkedList();
		}
	};
}