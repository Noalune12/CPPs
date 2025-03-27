#include <iostream>
#include <cctype> // toupper

/* std::cout = object that allow to have access to the writing console / represent the output stream
	std = namespace with functions, objects and classes
	:: = operator that allow to have access to what is inside std
	cout = object (output stream)
<< : insertion operator that send data to std::cout, handle data stream
std::endl = inserts a newline character into the output sequence and fluch (empty buffer where data is stocked before writing)*/

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)std::toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
