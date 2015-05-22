

#pragma once

#include "MenuCommand.hpp"

class OpenCommand : public MenuCommand
{
public:
	virtual std::string getName() const { return "Open"; }
	virtual void execute(PhonebookApplication& app);
};