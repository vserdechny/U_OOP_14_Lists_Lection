#pragma once
#include <stdexcept>
#include "List.h"
#include "DoublyLinkedNode.h"

namespace data_structures
{
	/*
	Doubly Linked List Implementation
	Author: Serdechny V.S.
	Date: 12.05.2023
	*/

	template <typename Type>
	class DoublyLinkedList : public List<Type>
	{
	private:
		DoublyLinkedNode<Type>* _head{ nullptr };		//pointer to the head of the list
		DoublyLinkedNode<Type>* _tail{ nullptr };		//pointer to the tail of the list

	public:
		//Constructors and destructor
		//**************************************

		//Default constructor
		DoublyLinkedList() {}
		//Constructor that takes as an argument the number of nodes and reserves space for them
		DoublyLinkedList(size_t count)
			:List<Type>(count)
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
			List<Type>::_size = 0;
		}

		//**************************************
		//Access methods
		//**************************************

		//Returns the value from the node at the specified position
		const Type& value_at(size_t index)const override
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == List<Type>::_size - 1)
				return _tail->value();

			DoublyLinkedNode<Type>* node = nullptr;

			//If we need a value from the second part of the list, let's iterate reversed
			if (index > List<Type>::_size / 2)
			{
				node = _tail;
				for (size_t i = List<Type>::_size - 1; i > index; i--)
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
		void set_value(size_t index, const Type& value) override
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == List<Type>::_size - 1)
				_tail->set_value(value);

			DoublyLinkedNode<Type>* node = nullptr;

			//If we need a value from the second part of the list, let's iterate reversed
			if (index > List<Type>::_size / 2)
			{
				node = _tail;
				for (size_t i = List<Type>::_size - 1; i > index; i--)
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
		void push_back(const Type& value) override
		{ 
			if (!_head)
			{
				_head = new DoublyLinkedNode<Type>(value);
				_tail = _head;
			}
			else
			{
				_tail->set_next(new DoublyLinkedNode<Type>(value));
				_tail->next()->set_prev(_tail);
				_tail = _tail->next();
			}

			List<Type>::_size++;
		}
		//Adds a new node to the front of the list
		void push_front(const Type& value) override
		{
			auto node = new DoublyLinkedNode<Type>(value, nullptr, _head);
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
				auto cur_tail = _tail;
				_tail = _tail->prev();
				_tail->set_next(nullptr);
				delete cur_tail;
			}

			List<Type>::_size--;
		}
		//Removes the first node of the list
		void pop_front() override
		{
			if (!_head)
				return;

			auto cur_head = _head;
			_head = _head->next();
			_head->set_prev(nullptr);
			delete cur_head;

			List<Type>::_size--;
		}
		//Inserts a new node with the corresponding value at the specified position
		void insert(size_t index, const Type& value)
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == 0)
				push_front(value);
			else
			{
				DoublyLinkedNode<Type>* node = nullptr;

				if (index > List<Type>::_size / 2)
				{
					node = _tail;
					for (size_t i = List<Type>::_size - 1; i > index; i--)
						node = node->prev();
				}
				else
				{
					node = _head;
					for (size_t i = 0; i < index-1; i++)
						node = node->next();
				}

				auto new_node = new DoublyLinkedNode<Type>(value);
				new_node->set_next(node->next());
				node->next()->set_prev(new_node);
				node->set_next(new_node);
				new_node->set_prev(node);

				List<Type>::_size++;
			}
		}
		//Removes the node at the specified position
		void remove_at(size_t index)
		{
			if (index >= List<Type>::_size)
				throw std::out_of_range("Index out of range!");

			if (index == 0)
				pop_front();
			else if (index == List<Type>::_size - 1)
				pop_back();
			else
			{
				DoublyLinkedNode<Type>* node = nullptr;

				if (index > List<Type>::_size / 2)
				{
					node = _tail;
					for (size_t i = List<Type>::_size - 1; i > index; i--)
						node = node->prev();

					node->prev()->set_next(node->next());
					node->next()->set_prev(node->prev());
					delete node;
				}
				else
				{
					node = _head;
					for (size_t i = 0; i < index - 1; i++)
						node = node->next();

					auto node_to_del = node->next();
					node->set_next(node->next()->next());
					node->next()->set_prev(node);
					delete node_to_del;
				}
				List<Type>::_size--;
			}
		}
		//Clears the list
		void clear()
		{
			this->~DoublyLinkedList();
		}
	};
}