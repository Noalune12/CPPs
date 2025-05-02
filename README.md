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
