#include <fstream>
#include <iostream>
#include <string>

void	replaceString(std::ofstream &outfile, std::string line, std::string find, std::string replace) {
	std::size_t	index;

	index = line.find(find);
	while (index != std::string::npos) {
		outfile << line.substr(0, index);
		outfile << replace;
		line = line.substr(index + find.length());
		index = line.find(find);
	}
	outfile << line;
}

std::string readLine(std::ifstream &file) {
	std::string	line;
	char		c;

	while (file.get(c)) {
		line += c;
		if (c == '\n')
			break;
	}
	return (line);
}

bool	argCheck(std::string replace, std::string find) {
	if (find.empty() || replace.empty()) {

		std::cout << "Error: Argument can't be empty" << std::endl;
		return (false);
	}
	return (true);
}

bool	fileCheck (char **av, std::ifstream &file, std::ofstream &out) {
	std::string outfile;

	file.open(av[1]);
	if (!file.is_open()) {
		std::cout << "Error: Could not open the file : " << av[1] << std::endl;
		return (false);
	}
	outfile = std::string(av[1]) + ".replace";
	out.open(outfile.c_str());
	if (!out.is_open()) {
		std::cout << "Error: Could not open the file : " << outfile << std::endl;
		file.close();
		return (false);
	}
	return (true);
}

int main(int ac, char **av) {
	std::string		find;
	std::string		replace;
	std::string		line;
	std::ifstream	file;
	std::ofstream	out;

	if (ac != 4) {
		std::cout << "You should enter 3 arguments (filename string1 string 2)" << std::endl;
		return (1);
	}
	find = std::string(av[2]);
	replace = std::string(av[3]);
	if (argCheck(replace, find) == false || fileCheck(av, file, out) == false)
		return (1);
	while (file)
	{
		line = readLine(file);
		if (!line.empty())
			replaceString(out, line, find, replace);
	}
	file.close();
	out.close();
	return (0);
}
