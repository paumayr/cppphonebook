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
		cout << "enter search term: " << endl;
		string term;
		cin >> term;

		auto results = phonebook.findMatches(term);

		cout << "found " << results.size() << " results:" << endl;
		for (auto r : results)
		{
			cout << r << endl;
		}
	}

	PhonebookEntry readEntry()
	{
		using namespace std;
		string first, last, number;
		cout << "firstname?" << endl;
		cin >> first;
		cout << "lastname?" << endl;
		cin >> last;
		cout << "number?" << endl;
		cin >> number;

		return PhonebookEntry{ first, last, number };
	}

	bool confirm()
	{
		using namespace std;
		string resp = "n";
		cin >> resp;
		return resp == "y" || resp == "yes";
	}

	void addNew()
	{
		using namespace std;
		auto entry = readEntry();
		cout << "add " << entry << " ? (y/n)" << endl;
		if (confirm())
		{
			phonebook.addNew(entry);
		}
	}

	bool findEntry(PhonebookEntry& entry)
	{
		using namespace std;
		while (true)
		{
			cout << "enter search term for finding update to update: " << endl;
			string term;
			cin >> term;

			if (term == "q")
			{
				return false;
			}

			auto results = phonebook.findMatches(term);

			if (results.size() == 1)
			{
				entry = results[0];
				return true;
			}
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
		PhonebookEntry entry;
		if (findEntry(entry))
		{
			cout << "found entry (" << entry << "), remove?" << endl;
			if (confirm())
			{
				phonebook.remove(entry);
			}
		}
	}

	void printAll() const
	{
		using namespace std;

		int pageSize = 5;
		int pages = (phonebook.size() / pageSize) + 1;

		for (int i = 0; i < pages; i++)
		{
			auto items = phonebook.getRange(i * pageSize, pageSize);
			for(auto item : items)
			{
				cout << item << endl;
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
			default:
				cout << "unknown command" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

