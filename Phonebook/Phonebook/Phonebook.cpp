#include "stdafx.h"

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