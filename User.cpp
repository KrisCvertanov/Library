#include "User.h"

User::User() {
	access = false;
}

User::User(const String& name_, const String& password_, const bool access_) {
	name = name_;
	password = password_;
	access = access_;
}

User::User(const char* name_, const char* password_, const bool access_) {
	name = name_;
	password = password_;
	access = access_;
}

const String User::getName() const {
	return name;
}

const String User::getPassword() const {
	return password;
}

bool User::getAccess() const{
	return access;
}

void User::print() const {
	std::cout << "info about user: " << std::endl;
	std::cout << "name: " << name << std::endl;
	std::cout << "pass: " << password << std::endl;
	std::cout << "access: " << access << std::endl;
}

void User::clear() {
	name.clear();
	password.clear();
	access = false;
}

std::ifstream& operator>>(std::ifstream& iFile, User& tempUser) {
	iFile >> tempUser.name;
	iFile >> tempUser.password;
	iFile >> tempUser.access;
	return iFile;
}

std::ofstream& operator<<(std::ofstream& oFile, const User& tempUser){
	oFile << tempUser.name << std::endl;
	oFile << tempUser.password << std::endl;
	oFile << tempUser.access << std::endl;
	std::cout << std::endl;
	return oFile;
}

std::istream& operator>>(std::istream& in, User& tempUser) {
	std::cout << "Username: ";
	in >> tempUser.name;
	std::cout << "Password: "; // moje posle da si napravq bonusa s  ***
	in >> tempUser.password;
	tempUser.access = 0;
	return in;
}

std::ostream& operator<<(std::ostream& out, const User& tempUser) {
	out << tempUser.name << " " << tempUser.password << " " << tempUser.access;
	return out;
}

void User::save(std::ofstream& oFile) {
	oFile << *this;
}

void User::load(std::ifstream& iFile) { 
	iFile >> *this;
}