#pragma once
#include <stdexcept>
#include "DoublyLinkedNode.h"

namespace data_structures
{
	/*
	Doubly Linked List Implementation
	Author: Serdechny V.S.
	Date: 12.05.2023
	*/

	template <typename Type>
	class DoublyLinkedList
	{
	private:
		DoublyLinkedNode<Type>* _head{ nullptr };		//pointer to the head of the list
		DoublyLinkedNode<Type>* _tail{ nullptr };		//pointer to the tail of the list
		size_t _size{ 0 };								//count of nodes in the list

	public:
		//Constructors and destructor
		//**************************************

		//Default constructor
		DoublyLinkedList() {}
		//Constructor that takes as an argument the number of nodes and reserves space for them
		DoublyLinkedList(size_t count)
			:_size(count)
		{
			_head = new DoublyLinkedNode<Type>();

			auto node = _head;
			for (size_t i = 1; i < count; i++)
			{
				node->set_next(new DoublyLinkedNode<Type>());
				node->next()->set_prev(node);
				node = node->next();
			}

			_tail = node;
		}
		//Destructor that removes all nodes
		~DoublyLinkedList()
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
			_size = 0;
		}

		//**************************************
		//Methods that receive information about the size of the list
		//**************************************

		//Returns true if the list is empty
		bool is_empty()const { return !_head; }
		//Returns the number of nodes in the list
		size_t size()const { return _size; }

		//**************************************
		//Access methods
		//**************************************

		//Returns the value from the node at the specified position
		const Type& value_at(size_t index)const
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range!");

			if (index == _size - 1)
				return _tail->value();

			DoublyLinkedNode<Type>* node = nullptr;

			//If we need a value from the second part of the list, let's iterate reversed
			if (index > _size / 2)
			{
				node = _tail;
				for (size_t i = _size - 1; i > index; i--)
					node = node->prev();
			}
			else
			{
				node = _head;
				for (size_t i = 0; i < index; i++)
					node = node->next();
			}	

			return node->value();
		}
		//Assigns a value to the node at the specified position
		void set_value(size_t index, const Type& value)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range!");

			if (index == _size - 1)
				_tail->set_value(value);

			DoublyLinkedNode<Type>* node = nullptr;

			//If we need a value from the second part of the list, let's iterate reversed
			if (index > _size / 2)
			{
				node = _tail;
				for (size_t i = _size - 1; i > index; i--)
					node = node->prev();
			}
			else
			{
				node = _head;
				for (size_t i = 0; i < index; i++)
					node = node->next();
			}

			node->set_value(value);
		}

		//**************************************
		//Add and remove methods
		//**************************************

		//Adds a new node to the end of the list
		void push_back(const Type& value)
		{ 
			_size++;

			if (!_head)
			{
				_head = new DoublyLinkedNode<Type>(value);
				_tail = _head;
				return;
			}

			_tail->set_next(new DoublyLinkedNode<Type>(value));
			_tail->next()->set_prev(_tail);
			_tail = _tail->next();
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

			auto cur_tail = _tail;
			_tail = _tail->prev();
			_tail->set_next(nullptr);
			delete cur_tail;
		}
		//Inserts a new node with the corresponding value at the specified position
		void insert(size_t index, const Type& value)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range!");

			_size++;

			if (index == 0)
			{
				auto node = new DoublyLinkedNode<Type>(value);
				node->set_next(_head);
				_head->set_prev(node);
				_head = node;
				return;
			}

			DoublyLinkedNode<Type>* node = nullptr;

			if (index > _size / 2)
			{
				node = _tail;
				for (size_t i = _size - 1; i > index; i--)
					node = node->prev();
			}
			else
			{			
				node = _head;
				for (size_t i = 0; i < index - 1; i++)
					node = node->next();
			}

			auto new_node = new DoublyLinkedNode<Type>(value);
			new_node->set_next(node->next());
			node->next()->set_prev(new_node);
			node->set_next(new_node);
			new_node->set_prev(node);
		}
		//Removes the node at the specified position
		void remove_at(size_t index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of range!");

			_size--;

			if (index == 0)
			{
				auto node_to_del = _head;
				_head = _head->next();
				_head->set_prev(nullptr);
				delete node_to_del;
				return;
			}

			DoublyLinkedNode<Type>* node = nullptr;

			if (index > _size / 2)
			{
				node = _tail;
				for (size_t i = _size - 1; i > index; i--)
					node = node->prev();

				if (node == _tail)
				{
					pop_back();
					_size++;
				}
				else
				{
					node->prev()->set_next(node->next());
					node->next()->set_prev(node->prev());
					delete node;
				}
			}
			else
			{
				node = _head;
				for (size_t i = 0; i < index - 1; i++)
					node = node->next();

				if (node->next()->next() == nullptr)
				{
					delete node->next();
					node->set_next(nullptr);
					_tail = node;
				}
				else
				{
					auto node_to_del = node->next();
					node->set_next(node->next()->next());
					node->next()->set_prev(node);
					delete node_to_del;
				}
			}
		}
		//Clears the list
		void clear()
		{
			this->~DoublyLinkedList();
		}
	};
}