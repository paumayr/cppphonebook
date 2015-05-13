// Phonebook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	bool keepRunning = true;

	while (keepRunning)
	{
		string first, last, number;
		cout << "firstname?" << endl;
		cin >> first;
		cout << "lastname?" << endl;
		cin >> last;
		cout << "number?" << endl;
		cin >> number;

		cout << first << " " << last << " - " << number << endl;
	}

	return 0;
}

