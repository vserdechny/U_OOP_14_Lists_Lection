#include "SinglyLinkedList.h"
#include <iostream>

using singly_linked_list::SinglyLinkedList;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
void print_sn_list_info(const SinglyLinkedList<T>& list);

int main()
{
	SinglyLinkedList<int> list;

	cout << "Initial state:";
	print_sn_list_info(list);

	for (size_t i = 1; i <= 5; i++)
		list.push_back(static_cast<int>(i * 10));

	cout << "\n\nAfter pushing back 5 values [10-50]:";
	print_sn_list_info(list);

	list.pop_back();
	cout << "\n\nAfter popping back 1 value:";
	print_sn_list_info(list);

	list.set_value(1, 100);
	cout << "\n\n:";
	print_sn_list_info(list);
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