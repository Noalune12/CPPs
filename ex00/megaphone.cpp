#include <iostream>

/* std::cout = object that allow to have access to the writing console / represent the output stream
	std = namespace with functions, objects and classes
	:: = operator that allow to have access to what is inside std
	cout = object (output stream)
<< : insertion operator that send data to std::cout, handle data stream
std::endl = inserts a newline character into the output sequence and fluch (empty buffer where data is stocked before writing)*/

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		std::cout << "no arguments" << std::endl;
	return (0);
}
