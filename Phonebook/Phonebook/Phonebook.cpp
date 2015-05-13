#include "stdafx.h"
#include <algorithm>

#include "phonebook.hpp"


PhonebookEntry::PhonebookEntry(std::string first, std::string last, std::string number)
	: first(first), last(last), number(number)
{
}

std::string PhonebookEntry::getFirst() const
{
	return first;
}

std::string PhonebookEntry::getLast() const
{
	return last;
}

std::string PhonebookEntry::getNumber() const
{
	return number;
}


void Phonebook::addNew(PhonebookEntry entry)
{
	entries.push_back(entry);
}

size_t Phonebook::size()
{
	return entries.size();
}

std::vector<PhonebookEntry> Phonebook::getRange(int first, int count)
{
	using namespace std;

	vector<PhonebookEntry> result;

	if (entries.size() > 0 && first < entries.size())
	{
		auto begin = entries.begin() + first;
		auto end = (first + count) < entries.size() ? begin + count : entries.end();

		begin = begin < entries.end() ? begin : entries.end();
		end = end < entries.end() ? end : entries.end();

		std::copy(begin, end, back_inserter(result));
	}

	return result;
}
