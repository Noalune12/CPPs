### Diffenrence between pointer and reference
1. Pointers:
- variable that holds the memory address of another variable. A pointer needs to be dereferenced with the * operator to access the memory location it points to.
- A pointer can be re-assigned.

2. References:
- another name for an already existing variable. A reference, like a pointer, is also implemented by storing the address of an object.
- A reference cannot be re-assigned, and must be assigned at initialization.

3. Diffenreces:
- Reassignation only possible for pointer
- A pointer has its own memory address and size on the stack, whereas a reference shares the same memory address with the original variable and takes up no space on the stack.
- A pointer is sotring the address of the var while a ref is referring to another var.
- A pointer can be assigned NULL directly, whereas a reference cannot be.
- We can have a pointer to pointer (known as a double pointer) offering extra levels of indirection, whereas references only offer one level of indirection. (int **q; // It is valid. VS int &&q = p; // It is reference to reference, so it is an error)
- Reference = pass by value VS pointer = pass by reference (int &p = a VS int *p = &a)


### Ex03
1. Ref for getType
- ref = club.getType(); // Get the value of _type but it makes a copie of the value
- const std::string& ref = club.getType(); // Store the const reference and it does not make a copy
2. setType
- used to modify _type
- pass a reference -> no copy (more efficient), the function get directly the origin of the object
- pass a value -> a new instance of the string is allocated in memory, the content of the string of origin is copied on the new instance, once the function is done, the copy is destroyed
3. Interest pointer vs reference for human a vs human b
- HumanA weapon as a reference : must have a weapon to be created, no NULL, direct access, cannot change weapon -> always has a valid weapon
- HumanB weapon as a pointer : can create without weapon, NULL -> change weapon dynamically

### Ex04
- ifstream : input file stream + ifs() -> create file
- ofstream : output file stream
- concatenate filename + .replace by casting filename to std::string then to ofstream need to convert it back to const char* with .c_str()
- find -> if nothing is found npos is returned which is the highest value possible for a size_t -> index == std::string::npos means that the string was not found
- https://medium.com/@ryan_forrester_/file-handling-with-getline-in-c-a-comprehensive-guide-51555631b14f
