

#include "MenuCommand.hpp"

class DeleteCommand : public MenuCommand
{
public:
	virtual std::string getName() const { return "Delete entry"; }
	virtual void execute(PhonebookApplication& app);

};