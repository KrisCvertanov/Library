#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <fstream>
#include "Book.h"
#include "User.h"
#include "vector.hpp"

class Library {
private:
	Vector<Book> books;
	User user;
	bool userLoggedIn;

public:
	Library();
	void open(const char*, Vector<Book>&, Vector<User>&); //da zarejdam userite sushto
	void close(Vector<Book>&, Vector<User>&) const;
	void save(const char*, Vector<Book>&, Vector<User>&) const; // da zapisvam userite sushto
	void saveas(Vector<Book>&, Vector<User>&) const; // da zapisvam userite sushto
	void help() const;
	void login(const char*);
	void logout();
	void booksAll() const;
	void booksInfo(int) const;
	void booksFind(const char*, const char*) const;
	void booksSort(Vector<Book>&, const char*, const char* = "asc") const;
	void addUser(Vector<User>&) const;//za vseki metod proverka dali ima potrebitel/admin!!!!
	void removeUser(Vector<User>&) const;
	void addBook(Vector<Book>&) const;
	void removeBook(Vector<Book>&) const;


};


#endif // !LIBRARY_H_

