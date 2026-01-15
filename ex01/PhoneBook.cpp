#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0) {}

void PhoneBook::addContact(std::string input[5])
{
	if (size < 8){
		list[size].setData(input);
		++size;
	}	
	else{
		for (int i = 0; i < 7; ++i)
			list[i] = list[i + 1];
		list[7].setData(input);
	}
}

int PhoneBook::getSize() const {
	return size;
}

const Contact& PhoneBook::getContact(int index) const {
	return list[index];
}

std::ostream& operator<<(std::ostream& os, const PhoneBook& pb){
	os << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	for (int i = 0; i < pb.getSize(); ++i) {
        os << pb.getContact(i).lineEntry(i) << std::endl;
    }
    return os;
}
