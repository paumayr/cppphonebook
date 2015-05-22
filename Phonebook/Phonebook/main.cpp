// Phonebook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include "phonebook.hpp"

#include <iostream>
#include <memory>

#include "Phonebook.hpp"
#include "phonebookapp.hpp"

#include "AddNewCommand.hpp"
#include "PrintAllCommand.hpp"
#include "SearchCommand.hpp"
#include "UpdateCommand.hpp"
#include "DeleteCommand.hpp"
#include "SaveCommand.hpp"
#include "OpenCommand.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	cout << "Welcome to phonebook!" << endl;

	PhonebookApplication app;

	app.addNewCommand(make_shared<AddNewCommand>());
	app.addNewCommand(make_shared<PrintAllCommand>());
	app.addNewCommand(make_shared<SearchCommand>());
	app.addNewCommand(make_shared<UpdateCommand>());
	app.addNewCommand(make_shared<DeleteCommand>());
	app.addNewCommand(make_shared<SaveCommand>());
	app.addNewCommand(make_shared<OpenCommand>());
	app.mainLoop();

	cout << "thank you for using phonebook." << endl;
	return 0;
}

