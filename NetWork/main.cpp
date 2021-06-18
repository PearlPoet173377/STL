#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<algorithm>
#include<direct.h>
using namespace std;
using std::cin;
using std::endl;
using std::cout;

#define tab "\t"

//#define WAL

void main()
{
#ifdef WAL

	string source_file_name;
	string destination_file_name;
	string ext = ".txt";

	cout << "Write source file name: "; getline(cin, source_file_name);
	cout << "Write destination file name: "; getline(cin, destination_file_name);
	
	if (source_file_name.find(ext) == string::npos)
	{
		source_file_name += ext;
	}

	if (destination_file_name.find(ext) == string::npos)
	{
		destination_file_name += ext;
	}

	ifstream fin(source_file_name);

	string IP;
	string MAC;

	if (fin.is_open())
	{
		ofstream fout(destination_file_name);
		while (fin>>IP>>MAC)
		{
			cout << MAC << tab << IP << endl;
			fout << MAC << tab << IP << endl;
		}
		fout.close();
		string cmd = "notepad" + destination_file_name;
		system(cmd.c_str());
	}
	else
	{
		cerr << "\nFile not found" << endl;
	}
	
	fin.close();
#endif

	string room_number;
	cout << "Write room number: "; cin >> room_number;

	string directory = "Files";
	_chdir(directory.c_str());

	string source_file_name = room_number+" RAW.txt";
	string dhcpd_file_name = room_number+".dhcpd";
	string wal_file_name = room_number + ".wal";
	string mac, ip;

	ifstream fin(source_file_name);
	if (fin.is_open())
	{
		ofstream dhcpd_fout(dhcpd_file_name);
		ofstream wal_fout(wal_file_name);
		for (int i = 1; fin >> ip >> mac; i++)
		{
			wal_fout << mac << tab << ip << endl;
			std::replace(mac.begin(), mac.end(), '-', ':');
			cout << "host-" << i<<endl;
			cout << "{";
			cout << "\thardware ethernet\t" << mac << ";\n";
			cout << "\tfixed_address\t\t" << ip << ";\n";
			cout << "}\n";
			cout << endl;

			dhcpd_fout << "host-" << i << endl;
			dhcpd_fout << "{";
			dhcpd_fout << "\thardware ethernet\t" << mac << ";\n";
			dhcpd_fout << "\tfixed_address\t\t" << ip << ";\n";
			dhcpd_fout << "}\n";
			dhcpd_fout << endl;
		}
		//string cmd = "notepad" + destination_file_name;
		string cmd = "start notepad ";
		system((cmd + wal_file_name).c_str());
		system((cmd + dhcpd_file_name).c_str());
	}
	else
	{
		cout << "File not found" << endl;
	}

	fin.close();

}