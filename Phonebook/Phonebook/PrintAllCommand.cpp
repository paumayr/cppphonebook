#include "stdafx.h"

#include "PrintAllCommand.hpp"

#include "phonebookapp.hpp"

std::string PrintAllCommand::getName() const
{
	return "Print All";
}

void PrintAllCommand::execute(PhonebookApplication& app)
{
	using namespace std;

	int pageSize = 5;
	int pages = (app.getPhonebook().size() / pageSize) + 1;

	auto& phonebook = app.getPhonebook();
	
	for (int i = 0; i < pages; i++)
	{
		auto items = phonebook.getRange(i * pageSize, pageSize);
		for (auto item : items)
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
