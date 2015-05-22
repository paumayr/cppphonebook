
#include "stdafx.h"

#include "UpdateCommand.hpp"

#include "phonebookapp.hpp"

void UpdateCommand::execute(PhonebookApplication& app)
{
	using namespace std;
	PhonebookEntry entry;
	if (app.findEntry(entry))
	{
		cout << "found entry (" << entry << "), enter new values:" << endl;
		auto newEntry = app.readEntry();
		cout << "update " << entry << " to " << newEntry << "?" << endl;
		if (app.confirm())
		{
			app.getPhonebook().updateEntry(entry, newEntry);
		}
	}
}
