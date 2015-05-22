#include "stdafx.h"

#include <fstream>

#include "SaveCommand.hpp"
#include "phonebookapp.hpp"

void SaveCommand::execute(PhonebookApplication& app)
{
	using namespace std;
	fstream f("c:\\users\\phili_000\\Desktop\\testphonebook.txt", std::ios_base::out);

	for (auto& entry : app.getPhonebook().getRange(0, app.getPhonebook().size()))
	{
		f << entry.getFirst() << " " << entry.getLast() << "-" << entry.getNumber() << endl;
	}

	f.flush();
	f.close();
}
