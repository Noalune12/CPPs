#include <iostream>
#include <string>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string* strPtr = &str;
	std::string& strRef = str;

	std::cout << "--- MEMORY ADDRESS ---" << std::endl;
	std::cout << "str = " << &str << std::endl;
	std::cout << "strPtr = " << strPtr << std::endl;
	std::cout << "strRef = " << &strRef << std::endl;
	std::cout << std::endl;
	std::cout << "--- STRING VALUE ---" << std::endl;
	std::cout << "str = " << str << std::endl;
	std::cout << "strPtr = " << *strPtr << std::endl;
	std::cout << "strRef = " << strRef << std::endl;
	return (0);
}
