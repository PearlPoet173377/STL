#include <iostream>
#include<string>
#include<map>
#include <list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void main()
{

	/*std::map<int, std::string>week =
	{
		std::pair<int , std::string>(0, "Sunday"),
		std::pair<int , std::string>(1, "Monday"),
		std::pair<int , std::string>(2, "Tuesday"),
		std::pair<int , std::string>(3, "Wednesday"),
		std::pair<int , std::string>(4, "Thursday"),
		std::pair<int , std::string>(5, "Friday"),
		std::pair<int , std::string>(6, "Saturday")
	};

	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab << it->second << endl;
	}*/

	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("finite", {"ograniceniy", "imeuciy predel"}),
		std::pair<std::string, std::list<std::string>>("adjacent", {"sosedniy", "smejniy"}),
		std::pair<std::string, std::list<std::string>>("plot", {"karta", "plan", "grafik", "syujet"}),
		std::pair<std::string, std::list<std::string>>("incident", {"sluchay", "proishestvie"}),
		std::pair<std::string, std::list<std::string>>("splice", {"soedinenie", "sracevivanie"}),
	};
	
	//std::cout << dictionary["finite"] << endl;
	std::cout << dictionary["finite"].front() << std::endl;
	dictionary["space"].assign({ "prostranstvo","kosmos","probel" });
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		std::cout << it->first << ":";
		std::cout.width(20);
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			std::cout << *jt << ", ";
		}
		std::cout << endl;
	}
	std::cout << dictionary.find("finite")->first << tab;
	for (std::string i : dictionary.find("finite")->second)std::cout << i << tab; std::cout << std::endl;
}