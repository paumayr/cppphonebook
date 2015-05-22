#include "stdafx.h"

#include "AddNewCommand.hpp"

#include "phonebookapp.hpp"

std::string AddNewCommand::getName() const
{
	return "Add New";
}

void AddNewCommand::execute(PhonebookApplication &app)
{
	using namespace std;
	auto entry = app.readEntry();
	cout << "add " << entry << " ? (y/n)" << endl;
	if (app.confirm())
	{
		app.getPhonebook().addNew(entry);
	}
}
