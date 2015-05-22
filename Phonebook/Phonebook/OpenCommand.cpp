#include "stdafx.h"
#include "OpenCommand.hpp"

#include "phonebookapp.hpp"
#include <fstream>

void OpenCommand::execute(PhonebookApplication& app)
{
	using namespace std;
	fstream f("c:\\users\\phili_000\\Desktop\\testphonebook.txt", std::ios_base::in);

	std::string line;
	while (!f.eof())
	{
		std::getline(f, line);

		if (!f.eof())
		{
			auto firstSplit = line.find(' ');
			auto numberSplit = line.find('-', firstSplit + 1);

			auto first = line.substr(0, firstSplit);
			auto last = line.substr(firstSplit + 1, numberSplit - firstSplit - 1);
			auto number = line.substr(numberSplit + 1);

			app.getPhonebook().addNew(PhonebookEntry(first, last, number));
		}
	}
}
