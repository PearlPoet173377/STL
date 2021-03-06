#include<iostream>
#include<list>
#include<forward_list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------\n"

//#define Unique
//#define LIST

template<typename T>inline void list_properties(const std::list<T>& lst)
{
	cout << "Size:    " << lst.size() << endl;
	cout << "MaxSize: " << lst.max_size() << endl;
}
template<typename T>void print_list(const std::list<T>& lst)
{
	if (lst.empty())
	{
		cout << "List is empty" << endl;
	}
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}



class list_wrapper
{
	std::list<int> lst;
};

bool more_than_10(const int& value)
{
	return value > 10;
}

void main()
{
#ifdef LIST
	//list - ??? ?????????, ??????? ?????? ?????? ? ???? ??????????? ??????
	cout << more_than_10 << endl;
	std::list<int> lst = { 3, 5, 8, 13, 21 };
	cout << "Empty list size: " << sizeof(list_wrapper) << endl;
	list_properties(lst);
	print_list(lst);
	lst.push_front(2);
	lst.push_back(34);
	for (int i : lst)cout << i << tab; cout << endl;
	list_properties(lst);

	/*int index;
	int value;
	cout << "??????? ?????? ???????????? ????????: "; cin >> index;
	cout << "??????? ???????? ???????????? ????????: "; cin >> value;
	std::list<int>::iterator position = lst.begin();
	for (int i = 0; i < index; i++)position++;
	lst.insert(position, value);*/
	//print_list(lst);
	lst.resize(20);
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		//cout << *it << tab;
		*it = rand() % 10;
	}
	cout << endl;
	/*lst.resize(25);
	lst.remove(0);
	lst.remove_if(more_than_10);*/
#ifdef Unique
	lst.sort();
	for (int i : lst)cout << i << tab; cout << endl;
	lst.unique();
	cout << delimiter << endl;
	for (int i : lst)cout << i << tab; cout << endl;
	lst.reverse();
	cout << delimiter << endl;
	for (int i : lst)cout << i << tab; cout << endl;
#endif
#endif

	/*std::list<int>lst1 = { 3, 5, 8, 13, 21 };
	std::list<int>lst2 = { 34,55,89 };
	lst1.merge(lst2);
	print_list(lst1);
	*/

	/*for (int i = 0; i < lst.size(); i++)
	{
		cout << lst[i] << tab;
	}
	cout << endl;*/

	std::forward_list<int> flst = { 3,5,8,13,21 };
	flst.push_front(34);
	for (std::forward_list<int>::iterator it = flst.begin(); it != flst.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	int index;
	int value;
	cout << "Write index: "; cin >> index;
	cout << "Write value: "; cin >> value;

	std::forward_list<int>::iterator position = flst.before_begin();
	for (int i = 0; i < index; i++)position++;
	flst.insert_after(position, value);
	for (int i : flst)cout << i << tab; cout << endl;

}