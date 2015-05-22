
#pragma once

#include "MenuCommand.hpp"

class UpdateCommand : public MenuCommand
{
public:
	virtual std::string getName() const { return "Update Entry"; }
	virtual void execute(PhonebookApplication& app);
};