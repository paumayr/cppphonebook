#include "stdafx.h"
#include <algorithm>

#include "phonebook.hpp"


PhonebookEntry::PhonebookEntry()
{
}

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

bool operator==(const PhonebookEntry& lh, const PhonebookEntry& rh)
{
	return lh.getFirst() == rh.getFirst() &&
			lh.getLast() == rh.getLast() &&
			lh.getNumber() == rh.getNumber();
}

std::ostream& operator<<(std::ostream& stream, const PhonebookEntry& entry)
{
	stream << entry.getFirst() << " " << entry.getLast() << " - " << entry.getNumber();
	return stream;
}


void Phonebook::addNew(PhonebookEntry entry)
{
	entries.push_back(entry);
}

size_t Phonebook::size() const
{
	return entries.size();
}

std::vector<PhonebookEntry> Phonebook::getRange(int first, int count) const
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

std::vector<PhonebookEntry> Phonebook::findMatches(std::string term)
{
	using namespace std;
	vector<PhonebookEntry> matches;

	copy_if(begin(entries), end(entries), back_inserter(matches), 
		[term](const PhonebookEntry& entry)
	{
		return entry.getFirst().find(term) != string::npos ||
			entry.getLast().find(term) != string::npos ||
			entry.getNumber().find(term) != string::npos;
	});

	return matches;
}
