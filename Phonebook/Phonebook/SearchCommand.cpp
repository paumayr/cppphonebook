#include "stdafx.h"

#include <iostream>
#include "SearchCommand.hpp"

#include "phonebookapp.hpp"

void SearchCommand::execute(PhonebookApplication& app)
{
	using namespace std;
	cout << "enter search term: " << endl;
	string term;
	cin >> term;

	auto results = app.getPhonebook().findMatches(term);

	cout << "found " << results.size() << " results:" << endl;
	for (auto r : results)
	{
		cout << r << endl;
	}
}