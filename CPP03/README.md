# CPP03
- hit points -> lost when attacked and get it back when repaired
- energy point -> lose one when attacking and repairing, can never get it back

### ex01
- Marking the destructor and the `attack` method as `virtual` in the `ClapTrap` class is useful for ensuring proper behavior in inheritance scenarios.
- Virtual destructor : When a base class has a virtual destructor, it ensures that the destructor of the derived class is called when an object is deleted through a pointer to the base class. Without a virtual destructor, only the base class destructor would be called, potentially leading to resource leaks or undefined behavior if the derived class allocates resources that need to be freed. If the destructor in `ClapTrap` were not virtual, only the `ClapTrap` destructor would be called, and the `ScavTrap` destructor would be skipped.
- **Virtual Destructor**: Ensures proper cleanup of derived class resources.
- Virtual `attack` Method : allows derived classes (like `ScavTrap`) to override the method and ensures that the correct version of the method is called based on the actual type of the object, not the type of the pointer/reference. This is essential for polymorphism, where behavior depends on the runtime type of the object. Without `virtual`, the base class's `attack` method would be called, even if the object is of type `ScavTrap`.
- **Virtual `attack` Method**: Enables polymorphic behavior, allowing derived classes to provide specialized implementations.

### ex03
- `virtual` used in inheritance to resolve ambiguities and ensure proper behavior when dealing with multiple inheritance or polymorphism. -
- Virtual Inheritance: In  `DiamondTrap` class, `ScavTrap` and `FragTrap` both inherit from `ClapTrap`. Without `virtual` inheritance, `DiamondTrap` would inherit two separate copies of `ClapTrap`—one from `ScavTrap` and one from `FragTrap`. This is known as the **diamond problem**. To solve this, `virtual` inheritance is used in the `FragTrap` and `ScavTrap` classes when inheriting from `ClapTrap`. This ensures that `DiamondTrap` only has **one shared instance** of `ClapTrap`, avoiding duplication.
- **Without `virtual`:** `DiamondTrap` would inherit two separate copies of `_name`, `_hitPoints`, `_energyPoints`, etc., leading to ambiguity.
- **With `virtual`:** `DiamondTrap` inherits a single shared copy of `ClapTrap`, resolving the ambiguity.


