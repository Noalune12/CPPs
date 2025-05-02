#include <fstream>
#include <iostream>

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "You should enter 3 arguments (filename string1 string 2)" << std::endl;
		return (1);
	}
	// open filename + protection
	std::ifstream	file(av[1]);
	if (!file.is_open()) {
		std::cout << "Error: Could not open the file : " << av[1] << std::endl;
		return (1);
	}
	// read the file and copy + replace the string1 by string2 in filename.replace


	// std::ifstream	ifs("numbers");
	// unsigned int dst;
	// unsigned int dst2;

	// ifs >> dst >> dst2;

	// std::cout << dst << " " << dst2 << std::endl;
	// ifs.close();

	// std::ofstream ofs("test.out");

	// ofs << "i am trying th fstream" << std::endl;
	// ofs.close();
	return (0);
}
