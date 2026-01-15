#include "Harl.hpp"

static void message(std::string &input, Harl &harl){
	std::cout << "[ " << input << " ]" << std::endl;
	harl.complain(input);
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <argument>" <<std::endl;
		return 1;
	}
	Harl instance;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	std::string level = std::string(argv[1]);
	for (; i < 4 && levels[i] != level; i++);
	switch(i){
		case 0:
			message(levels[0], instance);
		case 1:
			message(levels[1], instance);
		case 2:
			message(levels[2], instance);
		case 3:
			message(levels[3], instance);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" <<std::endl;
	}
	return 0;
}
