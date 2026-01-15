#include "Contact.hpp"

Contact::Contact(){
	for (int i = 0; i < 5; ++i)
		data[i] = "";
}

void	Contact::setData(const std::string input[5]){
	for (int i = 0; i < 5; ++i)
		data[i] = input[i];
}

std::string Contact::lineEntry(int index) const
{
	std::ostringstream	oss;
	oss << "|         " << std::setw(1) << index << "|";
	for (int i = 0; i < 3; ++i){
		std::string formatted = data[i];
		if (formatted.length() > 10)
			formatted = formatted.substr(0, 9) + ".";
		oss << std::setw(10) << formatted << "|";
	}
	return (oss.str());
}

const std::string& Contact::getField(int index) const{
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
	const char *explanations[] = {"First Name", "Last Name", "Nickname", "Telephone", "Secret"};
    for (int i = 0; i < 5; ++i) {
        os << std::left<< std::setw(10) << explanations[i] << std::right << ": " <<contact.getField(i) << std::endl;
    }
    return os;
}
