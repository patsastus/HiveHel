#pragma once
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void addContact(std::string input[5]);
		int getSize() const;
	    const Contact& getContact(int index) const;
	private:
		Contact	list[8];
		int size;
};

std::ostream& operator<<(std::ostream& os, const PhoneBook& book);
