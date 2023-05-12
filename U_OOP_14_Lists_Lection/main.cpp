#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>

using data_structures::SinglyLinkedList;
using data_structures::DoublyLinkedList;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
void print_sn_list_info(const SinglyLinkedList<T>& list);
template <typename T>
void print_db_list_info(const DoublyLinkedList<T>& list);

void singly_linked_list_test();
void doubly_linked_list_test();

int main()
{
	//singly_linked_list_test();
	doubly_linked_list_test();
}

void singly_linked_list_test()
{
	SinglyLinkedList<int> list, list2(10);

	cout << "Initial state of list #1:";
	print_sn_list_info(list);
	cout << "\n\nInitial state of list #2:";
	print_sn_list_info(list2);

	for (size_t i = 1; i <= 5; i++)
		list.push_back(static_cast<int>(i * 10));

	cout << "\n\nAfter pushing back 5 values [10-50]:";
	print_sn_list_info(list);

	list.pop_back();
	cout << "\n\nAfter popping back 1 value:";
	print_sn_list_info(list);

	list.set_value(1, 100);
	cout << "\n\nList after second value changes to 100:";
	print_sn_list_info(list);

	list.insert(0, -100);

	cout << "\n\nlist after inserting new value -100 at the beginning:";
	print_sn_list_info(list);

	list.insert(list.size() / 2, 500);

	cout << "\n\nlist after inserting new value 500 in the middle:";
	print_sn_list_info(list);

	list.remove_at(0);

	cout << "\n\nlist after removing the first value:";
	print_sn_list_info(list);

	list.remove_at(2);

	cout << "\n\nlist after removing value at position 2:";
	print_sn_list_info(list);

	list.remove_at(list.size() - 1);

	cout << "\n\nlist after removing the last value:";
	print_sn_list_info(list);

	list.clear();

	cout << "\n\nlist after clearing:";
	print_sn_list_info(list);
}

void doubly_linked_list_test()
{
	DoublyLinkedList<int> list(10);

	list.set_value(0, 100);
	list.set_value(8, 500);

	cout << "Source doubly-linked list:";
	print_db_list_info(list);

	for (size_t i = 1; i <= 3; i++)
		list.push_back(static_cast<int>(i));

	cout << "\n\nDoubly-linked list after pushing back 3 values [1-3]:";
	print_db_list_info(list);

	list.pop_back();

	cout << "\n\nDoubly-linked list after popping back 1 value:";
	print_db_list_info(list);
}

template <typename T>
void print_db_list_info(const DoublyLinkedList<T>& list)
{
	cout << "\nList size: " << list.size() << endl;
	cout << "Empty? " << (list.is_empty() ? "yes" : "no") << endl;
	cout << "Values:" << endl;
	for (size_t i = 0; i < list.size(); i++)
		cout << list.value_at(i) << " ";
}

template <typename T>
void print_sn_list_info(const SinglyLinkedList<T>& list)
{
	cout << "\nList size: " << list.size() << endl;
	cout << "Empty? " << (list.is_empty() ? "yes" : "no") << endl;
	cout << "Values:" << endl;
	for (size_t i = 0; i < list.size(); i++)
		cout << list.value_at(i) << " ";
}