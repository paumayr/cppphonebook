// Phonebook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include "phonebook.hpp"

class PhonebookApplication
{
	Phonebook phonebook;

public:
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

	void search()
	{
		using namespace std;
		cout << "search!" << endl;
	}

	void addNew()
	{
		using namespace std;
		
		string first, last, number;
		cout << "firstname?" << endl;
		cin >> first;
		cout << "lastname?" << endl;
		cin >> last;
		cout << "number?" << endl;
		cin >> number;
		cout << "add " << first << " " << last << " - " << number << " ? (y/n)" << endl;
		string add = "n";
		cin >> add;
		if (add == "y" || add == "yes")
		{
			phonebook.addNew(PhonebookEntry(first, last, number));
		}
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

		int pageSize = 5;
		int pages = (phonebook.size() / pageSize) + 1;

		for (int i = 0; i < pages; i++)
		{
			auto items = phonebook.getRange(i * pageSize, pageSize);
			for(auto item : items)
			{
				cout << item.getFirst() << " " << item.getLast() << " - " << item.getNumber() << endl;
			}

			if (i != pages - 1)
			{
				cout << "--- next page ---" << endl;

				string next;
				getline(cin, next);
				if (next.length() > 0 && next[0] == 'q')
				{
					break;
				}
			}
		}
	}

	void mainLoop()
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
			case 1:
				search();
				break;
			case 2:
				addNew();
				break;
			case 3:
				updateExisting();
				break;
			case 4:
				deleteEntry();
				break;
			case 5:
				printAll();
				break;
			case 6:
				keepRunning = false;
				break;
			}
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	cout << "Welcome to phonebook!" << endl;

	PhonebookApplication app;
	app.mainLoop();

	cout << "thank you for using phonebook." << endl;
	return 0;
}

