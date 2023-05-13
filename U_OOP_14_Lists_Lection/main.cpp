#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <ostream>

using data_structures::SinglyLinkedList;
using data_structures::DoublyLinkedList;
using data_structures::List;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::ios;

template <typename T>
void test_list(List<T>& list, fstream& file_stream);
template <typename T>
void print_list_info(const List<T>& list, ostream& os);

int main()
{
	fstream s_list_file("singly_linked_list_test_report.txt", ios::out);
	fstream d_list_file("doubly_linked_list_test_report.txt", ios::out);

	if (!s_list_file.is_open() || !d_list_file.is_open())
	{
		cout << "Error opening files for writing report!" << endl;
		return 0;
	}

	SinglyLinkedList<int> s_list;
	DoublyLinkedList<int> d_list(5);

	cout << "Testing singly linked list..." << endl;
	test_list(s_list, s_list_file);
	s_list_file.close();
	cout << "Done!";

	cout << "\n\nTesting doubly linked list..." << endl;
	test_list(d_list, d_list_file);
	d_list_file.close();
	cout << "Done!";
}

template <typename T>
void print_list_info(const List<T>& list, ostream& os)
{
	os << "\nList size: " << list.size() << endl;
	os << "Empty? " << (list.is_empty() ? "yes" : "no") << endl;
	os << "Values:" << endl;
	for (size_t i = 0; i < list.size(); i++)
		os << list.value_at(i) << " ";
}
template <typename T>
void test_list(List<T>& list, fstream& file_stream)
{
	file_stream << "Initial state of list:";
	print_list_info(list, file_stream);

	for (size_t i = 1; i <= 5; i++)
		list.push_back(static_cast<int>(i * 10));

	file_stream << "\nAfter pushing back 5 values [10-50]:";
	print_list_info(list, file_stream);

	list.push_front(1000);

	file_stream << "\n\nAfter pushing front value 1000:";
	print_list_info(list, file_stream);

	list.pop_back();
	file_stream << "\n\nAfter popping back 1 value:";
	print_list_info(list, file_stream);

	list.pop_front();
	file_stream << "\n\nAfter popping front 1 value:";
	print_list_info(list, file_stream);

	list.set_value(1, 100);
	file_stream << "\n\nList after second value changes to 100:";
	print_list_info(list, file_stream);

	list.insert(0, -100);
	file_stream << "\n\nlist after inserting new value -100 at the beginning:";
	print_list_info(list, file_stream);

	list.insert(list.size() / 2, 500);
	file_stream << "\n\nlist after inserting new value 500 in the middle:";
	print_list_info(list, file_stream);

	list.remove_at(0);
	file_stream << "\n\nlist after removing the first value:";
	print_list_info(list, file_stream);

	list.remove_at(2);
	file_stream << "\n\nlist after removing value at position 2:";
	print_list_info(list, file_stream);

	list.remove_at(list.size() - 1);
	file_stream << "\n\nlist after removing the last value:";
	print_list_info(list, file_stream);

	list.clear();
	file_stream << "\n\nlist after clearing:";
	print_list_info(list, file_stream);
}
