#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain {

	public:
		Brain();
		Brain(Brain const& src);
		~Brain();

		Brain& operator=(Brain const& name);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string add);

	private: // protected ??
		std::string ideas[100];
};

#endif
