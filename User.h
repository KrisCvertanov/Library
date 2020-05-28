#ifndef USER_H_
#define USER_H_
#include "String.h"

class User {
private:
	String name;
	String password;
	bool access;		// 1 ako e admin, 0 ako e normalen potrebitel

public:
	User();
	User(const String&, const String&, const bool);
	User(const char*, const char*, const bool);
	const String getName() const;		// 
	const String getPassword() const;	// funkcii za dostup
	bool getAccess() const;				//
	void print() const;		// izvejda informaciya za potrebitelya
	void clear();	// izchistva zadelenata pamet za potrebitelya
	friend std::ifstream& operator>>(std::ifstream&, User&);			//
	friend std::ofstream& operator<<(std::ofstream&, const User&);		// operatori za vhod i izhod
	friend std::istream& operator>>(std::istream&, User&);				//
	friend std::ostream& operator<<(std::ostream&, const User&);		//
	void load(std::ifstream&); // funkciya za zapazvane na informaciya v izhoden failov potok 
	void save(std::ofstream&); // funkciya za izvlichane na informaciya ot vhoden failov potok

};

#endif // !USER_H_

