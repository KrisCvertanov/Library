#define _CRT_SECURE_NO_WARNINGS
#include "Library.h"

Library::Library() {
	User temp("admin", "i<3c++", 1);
	user = temp;
	userLoggedIn = true;
}

void Library::open(const char* dir, Vector<Book>& tempBooks, Vector<User>& tempUsers){
	std::ifstream iFile(dir, std::ios::in); // otvarya faila za knigite
	if (!iFile) {
		std::cerr << "Failed to open!" << std::endl;
		return;
	}
	iFile.seekg(0, std::ios::end);
	if (iFile.tellg() == 0) { // ako faila e prazen
		iFile.close();
		std::ofstream oFile(dir, std::ios::out);
		if (!oFile) {
			std::cerr << "Failed to open!" << std::endl;
			return;
		}
		int zero = 0;
		oFile << zero; // zapisva '0' 
		oFile.close();
		std::ifstream iFile(dir, std::ios::in);
		if (!iFile) {
			std::cerr << "Failed to open!" << std::endl;
		}
	}
	iFile.seekg(0, std::ios::beg);
	int i;
	iFile >> i;
	iFile.ignore();
	tempBooks.deleteVector();
	tempBooks.allocateMemory(i);
	if (i > 0) {
		for (int j = 0; j < i; j++) {
			tempBooks[j].load(iFile);
			tempBooks.addToCount();
			iFile.ignore();
			iFile.ignore();
		}
	}
	iFile.close();

	books = tempBooks;

	std::ifstream iFile2("users.txt"); // otvarya faila za potrebitelite
	if (!iFile2) {
		std::cerr << "Failed to open file with users!" << std::endl;
		return;
	}
	iFile2.seekg(0, std::ios::end);
	if (iFile2.tellg() == 0) { // ako faila e prazen
		iFile2.close();
		std::ofstream oFile2("users.txt", std::ios::trunc);
		if (!oFile2) {
			std::cerr << "Failed to open file for adding admin!" << std::endl;
			return;
		}
		int one = 1;
		User admin("admin", "i<3c++", 1);
		oFile2 << one << std::endl;
		admin.save(oFile2);
		tempUsers.addToCount();
		oFile2.close();

		std::ifstream iFile2("users.txt", std::ios::in);
		if (!iFile2) {
			std::cerr << "Failed to open file of users vol.2!" << std::endl;
		}
	}
	iFile2.seekg(0, std::ios::beg);
	int p;
	iFile2 >> p;
	iFile2.ignore();
	tempUsers.deleteVector();
	tempUsers.allocateMemory(p);
	if (p > 0) {
		for (int j = 0; j < p; j++) {
			tempUsers[j].load(iFile2);
			tempUsers.addToCount();
			iFile2.ignore();
			//iFile.ignore();
		}
	}
	iFile2.close();
}

void Library::close(Vector<Book>& tempBooks, Vector<User>& tempUsers) const{
	if (tempBooks.size() == 0) {
		std::cout << "File is already closed. Cannot use this command!" << std::endl;
		return;
	}
	tempBooks.clear();
	tempUsers.clear();
}

void Library::save(const char* dir, Vector<Book>& tempBooks, Vector<User>& tempUsers) const{
	int i = tempBooks.size(); 
	if (i > 0) {
		std::ofstream oFile(dir, std::ios::trunc);
		if (!oFile) {
			std::cerr << "Failed to open!" << std::endl;
			return;
		}
		oFile << i << std::endl;
		for (int j = 0; j < i; j++) {
			tempBooks[j].save(oFile);
		}
		oFile.close();
	}
	i = tempUsers.size();
	if (i > 0) {
		std::ofstream oFile("users.txt", std::ios::trunc);
		if (!oFile) {
			std::cerr << "Failed to open!" << std::endl;
			return;
		}
		oFile << i << std::endl;
		for (int j = 0; j < i; j++) {
			tempUsers[j].save(oFile);
		}
	}
	if (tempBooks.size() == 0 && tempUsers.size() == 0) {
		std::cout << "File is closed. Cannot use that command!" << std::endl;
	}
}

void Library::saveas(Vector<Book>& tempBooks, Vector<User>& tempUsers) const {
	int i = tempBooks.size();
	if (i > 0) {
		std::cout << "Enter file's name: ";
		char* dir;
		int br = 2;
		dir = new char[br];
		char letter;
		std::cin.get(letter);
		while (letter != '\n') {
			char* tempArr = new char[br];
			if (br == 2) {
				tempArr[0] = letter;
				tempArr[1] = '\0';
			}
			else {
				strcpy(tempArr, dir);
				tempArr[br - 2] = letter;
				tempArr[br - 1] = '\0';
			}
			delete[] dir;
			dir = new char[br];
			strcpy(dir, tempArr);
			br++;
			delete[] tempArr;
			std::cin.get(letter);
		}

		std::ofstream oFile(dir, std::ios::trunc);
		if (!oFile) {
			std::cerr << "Failed to open!" << std::endl;
			return;
		}
		delete[] dir;
		oFile << i << std::endl;
		for (int j = 0; j < i; j++) {
			tempBooks[j].save(oFile);
		}
	}

	i = tempUsers.size();
	if (i > 0) {
		std::ofstream oFile("users.txt", std::ios::trunc);
		if (!oFile) {
			std::cerr << "Failed to open!" << std::endl;
			return;
		}
		oFile << i << std::endl;
		for (int j = 0; j < i; j++) {
			tempUsers[j].save(oFile);
		}
	}
	if (tempBooks.size() == 0 && tempUsers.size() == 0) {
		std::cout << "File is closed. Cannot use that command!" << std::endl;
	}
}

void Library::help() const{
	std::cout << "The following app commands are supported: " << std::endl;
	std::cout << "open <file>                       opens <file>" << std::endl;
	std::cout << "close                             closes currently opened file " <<std::endl;
	std::cout << "save                              saves updates in currently opened file" << std::endl;
	std::cout << "saveas <file>                     saves currently opened file in <file>" << std::endl;
	std::cout << "exit                              exits the program" << std::endl;
	std::cout << "login                             log in as an existing user" << std::endl;
	std::cout << "logout                            logs out (user needed)" << std::endl;
	std::cout << "books all                         prints short information about all books (user needed)" << std::endl;
	std::cout << "books info <bn_value>             prints detailed information about the book with unique number <bn_value> (user needed)" << std::endl;
	std::cout << "books find <option> <option_str>  prints a book searched by <option> and <option_str> (user needed)" << std::endl;
	std::cout << "books sort <option> [asc|desc]    sorts the books by <option> (user needed)" << std::endl;
	std::cout << "books add                         adds a new book to the library (admin needed)" << std::endl;
	std::cout << "books remove                      removes a book from the library (admin needed)" << std::endl;
	std::cout << "users add <user> <password>       add s a new user with name <user> and password <password> (admin needed)" << std::endl;
	std::cout << "users remove <user>               deletes user with name <user> from currently opened file (admin needed)" << std::endl;
}

void Library::login(const char* dir) {
	if (userLoggedIn == true) {
		std::cout << "You are already logged in." << std::endl;
		return;
	}
	std::ifstream iFile(dir, std::ios::in);
	if (!iFile) {
		std::cerr << "Failed to open!" << std::endl;
		return;
	}
	int l;
	iFile >> l;
	iFile.ignore();
	User* tempUsers = new User[l];
	for (int i = 0; i < l; i++) {
		tempUsers[i].load(iFile);
		iFile.ignore();
	}
	iFile.close();
	int pos;
	bool flag = false;
	String tempName, tempPassword;
	std::cout << "Enter username: ";
	std::cin >> tempName;
	for (int i = 0; i < l; i++) { /// priema se, che nqma potrebiteli s edni i sushti imena i razlichni paroli
		if (tempName == tempUsers[i].getName()) {
			flag = true;
			pos = i;
			break;
		}
	}
	if (flag == false) { 
		std::cout << "There's no user with that name." << std::endl; 
		return;
	}
	std::cout << "Enter password: ";
	std::cin >> tempPassword;
	if (tempPassword == tempUsers[pos].getPassword()) {
		std::cout << "Welcome " << tempName << std::endl;
		if (tempName == "admin") {
			User temp(tempName, tempPassword, true);
			user = temp;
		}
		else {
			User temp(tempName, tempPassword, false);
			user = temp;
		}
		userLoggedIn = true;
		delete[] tempUsers;
		return;
	}
	std::cout << "Entered password is incorrect!" << std::endl;
	delete[] tempUsers;
	return;

}

void Library::logout() {
	if (userLoggedIn) {
		user.clear(); /// osvobojdavame zadelenata pamet
		userLoggedIn = false;
	}
	else {
		std::cout << "There's no user logged in!" << std::endl;
	}
}

void Library::booksAll() const {
	if (!userLoggedIn) {
		std::cout << "There must be a user logged in!" << std::endl;
		return;
	}
	int j = books.size();
	for (int i = 0; i < j; i++) {
		books[i].printForBooksAll();
	}
}

void Library::booksInfo(int num) const {
	if (!userLoggedIn) {
		std::cout << "There must be a user logged in!" << std::endl;
		return;
	}
	int j = books.size();
	for (int i = 0; i < j; i++) {
		if (books[i].getUniqueNumber() == num) {
			books[i].print();
			break;
		}
	}
}

void Library::booksFind(const char* option, const char* option_str) const{ // proverka v meina dali e pravilno vuvedena opciyata
	if (!userLoggedIn) {
		std::cout << "There must be a user logged in!" << std::endl;
		return;
	}
	int n = books.size();
	if (strcmp(option, "tag") == 0) {
		for (int i = 0; i < n; i++) {
			int br = 0;
			String tempTags = books[i].getTags();
			for (int j = 0; j < tempTags.getSize(); j++) {
				if (tempTags[j] == ' ') br++; // ochakva se che tagovete sa razdeleni s 1 interval
			}
			char** bookTags = new char* [br + 1];
			int count = 0;
			for (int j = 0; j < tempTags.getSize(); j++) {
				br = 0;
				int s = 0;
				while (tempTags[j+s] != ' ' && (j + s < tempTags.getSize())) {
					br++;
					s++;
				}
				j += br;
				bookTags[count] = new char[br + 1];
				count++;
			}
			count = 0;
			for (int j = 0; j < tempTags.getSize(); j++) {
				br = 0;
				int s = 0;
				while (tempTags[j + s] != ' ' && (j + s < tempTags.getSize())) {
					bookTags[count][s] = tempTags[j + s];
					s++;
					br++;
				}
				j += br;
				bookTags[count][s] = '\0';
				count++;
			}
			for (int j = 0; j < count; j++) {
				if (strcmp(bookTags[j], option_str) == 0) books[i].print();
			}
			for (int j = 0; j < count; j++) {
				delete[] bookTags[j];
			}
			delete[] bookTags;
		}
	}
	else if(strcmp(option, "author") == 0) {
		for (int i = 0; i < n; i++) {
			if (books[i].getAuthor() == option_str) books[i].print();
		}
	}
	else { // title
		for (int i = 0; i < n; i++) {
			if (books[i].getTitle() == option_str) books[i].print();
		}
	}
}

void Library::booksSort(Vector<Book>& tempBooks, const char* option, const char* order) const{ // proverka dali vuvedenite opciya i red sa validni
	if (!userLoggedIn) {
		std::cout << "There must be a user logged in!" << std::endl;
		return;
	}
	int n = tempBooks.size();
	if (strcmp(option, "title") == 0) {
		if (strcmp(order, "asc") == 0) {
			for (int i = 0; i < n; i++) {
				String firstBookTitle = tempBooks[i].getTitle();
				for (int j = i + 1; j < n; j++) {
					String secondBookTitle = tempBooks[j].getTitle();
					int k = 0;
					while (firstBookTitle[k] && secondBookTitle[k]) {
						if (firstBookTitle[k] > secondBookTitle[k]) {
							Book tempBook = tempBooks[i];
							tempBooks[i] = tempBooks[j];
							tempBooks[j] = tempBook;
							break;
						}
						else if (firstBookTitle[k] < secondBookTitle[k]) break;
						k++;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				String firstBookTitle = tempBooks[i].getTitle();
				for (int j = i + 1; j < n; j++) {
					String secondBookTitle = tempBooks[j].getTitle();
					int k = 0;
					while (firstBookTitle[k] && secondBookTitle[k]) {
						if (firstBookTitle[k] < secondBookTitle[k]) {
							Book tempBook = tempBooks[i];
							tempBooks[i] = tempBooks[j];
							tempBooks[j] = tempBook;
							break;
						}
						else if (firstBookTitle[k] > secondBookTitle[k]) break;
						k++;
					}
				}
			}
		}
	}
	else if (strcmp(option, "author") == 0) {
		if (strcmp(order, "asc") == 0) {
			for (int i = 0; i < n; i++) {
				String firstBookAuthor = tempBooks[i].getAuthor();
				for (int j = i + 1; j < n; j++) {
					String secondBookAuthor = tempBooks[j].getAuthor();
					int k = 0;
					while (firstBookAuthor[k] && secondBookAuthor[k]) {
						if (firstBookAuthor[k] > secondBookAuthor[k]) {
							Book tempBook = tempBooks[i];
							tempBooks[i] = tempBooks[j];
							tempBooks[j] = tempBook;
							break;
						}
						else if (firstBookAuthor[k] < secondBookAuthor[k]) break;
						k++;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				String firstBookAuthor = tempBooks[i].getAuthor();
				for (int j = i + 1; j < n; j++) {
					String secondBookAuthor = tempBooks[j].getAuthor();
					int k = 0;
					while (firstBookAuthor[k] && secondBookAuthor[k]) {
						if (firstBookAuthor[k] < secondBookAuthor[k]) {
							Book tempBook = tempBooks[i];
							tempBooks[i] = tempBooks[j];
							tempBooks[j] = tempBook;
							break;
						}
						else if (firstBookAuthor[k] > secondBookAuthor[k]) break;
						k++;
					}
				}
			}
		}
	}
	else if (strcmp(option, "year") == 0) {
		if (strcmp(order, "asc") == 0) {
			for (int i = 0; i < n; i++) {
				char firstBookYear[5]; // priema se, che godinata e 4-cifreni chislo
				String tempBook1 = tempBooks[i].getDateOfRelease();
				for (int j = 0; j < 4; j++) firstBookYear[j] = tempBook1[j];
				firstBookYear[4] = '\0';
				for (int j = i + 1; j < n; j++) {
					char secondBookYear[5]; 
					String tempBook2 = tempBooks[j].getDateOfRelease();
					for (int s = 0; s < 4; s++) secondBookYear[s] = tempBook2[s];
					secondBookYear[4] = '\0';
					if (strcmp(firstBookYear, secondBookYear) > 0) {
						Book tempBook = tempBooks[i];
						tempBooks[i] = tempBooks[j];
						tempBooks[j] = tempBook;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				char firstBookYear[5]; // priema se, che godinata e 4-cifreni chislo
				String tempBook1 = tempBooks[i].getDateOfRelease();
				for (int j = 0; j < 4; j++) firstBookYear[j] = tempBook1[j];
				firstBookYear[4] = '\0';
				for (int j = i + 1; j < n; j++) {
					char secondBookYear[5];
					String tempBook2 = tempBooks[j].getDateOfRelease();
					for (int s = 0; s < 4; s++) secondBookYear[s] = tempBook2[s];
					secondBookYear[4] = '\0';
					if (strcmp(firstBookYear, secondBookYear) < 0) {
						Book tempBook = tempBooks[i];
						tempBooks[i] = tempBooks[j];
						tempBooks[j] = tempBook;
					}
				}
			}
		}
	}
	else { // rating
		if (strcmp(order, "asc") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (tempBooks[i].getRating() > tempBooks[j].getRating()) {
						Book tempBook = tempBooks[i];
						tempBooks[i] = tempBooks[j];
						tempBooks[j] = tempBook;
					}
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (tempBooks[i].getRating() < tempBooks[j].getRating()) {
						Book tempBook = tempBooks[i];
						tempBooks[i] = tempBooks[j];
						tempBooks[j] = tempBook;
					}
				}
			}
		}
	}
}

void Library::addUser(Vector<User>& tempUsers) const {
	if (!user.getAccess()) {
		std::cout << "There must be an admin logged in!" << std::endl;
		return;
	}
	User newUser;
	std::cout << "New user's name: ";
	std::cin >> newUser;
	tempUsers.add(newUser);
	std::cout << "User addded successfully!" << std::endl;
}

void Library::removeUser(Vector<User>& tempUsers) const {
	if (!user.getAccess()) {
		std::cout << "There must be an admin logged in!" << std::endl;
		return;
	}
	std::cout << "Enter user's name you want to remove: ";
	char* oldUser;
	int br = 2;
	oldUser = new char[br];
	char letter;
	std::cin.get(letter);
	while (letter != '\n') {
		char* tempArr = new char[br];
		if (br == 2) {
			tempArr[0] = letter;
			tempArr[1] = '\0';
		}
		else {
			strcpy(tempArr, oldUser);
			tempArr[br - 2] = letter;
			tempArr[br - 1] = '\0';
		}
		delete[] oldUser;
		oldUser = new char[br];
		strcpy(oldUser, tempArr);
		br++;
		delete[] tempArr;
		std::cin.get(letter);
	}
	oldUser[br-1] = '\0';
	if (strcmp(oldUser, "admin") == 0) {
		std::cout << "You cannot remove the admin!" << std::endl;
		return;
	}
	int n = tempUsers.size(), pos;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (tempUsers[i].getName() == oldUser) {
			flag = true;
			pos = i;
			break;
		}
	}
	if (!flag) {
		std::cout << "User with that name is not found!" << std::endl;
		return;
	}
	tempUsers.removeAtIndex(pos);
	std::cout << "User removed successfully!" << std::endl;
}

void Library::addBook(Vector<Book>& tempBooks) const {
	if (!user.getAccess()) {
		std::cout << "There must be an admin logged in!" << std::endl;
		return;
	}
	Book newBook;
	std::cout << "New book: " << std::endl;
	std::cin >> newBook;
	tempBooks.add(newBook);
	std::cout << std::endl;
	std::cout << "Book added successfully!" << std::endl << std::endl;
}

void Library::removeBook(Vector<Book>& tempBooks) const {
	if (!user.getAccess()) {
		std::cout << "There must be an admin logged in!" << std::endl;
		return;
	}
	std::cout << "Enter books's serial number you want to remove: ";
	int oldBookUN;
	std::cin >> oldBookUN;

	int n = tempBooks.size(), pos;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (tempBooks[i].getUniqueNumber() == oldBookUN) {
			flag = true;
			pos = i;
			break;
		}
	}
	if (!flag) {
		std::cout << "Book with that serial number is not found!" << std::endl;
		return;
	}
	tempBooks.removeAtIndex(pos);
	std::cout << "Book removed successfully!" << std::endl << std::endl;
}



