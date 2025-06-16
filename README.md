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

### EX03
1. **Pointer to Member Function Syntax**:
   - `AForm* (Intern::*formCreation[3])(std::string) const` is an array of pointers to member functions of the `Intern` class.
   - Each member function in this array:
     - Belongs to the `Intern` class (`Intern::*`).
     - Takes a single `std::string` parameter (`(std::string)`).
     - Returns a pointer to an `AForm` object (`AForm*`).
     - Is marked as `const`, meaning it does not modify the state of the `Intern` object.
	- **Initialization**:
		- The array `formCreation` is initialized with the addresses of the member functions:
     - `this->*formCreation[i]` dereferences the pointer-to-member-function for the current object (`this`).
2. Why need Inter::
   - Member functions of a class are tied to an instance of that class. They require an object (or a pointer to an object) to be called because they implicitly operate on the `this` pointer.
   - When I create a pointer to a member function, I must explicitly specify the class it belongs to. This is why I need to use `Intern::` to indicate that the functions belong to the `Intern` class.
   - If I was to call the function directly (e.g., `createShrubberyForm`), the compiler would interpret it as a regular function, not a member function of `Intern`. This would result in a compilation error because the function is tied to an instance of the `Intern` class and requires the `this` pointer.
   - Using `&Intern::createShrubberyForm` explicitly creates a pointer to the member function, which can later be invoked on an instance of `Intern` using the `this` pointer.
   - A pointer to a member function is not the same as a pointer to a regular function because it needs to account for the `this` pointer.
   - When we dereference a pointer to a member function (e.g., `(this->*formCreation[i])`), the `this` pointer is automatically passed to the function, allowing it to operate on the correct instance of the class.

### TODO
[ ] add copy to copy operator name
[ ] check comment to remove
[ ] put all sources in src and include in inc
