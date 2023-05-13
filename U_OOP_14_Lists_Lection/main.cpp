#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "List.h"
#include <iostream>

using data_structures::SinglyLinkedList;
using data_structures::DoublyLinkedList;
using data_structures::List;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
void test_list(List<T>& list);
template <typename T>
void print_list_info(const List<T>& list);

int main()
{
	SinglyLinkedList<int> s_list;
	DoublyLinkedList<int> d_list(5);

	cout << "Singly Linked list test:\n\n";
	test_list(s_list);
}

template <typename T>
void print_list_info(const List<T>& list)
{
	cout << "\nList size: " << list.size() << endl;
	cout << "Empty? " << (list.is_empty() ? "yes" : "no") << endl;
	cout << "Values:" << endl;
	for (size_t i = 0; i < list.size(); i++)
		cout << list.value_at(i) << " ";
}
template <typename T>
void test_list(List<T>& list)
{
	cout << "Initial state of list:";
	print_list_info(list);

	for (size_t i = 1; i <= 5; i++)
		list.push_back(static_cast<int>(i * 10));

	cout << "\nAfter pushing back 5 values [10-50]:";
	print_list_info(list);

	list.pop_back();
	cout << "\n\nAfter popping back 1 value:";
	print_list_info(list);

	list.set_value(1, 100);
	cout << "\n\nList after second value changes to 100:";
	print_list_info(list);

	list.insert(0, -100);
	cout << "\n\nlist after inserting new value -100 at the beginning:";
	print_list_info(list);

	list.insert(list.size() / 2, 500);
	cout << "\n\nlist after inserting new value 500 in the middle:";
	print_list_info(list);

	list.remove_at(0);
	cout << "\n\nlist after removing the first value:";
	print_list_info(list);

	list.remove_at(2);
	cout << "\n\nlist after removing value at position 2:";
	print_list_info(list);

	list.remove_at(list.size() - 1);
	cout << "\n\nlist after removing the last value:";
	print_list_info(list);

	list.clear();
	cout << "\n\nlist after clearing:";
	print_list_info(list);
}
