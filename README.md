# CPP04

### Main info
1. Polymorphism
	- It allows objects of different types to be treated as objects of a common supertype. It is typically achieved through **inheritance** and **virtual functions**.
	- There are two main types of polymorphism.
	- **Compile-time Polymorphism** (or Static Polymorphism): Achieved using function overloading and operator overloading. The method to be invoked is determined at compile time.
	- Function overloading : The names of the functions and return types are the same but differ in the type of arguments. OR The name of the functions and return types are the same, but they differ in the number of arguments. (void print(int x); VS void print(std::string s);)
	- **Run-time Polymorphism** (or Dynamic Polymorphism): Achieved using virtual functions and pointers/references to base classes. The method to be invoked is determined at runtime based on the type of the object.
	- Function Overriding is when more than one method of the derived class has the same name, the same number of parameters, and the same parameter type as of base class.
	- A virtual function in C++ is a base class member function. In a derived class, we can redefine it. The virtual function must be declared using the keyword virtual in the base class. A class that declares or inherits a virtual function is called a polymorphic class.
	- class Base { virtual void display() { std::cout << "Base"; }}; + class Derived : public Base { void display() override { std::cout << "Derived"; }}; -> Base* obj = new Derived(); obj->display(); // Outputs "Derived"
	- Polymorphism enables **behavioral flexibility**—the same interface can be used to invoke different implementations depending on the object's type.

2. Subtyping
	- Subtyping refers to the relationship between types where one type (the subtype) is considered a specialized version of another type (the supertype). Subtyping is a **type hierarchy** concept.
	- class Animal { virtual void speak() = 0; }; + class Dog : public Animal { void speak() override { std::cout << "Woof"; }}; + void makeAnimalSpeak(Animal* animal) { animal->speak();} -> Dog dog; makeAnimalSpeak(&dog); // Works because Dog is a subtype of Animal

3. **Key Differences**
| **Aspect**            | **Polymorphism**                          | **Subtyping**                              |
|------------------------|-------------------------------------------|--------------------------------------------|
| **Definition**         | Behavior that varies depending on the object's type. | Relationship between types (subtype and supertype). |
| **Focus**             | Focuses on **behavior** (methods).        | Focuses on **type hierarchy**.             |
| **Implementation**    | Achieved through virtual functions, method overriding, etc. | Achieved through inheritance or type definitions. |
| **Purpose**           | Enables dynamic behavior at runtime.      | Enables type compatibility and code reuse. |
| **Example**           | A `Base` pointer calling a `Derived` method. | A `Dog` being treated as an `Animal`.      |


4. Abstract classes
	- **Pure method**: `virtual void X() = 0;` -> No implementation of the method, and the class (AName) cannot be instantiated.
	- To be instantiated, child classes must define the pure methods, even if they cannot be instantiated in the parent class.
	- An **abstract class** is a class that cannot be instantiated directly. It serves as a blueprint for other classes and is typically used to define a common interface for derived classes. Abstract classes are characterized by having at least one **pure virtual function**.
		1. **Pure Virtual Function**:
			- Declared using the syntax `virtual void functionName() = 0;`.
			- A pure virtual function has no implementation in the abstract class.
			- Derived classes must provide an implementation for all pure virtual functions to be instantiated.
		2. **Cannot Instantiate**:
			- You cannot create objects of an abstract class directly.
			- You can, however, use pointers or references to an abstract class to refer to objects of derived classes.
		3. **Inheritance Requirement**:
			- Derived classes must implement all pure virtual functions of the abstract class to be instantiable.
	- Abstract classes are useful for defining a common interface for a group of related classes.
	- They promote **polymorphism** by allowing derived classes to be used interchangeably via pointers or references to the abstract base class.


5. Interface
	- Only methods that cannot be instantiated.
	- An interface is used to work with derived objects.
	- Interfaces can be implemented using **abstract classes**. An interface in C++ is essentially an abstract class where:
		1. All member functions are **pure virtual functions** (`virtual void functionName() = 0;`).
		2. It does not contain any data members or implemented methods (except for optional destructors).
	- Interfaces are used to define a contract that derived classes must adhere to, ensuring they implement specific functionality.
	- **Pure Virtual Functions**: All functions in an interface are pure virtual, meaning derived classes must implement them.
	- **No Implementation**: Interfaces do not provide any implementation for their methods.
	- **Polymorphism**: Interfaces promote polymorphism by allowing objects of different types to be used interchangeably via pointers or references to the interface.

6. Differences Between Abstract Classes and Interfaces:
- **Abstract Classes**:
   - Can have both pure virtual functions and implemented methods.
   - Can contain data members.
   - Used when you want to provide a partial implementation or shared functionality.

- **Interfaces**:
   - Only contain pure virtual functions.
   - Do not have data members or implemented methods.
   - Used purely to define a contract for derived classes.


7. DEEP COPY
- **Shallow Copy vs Deep Copy**:
   - **Shallow Copy**: Copies only the values of the object's member variables. If the object contains pointers, only the pointer values are copied, not the data they point to. This can lead to issues like dangling pointers or double deletion.
   - **Deep Copy**: Copies the actual data pointed to by the pointers, ensuring the new object has its own copy of the dynamically allocated resources.

- **Implementation**:
   - Write a custom copy constructor : Perform a deep copy of the Brain object by creating a new Brain instance and copying the contents of the src.brain
   - Write a custom assignment operator (`operator=`) : Free the existing Brain object before assigning a new one to avoid memory leaks. Perform a deep copy of the Brain object using the copy constructor.

### EX00
- **virtual** void makeSound() const; for Animal class so the child (declared as an animal) can have their own function
### EX01
- deep copy of brain


### EX04
1. **AMateria**
	- Pure Virtual Function (clone): any derived class must provide its own implementation of this function. This is because the AMateria class is designed to be an abstract base class, and the clone function is critical for creating a copy of the derived object. Each derived class will have its own specific implementation of clone to ensure the correct type of object is duplicated.
	- Virtual Function (use): it can be overridden in derived classes, but it is not mandatory to do so. The base class AMateria provides a default implementation of use, which derived classes can either use as-is or override with their own specific behavior.
2. **INCLUDES**
	- Forward Declaration W: In AMateria.hpp, the `ICharacter` class is only referenced as a parameter type in the `use` method and as a pointer type in the `clone` method.
	- Forward declarations are sufficient in these cases because: **Pointers and References**: The compiler does not need the full definition of a class to declare pointers or references to it. It only needs to know that the class exists, which is what the forward declaration provides. **No Member Variables or Base Class**: `AMateria` does not inherit from `ICharacter`, nor does it have `ICharacter` as a member variable. These scenarios would require the full definition of `ICharacter`.
	- In `Character.hpp`, the `ICharacter` class is used as a **base class** (`class Character : public ICharacter`) and the `Storage` class is used as a **member variable** (`Storage _ground`). Both of these usages require the full definitions of the respective classes because:**Base Classes**: The compiler needs the full definition of a base class to generate the derived class's layout and ensure proper inheritance. **Member Variables**: The compiler needs the full definition of a class to allocate memory for its member variables.
	- **Forward Declaration**: Works for pointers, references, and method parameters.
	- **Full Definition**: Required for inheritance, member variables, and method calls that access the class's implementation.
