// Phonebook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

void printMenu()
{
	using namespace std;

	cout << "menu:" << endl << "=====" << endl;

	cout << "1) search" << endl;
	cout << "2) add new" << endl;
	cout << "3) update existing" << endl;
	cout << "4) delete" << endl;
	cout << "5) print all" << endl;
	cout << "6) quit" << endl;
}

void newContact()
{
	using namespace std;

	string first, last, number;
	cout << "firstname?" << endl;
	cin >> first;
	cout << "lastname?" << endl;
	cin >> last;
	cout << "number?" << endl;
	cin >> number;
	cout << first << " " << last << " - " << number << endl;
}

void search()
{
	using namespace std;
	cout << "search!" << endl;
}

void addNew()
{
	using namespace std;
	cout << "addNew!" << endl;
}

void updateExisting()
{
	using namespace std;
	cout << "updateExisting!" << endl;
}

void deleteEntry()
{
	using namespace std;
	cout << "deleteEntry!" << endl;
}

void printAll()
{
	using namespace std;
	cout << "printAll!" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	bool keepRunning = true;

	while (keepRunning)
	{
		printMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1: // search
			search();
			break;
		case 2: // add new 
			addNew();
			break;
		case 3: // update existing
			updateExisting();
			break;
		case 4: // delete
			deleteEntry();
			break;
		case 5: // print all
			printAll();
			break;
		case 6: // quit
			keepRunning = false;
			break;
		}
	}

	cout << "thank you for using phonebook." << endl;
	return 0;
}

