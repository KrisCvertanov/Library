#include <iostream>
#include <fstream>
#include "Library.h"

using namespace std;


int main()
{
	Library a;
	Vector<Book> books;
	Vector<User> users;
	a.open("books.txt", books, users);
	for (int i = 0; i < books.size(); i++) {
		books[i].print();
		cout << endl;
	}
	for (int i = 0; i <users.size(); i++) {
		users[i].print();
		cout << endl;
	}
	/*Book b("Steven King", "It", "horror", "scary book", "2000-06-12", "clown scary smile", 8.4, 1125);
	books.add(b);
	a.save("books.txt", books, users);*/
	a.removeBook(books);
	for (int i = 0; i < books.size(); i++) {
		books[i].print();
		cout << endl;
	}
	return 0;
}


