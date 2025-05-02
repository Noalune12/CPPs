#include <fstream>
#include <iostream>

void	replaceString(std::ofstream &outfile, std::string line, std::string find, std::string replace) {
	std::size_t	index;

	index = line.find(find);
	while (index != std::string::npos) {
		outfile << line.substr(0, index);
		outfile << replace;
		line = line.substr(index + find.length());
		index = line.find(find);
	}
	outfile << line << std::endl;
}

int main(int ac, char **av) {
	std::string outfile;
	std::string	find;
	std::string	replace;
	std::string	line;

	if (ac != 4) {
		std::cout << "You should enter 3 arguments (filename string1 string 2)" << std::endl;
		return (1);
	}
	std::ifstream	file(av[1]);
	if (!file.is_open()) {
		std::cout << "Error: Could not open the file : " << av[1] << std::endl;
		return (1);
	}
	outfile = std::string(av[1]) + ".replace";
	std::ofstream	out(outfile.c_str());
	if (!out.is_open()) {
		std::cout << "Error: Could not open the file : " << outfile << std::endl;
		file.close();
		return (1);
	}
	find = std::string(av[2]);
	replace = std::string(av[3]);
	while (getline(file, line))
		replaceString(out, line, find, replace);
	file.close();
	out.close();
	return (0);
}
