#ifndef BOOK_H_
#define BOOK_H_
#include "String.h"

class Book {
private:
	String author;
	String title;
	String genre;
	String description;
	String dateOfRelease;
	String tags;
	double rating;
	int uniqueNumber;

public:
	Book();
	Book(const String&, const String&, const String&, const String&, const String&, const String&, const double, const int);
	Book(const char*, const char*, const char*, const char*, const char*, const char*, const double, const int);
	const String getAuthor() const;				//
	const String getTitle() const;				//
	const String getGenre() const;				//
	const String getDescription() const;		// funkcii za dostup
	const String getDateOfRelease() const;		//
	const String getTags() const;				//
	double getRating() const;					//
	int getUniqueNumber() const;				//
	void print() const;  // izvejda informaciya za knigata
	void printForBooksAll() const; // izvejda podbrana informaciya za knigata
	friend std::ifstream& operator>>(std::ifstream&, Book&);       //
	friend std::ofstream& operator<<(std::ofstream&, const Book&); // operatori za vhod i izhod
	friend std::istream& operator>>(std::istream&, Book&);		   //
	friend std::ostream& operator<<(std::ostream&, const Book&);   //
	void save(std::ofstream&); // funkciya za zapazvane na informaciya v izhoden failov potok 
	void load(std::ifstream&); // funkciya za izvlichane na informaciya ot vhoden failov potok
};


#endif // !BOOK_H_

