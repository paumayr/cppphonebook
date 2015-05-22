
#pragma once 

#include "MenuCommand.hpp"

class SearchCommand : public MenuCommand
{
public:
	std::string getName() const { return "Search"; };
	void execute(PhonebookApplication& app);
	
};