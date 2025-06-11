#ifndef STORAGE_H
#define STORAGE_H

class AMateria;

class Storage {

	public:
		Storage();
		Storage(Storage const& src);
		~Storage();

		Storage& operator=(Storage const& src);

		void addStorage(AMateria* m);
		void compareStorage(AMateria* m);
		void printStorage() const;

	private:
		AMateria **_storage;
		int _capacity;
		int _size;
};

#endif
