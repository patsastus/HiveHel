#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
	public:
		Contact();
		void setData(const std::string input[5]);
		std::string lineEntry(int index) const;
		const std::string& getField(int index) const;
	private:
		std::string data[5];
};

std::ostream& operator<<(std::ostream& os, const Contact& contact);
