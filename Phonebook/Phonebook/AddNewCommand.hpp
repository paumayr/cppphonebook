#pragma once

#include "MenuCommand.hpp"

class AddNewCommand : public MenuCommand
{
public:
	virtual std::string getName() const;

	virtual void execute(PhonebookApplication& app);

};