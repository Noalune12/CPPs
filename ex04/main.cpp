#include <fstream>
#include <iostream>
#include <string>

void	replaceString(std::ofstream &outfile, std::string line, std::string find, std::string replace) {
	std::size_t	index;

	while ((index = line.find(find)) != std::string::npos) {
		outfile << line.substr(0, index);
		outfile << replace;
		line = line.substr(index + find.length());
	}
	outfile << line;
}

bool	getLastChar(std::ifstream &file) {
	file.seekg(-1, std::ios::end); // go to the last caracter
	char lastChar;
	file.get(lastChar); //get the last caracter
	file.clear(); //reinit indicator of the file like EOF
	file.seekg(0, std::ios::beg); //go back to beginning
	if (lastChar == '\n')
		return (true);
	return (false);
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "You should enter 3 arguments (filename find replace)" << std::endl;
		return (1);
	}

	std::string find = std::string(av[2]);
	std::string replace = std::string(av[3]);
	if (find.empty() || replace.empty()) {
		std::cout << "Error: Argument can't be empty" << std::endl;
		return (1);
	}

	std::ifstream	file(av[1]);
	if (!file.is_open()) {
		std::cout << "Error: Could not open the file : " << av[1] << std::endl;
		return (1);
	}

	std::string outfile = std::string(av[1]) + ".replace";
	std::ofstream	out(outfile.c_str());
	if (!out.is_open()) {
		std::cout << "Error: Could not open the file : " << outfile << std::endl;
		file.close();
		return (1);
	}

	file.seekg(0, std::ios::end); //position at the end to get the len of the file with tellg
	std::streampos length = file.tellg(); //return position of cursor (0 if empty)
	if (length == 0)
		return 0;
	bool newLine = getLastChar(file);

	std::string		line;
	while (getline(file, line)) {
		replaceString(out, line, find, replace);
		if (file.peek() != EOF)
			out << std::endl;
	}
	if (newLine == true)
		out << std::endl;

	file.close();
	out.close();
	return (0);
}
