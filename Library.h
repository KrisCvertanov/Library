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
	void open(const char*, Vector<Book>&, Vector<User>&);				// otvarya i prochita informaciya ot fail
	void close(Vector<Book>&, Vector<User>&) const;						// zatvarya faila i izchistva zaredenata informaciya
	void save(const char*, Vector<Book>&, Vector<User>&) const; // zapazva promenite po bibliotekata v tekushto zaredeniya fail
	void saveas(const char*, Vector<Book>&, Vector<User>&) const;		// zapazva promenite po bibliotekata v nov fail
	void help() const;													// izvejda poddurjanite komandi ot sistemata
	void login(const char*, Vector<User>&);								// potrebitel vliza v sistemata
	void logout();														// potrebitel izliza ot sistemata
	void booksAll() const;												// izvejda informaciya za vsichki knigi v bibliotekata
	void booksInfo(int) const;										// izvejda podrobna informaciya za kniga s daden serien nomer
	void booksFind(const char*, const char*) const;					// namira i otpechatva kniga, tursena po zadaden kriterii
	void booksSort(Vector<Book>&, const char*, const char* = "asc") const; // sortira po zadaden kriterii knigite v bibliotekata
	void addUser(const char*, const char*, Vector<User>&) const;		// dobavya nov potrebitel kum sistemata
	void removeUser(Vector<User>&) const;								// premahva potrebitel ot sistemata
	void addBook(Vector<Book>&) const;									// dobavya nova kniga v bibliotekata
	void removeBook(Vector<Book>&) const;								// premahva kniga ot bibliotekata(po zadaden nomer)
};


#endif // !LIBRARY_H_

