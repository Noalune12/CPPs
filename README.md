### Main concepts
1. **NESTED CLASS**
	- define a class inside a class
	- to instanciate -> Origin::Nested name;

2. **EXCEPTIONS**
	- allow to handle errors
	- try (if (there is an error) -> throw (the exception with std::exception()) // else (do something))  / catch (the exception thrown with std::exception e)
	- e.what
	- try {function() -> the throw is in the function} catch(std::exception& e)
	- class PEBKACException : public std::exception { public: virtul const char* what() const throw() { return ("PROBLEM") } } -> try {something} catch (PEBKACException&  e) { do something } catch (std::exception& e) { do something else }
	