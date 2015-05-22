
#include "stdafx.h"

#include "DeleteCommand.hpp"
#include "phonebookapp.hpp"

void DeleteCommand::execute(PhonebookApplication& app)
{
	using namespace std;
	PhonebookEntry entry;
	if (app.findEntry(entry))
	{
		cout << "found entry (" << entry << "), remove?" << endl;
		if (app.confirm())
		{
			app.getPhonebook().remove(entry);
		}
	}
}
