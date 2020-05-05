#ifndef USER_H_
#define USER_H_
#include "String.h"

class User {
private:
	String name;
	String password;
	bool access;

public:
	User();
	User(const String, const String, const bool);
	User(const char*, const char*, const bool);
	const String getName() const;
	const String getPassword() const;
	bool getAccess() const;
	void print() const;
	void clear();
	friend std::ifstream& operator>>(std::ifstream&, User&);
	friend std::ofstream& operator<<(std::ofstream&, const User&);
	friend std::istream& operator>>(std::istream&, User&);
	friend std::ostream& operator<<(std::ostream&, const User&);
	void load(std::ifstream&);
	void save(std::ofstream&);

};

#endif // !USER_H_

