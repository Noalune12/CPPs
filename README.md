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

### EX02
1. generate a random number :
	- `rand()`**
		- **Purpose**: Generates a pseudo-random integer.
		- **Range**: The value returned by `rand()` is between `0` and `RAND_MAX` (a constant defined in `<cstdlib>`, typically `32767`).
		- **Behavior**: `rand()` generates numbers based on an internal state (seed). If the seed is not set explicitly using `srand()`, the default seed is used, which results in the same sequence of numbers every time the program runs.
	- `srand()`**
		- **Purpose**: Sets the seed for the random number generator used by `rand()`.
		- **How It Works**: The seed determines the starting point for the sequence of random numbers. If we call `srand()` with the same seed, `rand()` will produce the same sequence of numbers. To make the sequence different every time the program runs, we can use a changing value (e.g., the current time) as the seed.
	- **Without `srand()`**: The random number generator always starts with the same default seed and the same sequence of numbers every time the program runs will be generated.
	- **With `srand()`**: We can set a custom seed to control the sequence of random numbers. It is best to use time(0) because its value changes every second.

### TODO
[ ] add copy to sopy operator name
