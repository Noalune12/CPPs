# EX00
- std::cout = object that allow to have access to the writing console / represent the output stream
	- std = namespace with functions, objects and classes
	- :: = operator that allow to have access to what is inside std
	- cout = object (output stream)
- << : insertion operator that send data to std::cout, handle data stream
- std::endl = inserts a newline character into the output sequence and fluch (empty buffer where data is stocked before writing)

# EX01
- use getline because read entire line including spaces + automtically empty buffer
- function() const; will never modify the instance

# EX02
- timestamp : annee mois jour _ heure minute seconde
- time get the time in second since 1970
- tm->tm_year year since 1900, need to add 1900 to get the real year.
- tm->tm_mon index of month so +1.
