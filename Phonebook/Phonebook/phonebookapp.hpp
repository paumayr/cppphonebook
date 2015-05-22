#pragma once

#include <iostream>
#include <memory>
#include "Phonebook.hpp"

class MenuCommand;

class PhonebookApplication
{
	Phonebook phonebook;

	std::vector<std::shared_ptr<MenuCommand>> commands;
public:
	void addNewCommand(std::shared_ptr<MenuCommand> newCommand);

	Phonebook& getPhonebook();

	void printMenu();
	PhonebookEntry readEntry();
	bool confirm();
	bool findEntry(PhonebookEntry& entry);
	void updateExisting();
	void deleteEntry();
	void printAll() const;
	void mainLoop();
};
