
#pragma once

#include "MenuCommand.hpp"

class SaveCommand : public MenuCommand
{
public:
	virtual std::string getName() const { return "Save"; }
	virtual void execute(PhonebookApplication& app);

};