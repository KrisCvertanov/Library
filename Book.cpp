#include "Book.h"

Book::Book() {}

Book::Book(const String author_, const String title_, const String genre_, const String desc_, const String date_, const String tags_, const double rating_, const int num_) {
	author = author_;
	title = title_;
	genre = genre_;
	description = desc_;
	dateOfRelease = date_;
	tags = tags_;
	rating = rating_;
	uniqueNumber = num_;
}

Book::Book(const char* author_, const char* title_, const char* genre_, const char* desc_, const char* date_, const char* tags_, const double rating_, const int num_) {
	author = author_;
	title = title_;
	genre = genre_;
	description = desc_;
	dateOfRelease = date_;
	tags = tags_;
	rating = rating_;
	uniqueNumber = num_;
}

const String Book::getAuthor() const {
	return author;
}

const String Book::getTitle() const {
	return title;
}

const String Book::getGenre() const {
	return genre;
}

const String Book::getDescription() const {
	return description;
}

const String Book::getDateOfRelease() const{
	return dateOfRelease;
}

const String Book::getTags() const{
	return tags;
}

double Book::getRating() const {
	return rating;
}

int Book::getUniqueNumber() const {
	return uniqueNumber;
}

void Book::print() const{
	std::cout << author << std::endl;
	std::cout << title << std::endl;
	std::cout << genre << std::endl;
	std::cout << description << std::endl;
	std::cout << dateOfRelease << std::endl;
	std::cout << tags << std::endl;
	std::cout << rating << std::endl;
	std::cout << uniqueNumber << std::endl;
	std::cout << std::endl;
}

void Book::printForBooksAll() const {
	std::cout << "modified info about book:" << std::endl;
	std::cout << title << std::endl;
	std::cout << author << std::endl;
	std::cout << genre << std::endl;
	std::cout << uniqueNumber << std::endl;
	std::cout << std::endl;
}

std::ifstream& operator>>(std::ifstream& iFile, Book& book) {
	iFile >> book.author;
	iFile >> book.title;
	iFile >> book.genre;
	iFile >> book.description;
	iFile >> book.dateOfRelease;
	iFile >> book.tags;
	iFile >> book.rating;
	iFile >> book.uniqueNumber;
	return iFile;
}

std::ofstream& operator<<(std::ofstream& oFile, const Book& book) {
	oFile << book.author << "\n";
	oFile << book.title << "\n";
	oFile << book.genre << "\n";
	oFile << book.description << "\n";
	oFile << book.dateOfRelease << "\n";
	oFile << book.tags << "\n";
	oFile << book.rating << "\n";
	oFile << book.uniqueNumber << std::endl;
	oFile << std::endl;
	return oFile;
}

std::istream& operator>>(std::istream& in, Book& book) {
	std::cout << "Author: ";
	in >> book.author;
	std::cout << "Title: ";
	in >> book.title;
	std::cout << "genre: ";
	in >> book.genre;
	std::cout << "description: ";
	in >> book.description;
	std::cout << "date of release: ";
	in >> book.dateOfRelease;
	std::cout << "tags: ";
	in >> book.tags;
	std::cout << "rating: ";
	in >> book.rating;
	std::cout << "serial number: ";
	in >> book.uniqueNumber;
	return in;
}

std::ostream& operator<<(std::ostream& oFile, const Book& book) {
	oFile << book.author << " ";
	oFile << book.title << " ";
	oFile << book.genre << " ";
	oFile << book.description << " ";
	oFile << book.dateOfRelease << " ";
	oFile << book.tags << " ";
	oFile << book.rating << " ";
	oFile << book.uniqueNumber << std::endl;
	return oFile;
}

void Book::save(std::ofstream &oFile) {
	oFile << *this;
}

void Book::load(std::ifstream& iFile) {
	iFile >> *this;
}