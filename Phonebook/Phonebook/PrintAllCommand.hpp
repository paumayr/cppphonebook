
#pragma once
#include "MenuCommand.hpp"

class PrintAllCommand : public MenuCommand
{
public:
	virtual std::string getName() const override;
	virtual void execute(PhonebookApplication& app) override;

};