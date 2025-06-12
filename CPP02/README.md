# CPP02

### Functions Overload (ad hoc polymorphis)
- Functions with same name but different param
- void name ( param );

### Operator Overload
- Define new operator -> add semantic to adapt to our need
- notation prefix (+ 1 1), postfix (1 1 +) and infix (1 + 1)
- (+ (1, 1)) = 1.+( 1 ) -> instance 1 with function member (+) to which we send 1
- Class& operator=(Class const & name); -> modify current instance + return reference on class, return current instance
- Class& Class::operator=(Class const & name) { this->_var = name.getValue(); return (*this) }
- Class operator+(Class const & name) const; -> never modify current instance, return copy of the result
- Class Class::operator+(Class const & name) const { return (Class( this->_var + name.getValue() )); } -> return copy of class
- "operator" => key word for overload
- default param is the instance (this)
- std::ostream & operator<<( std::ostream & o, Class const & name );
- std::ostream & operator<<( std::ostream & o, Class const & name ) { o << name.getValue(), return o; } -> function overload, use outut stream (o) on which we redirect something

### Canonical class
- Class(void); //constructeur par defaut -> Class::Class (int const n) : _var (n) {}
- Class(Class const & name); //constructeur par copie -> Class::Class (Class const & name) { *this = name;}
- ~Class(void); //destructor
- Class & operator=(Class const & name); //opertor =

### ex01
- fixed point format = integer that represent a nb multiplied by power of 2 regarding of how many bits are reserved for the fractional part => with 8 fractional bits --- real value = int / 2^8 = int / 256
    1. An integer has no fractional part. To convert it to fixed-point: fixed_value = integer × 2^n
    2. n = number of fractional bits (e.g., 8),
    3. shifting the value left by 8 bits to make space for fractional bits.
    4. for instance 10 in binary = 00001010 if we shift to the left -> 10 * 2^8 = 10 << 8 = 00001010 00000000 = 2560
    5. to convert it back we shift on the other side integer = fixed value >> 8 = fixed value / 2^8
- for float we need to handle the decimal part as we can bit shift only on integer = float * (1 << 8)
    1. first multiply the float f by 2^8  which is done using (1 << 8) = 256, this shifts 1 to the left by 8 positions
    2. to convert it back we shift on the other side float = fixed value / 256 = fixed value / (1 << 8)
- limited precision of the float type — which usually gives only about 6–7 decimal digits of precision total, including both integer and fractional parts.

### ex02
- https://learn.microsoft.com/fr-fr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
- static = can call directly from main with FIxed::function, can be called without creating an instance of the class, can only manipulate other static member of the class
- const = because we can declare instance as const -> object cannot be modified
- pstfix take int as arg to send message to compilator "this is the funciton for postfix"

### ex03
- determinant donne l'air d'un parallelogramme du coup on /2 pour avoir un triangle
- A (x1, y1, 1)
- B (x2, y2, 1)
- C (x3, y3, 1)
- determinant = abs ( x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
- vecteur = objet avec 2 aspects
    1. direction
    2. longueur
    3. il peut etre represente par une fleche dans l'espace
    4. vecteur AB -> deplacement de A vers B
- = operator with const -> not useful here because we are using const variable that have to be init at the construction of the object and won't be changed then and can't be assigned with this operator
