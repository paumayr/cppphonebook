
#pragma once
#include <string>

class PhonebookApplication;

class MenuCommand
{	
public:
	virtual ~MenuCommand() {};
	
	virtual std::string getName() const = 0;
	virtual void execute(PhonebookApplication& app) = 0;
};