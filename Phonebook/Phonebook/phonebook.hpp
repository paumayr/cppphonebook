#pragma once
#include <string>
#include <vector>


class PhonebookEntry
{
	std::string first;
	std::string last;
	std::string number;

public:
	PhonebookEntry();
	PhonebookEntry(std::string first, std::string last, std::string number);

	std::string getFirst() const;
	std::string getLast() const;
	std::string getNumber() const;
};

bool operator==(const PhonebookEntry& lh, const PhonebookEntry& rh);

std::ostream& operator<<(std::ostream& stream, const PhonebookEntry& entry);

class Phonebook
{
	std::vector<PhonebookEntry> entries;
public:
	void addNew(PhonebookEntry entry);

	size_t size() const;
	std::vector<PhonebookEntry> getRange(int first, int count) const;
	std::vector<PhonebookEntry> findMatches(std::string term) const;
	void updateEntry(PhonebookEntry old, PhonebookEntry newEntry);
	void remove(PhonebookEntry entry);
};