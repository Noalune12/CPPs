# EX00
- std::cout = object that allow to have access to the writing console / represent the output stream
	- std = namespace that contains the names and identifiers of standard library components like data types, functions, objects and classes
	- :: = operator that allow to have access to what is inside std
	- cout = object (output stream)
- << : insertion operator that send data to std::cout, handle data stream
- std::endl = inserts a newline character into the output sequence and fluch (empty buffer where data is stocked before writing)

# EX01
- use getline because read entire line including spaces + automtically empty buffer
- function() const; will never modify the instance
- I don't need a getter to print the info because I print only from the class and I don't need to give access to the data to other classes
- getters are useful to allow more flexibility outside of the class
- using a getter allow to read the private member but not modify it

# EX02
- timestamp : annee mois jour _ heure minute seconde
- time get the time in second since 1970
- tm->tm_year year since 1900, need to add 1900 to get the real year.
- tm->tm_mon index of month so +1.

- Static : Global informations to different classes so maybe we can use them outside the class
### Advantage of getters:
1. **Encapsulation** : protect direct access to private variables.
2. **Coherence** : centralise access
- vs instance variable -> create getter only if we nood to access the variable from outside the class
