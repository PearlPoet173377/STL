#include<iostream>
#include<fstream>
using namespace std;

void main()
{

	/*//cout << "HelloWorld";
	ofstream fout;//create stream
	fout.open("File.txt", ios_base::app);//open stream
	fout << "HelloWorld" << endl;
	fout.close();//streams must be closed
	system("notepad File.txt");*/

	/*ifstream fin;
	fin.open("File.txt");
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof())//end of file
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: File not found" << endl;
	}
	fin.close();*/

	/*ofstream fout;
	ifstream fin;
	fout.open("Copy.txt");
	fin.open("File.txt");

	const int n = 256;
	char buffer[n] = {};

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, n);
			fout << buffer;
		}
	}

	else
	{
		cout << "Error: File not found" << endl;
	}

	fin.close();
	fout.close();
	system("notepad Copy.txt");*/



}