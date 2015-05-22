#include "stdafx.h"

#include "phonebookapp.hpp"

#include "MenuCommand.hpp"


Phonebook& PhonebookApplication::getPhonebook()
{
	return phonebook;
}

void PhonebookApplication::addNewCommand(std::shared_ptr<MenuCommand> newCommand)
{
	this->commands.push_back(newCommand);
}

void PhonebookApplication::printMenu()
{
	using namespace std;

	cout << "menu:" << endl << "=====" << endl;

	int i = 1;
	for (auto& command : this->commands)
	{
		cout << i << ") " << command->getName() << endl;
		i++;
	}
}


PhonebookEntry PhonebookApplication::readEntry()
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

bool PhonebookApplication::confirm()
{
	using namespace std;
	string resp = "n";
	cin >> resp;
	return resp == "y" || resp == "yes";
}

bool PhonebookApplication::findEntry(PhonebookEntry& entry)
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

void PhonebookApplication::mainLoop()
{
	using namespace std;
	bool keepRunning = true;

	while (keepRunning)
	{
		printMenu();
		int choice;
		cin >> choice;

		if (choice > 0 && choice <= this->commands.size())
		{
			this->commands[choice - 1]->execute(*this);
		}
		else
		{
			cout << "unknown command" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

