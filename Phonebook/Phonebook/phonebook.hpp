#pragma once
#include <string>
#include <vector>


class PhonebookEntry
{
	std::string first;
	std::string last;
	std::string number;

public:
	PhonebookEntry(std::string first, std::string last, std::string number);

	std::string getFirst() const;
	std::string getLast() const;
	std::string getNumber() const;
};

class Phonebook
{
	std::vector<PhonebookEntry> entries;
public:
	void addNew(PhonebookEntry entry)
	{
		entries.push_back(entry);
	}
};