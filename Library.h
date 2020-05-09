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
	void open(const char*, Vector<Book>&, Vector<User>&); 
	void close(Vector<Book>&, Vector<User>&) const;
	void save(const char*, Vector<Book>&, Vector<User>&) const; 
	void saveas(const char*, Vector<Book>&, Vector<User>&) const; 
	void help() const;
	void login(const char*, Vector<User>&);
	void logout();
	void booksAll() const;
	void booksInfo(int) const;
	void booksFind(const char*, const char*) const;
	void booksSort(Vector<Book>&, const char*, const char* = "asc") const;
	void addUser(const char*, const char*, Vector<User>&) const;
	void removeUser(Vector<User>&) const;
	void addBook(Vector<Book>&) const;
	void removeBook(Vector<Book>&) const;
};


#endif // !LIBRARY_H_

