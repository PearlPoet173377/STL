#include<iostream>
#include<string>
#include<map>
#include<list>
#include<forward_list>
#include<Windows.h>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n-----------------\n"

int menu(std::map<std::string, std::forward_list<std::string>>& base);
void print_base(const std::map<std::string, std::forward_list<std::string>>& base);
void add_crime(std::map<std::string, std::forward_list<std::string>>& base);
void crimes_of(std::string id, const std::map<std::string, std::forward_list<std::string>>& base);

void main()
{
	setlocale(LC_ALL, "Rus");
	/*system("CHCP 1251");
	system("CLS");*/
	SetConsoleCP(1251);
	GetConsoleOutputCP();


	std::map<std::string, std::forward_list<std::string>> base =
	{
		std::pair<std::string, std::forward_list<std::string>>("m123kr777", {"red signal" ,"high speed"}),
		std::pair<std::string, std::forward_list<std::string>>("m124kr777", {" wrong place parking"}),
		std::pair<std::string, std::forward_list<std::string>>("m555kr777", {"high speed"}),
		std::pair<std::string, std::forward_list<std::string>>("a555kr178", {"red signal", "bad language"})
	};

	/*print_base(base);
	add_crime(base);
	print_base(base);*/
	/*std::string id;
	cout << "Write auto number: "; cin >> id;
	crimes_of(id, base);*/

	menu(base);
}

int menu(std::map<std::string, std::forward_list<std::string>>& base)
{
	cout << "1. Return all data;" << endl;
	cout << "2. Return data byy number;" << endl;
	cout << "3. Return by diapozon;" << endl;
	cout << "5. Exit;" << endl;
	int choise;
	cin >> choise;
	std::string id;
	switch (choise)
	{
		case 1: print_base(base); break;
		case 2: cout << "Write auto number: "; cin >> id; crimes_of(id, base);
		case 4: add_crime(base); break;
		default: cout << "Crime" << endl;
		case 5: return;
	}
	menu(base);
	return choise;
}

void print_base(const std::map<std::string, std::forward_list<std::string>>& base)
{
	for (std::map<std::string, std::forward_list<std::string>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ":\t";
		for (std::forward_list <std::string>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << *l_it << ", ";
		}
		cout << "\b \b";
		cout << "\b \b";
		cout << ";";
		cout << delimiter;
	}
}

void add_crime(std::map<std::string, std::forward_list<std::string>>& base)
{
	std::string id;
	std::string crime;
	cout << "Write number of auto: "; cin >> id;
	cout << "Write crime: "; 
	cin.ignore();
	getline(cin, crime);
	base[id].push_front(crime);


}

void crimes_of(std::string id, const std::map<std::string, std::forward_list<std::string>>& base)
{
	std::map<std::string, std::forward_list<std::string>>::const_iterator criminal = base.find(id);
	if (criminal != base.end())
	{
		cout << "List of crimes " << id << ":\t";
		for (std::forward_list<std::string>::const_iterator it = criminal->second.begin(); it != criminal->second.end(); it++)
		{
			cout << *it << endl;
		}
	}
}