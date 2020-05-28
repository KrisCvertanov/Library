#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Library.h"

using namespace std;

int pow(int num, int power) {
	if (num == 0) return 0;
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= num;
	}
	return result;
}

int main()
{
	cout << "Welcome to my Library! Enter a command to perform an action. To see list with all commands, type help." << endl;
	Library lib;
	Vector<Book> tempBooks;
	User admin("admin", "i<3c++", 1);
	Vector<User> tempUsers;
	tempUsers.add(admin);
	String command;
	char* dir = new char[1];
	bool fileOpened = false;
	while (true) {
		cout << "> ";
		cin >> command;
		int br = 0, n = command.getSize();
		//cout << n << endl;
		for (int i = 0; i < n; i++) {
			if (command[i] == ' ') br++;
		}
		char** wordsOfCommand = new char* [br + 1];
		int numOfWords = 0;
		br = 0;
		for (int i = 0; i < n; i++) {
			int count = 0;
			while (command[i] != ' ' && i < n) {
				count++;
				i++;
			}
			wordsOfCommand[numOfWords] = new char[count + 1];
			for (int j = 0; j < count; j++) {
				wordsOfCommand[numOfWords][j] = command[br];
				br++;
			}
			wordsOfCommand[numOfWords][count] = '\0';
			numOfWords++;
			br++;
		}
		
		if (strcmp(wordsOfCommand[0], "close") == 0 && numOfWords == 1) {
			if (fileOpened) lib.close(tempBooks, tempUsers);
			else cout << "You haven't opened a file yet." << endl;
		}
		else if (strcmp(wordsOfCommand[0], "save") == 0 && numOfWords == 1) {
			if (fileOpened) lib.save(dir, tempBooks, tempUsers);
			else cout << "You haven't opened a file yet." << endl;
		}
		else if (strcmp(wordsOfCommand[0], "help") == 0 && numOfWords == 1) {
			lib.help();
		}
		else if (strcmp(wordsOfCommand[0], "login") == 0 && numOfWords == 1) lib.login(dir, tempUsers);
		else if (strcmp(wordsOfCommand[0], "logout") == 0 && numOfWords == 1) lib.logout();
		else if (strcmp(wordsOfCommand[0], "exit") == 0 && numOfWords == 1) {
			cout << "Exiting the program..." << endl;
			return 0;
		}
		else if (strcmp(wordsOfCommand[0], "open") == 0 && numOfWords == 2) {
			delete[] dir;
			int l = strlen(wordsOfCommand[1]);
			dir = new char[l + 1];
			for (int i = 0; i < l; i++) {
				dir[i] = wordsOfCommand[1][i];
			}
			dir[l] = '\0';
			fileOpened = true;
			lib.open(dir, tempBooks, tempUsers);
		}
		else if (strcmp(wordsOfCommand[0], "saveas") == 0 && numOfWords == 2) {
			if(fileOpened) lib.saveas(wordsOfCommand[1], tempBooks, tempUsers);
			else cout << "You haven't opened a file yet." << endl;
		}
		else if (strcmp(wordsOfCommand[0], "books") == 0 && numOfWords > 1) { /// da si opravq chastta s broq na dumite
			if (fileOpened) {
				if (strcmp(wordsOfCommand[1], "all") == 0 && numOfWords == 2) lib.booksAll();
				else if (strcmp(wordsOfCommand[1], "add") == 0 && numOfWords == 2) lib.addBook(tempBooks);
				else if (strcmp(wordsOfCommand[1], "remove") == 0 && numOfWords == 2) lib.removeBook(tempBooks);
				else if (strcmp(wordsOfCommand[1], "info") == 0 && numOfWords == 3) {
					int l = strlen(wordsOfCommand[2]);
					bool containsOnlyDigits = true;
					int serialNumber = 0;
					for (int i = 0; i < l; i++) {
						if (wordsOfCommand[2][i] >= '0' && wordsOfCommand[2][i] <= '9') {
							serialNumber += pow(10, l - i - 1) * (wordsOfCommand[2][i] - '0');
						}
						else {
							containsOnlyDigits = false;
							break;
						}
					}
					if (containsOnlyDigits) lib.booksInfo(serialNumber);
					else cout << "Serial number needs to contain only digits!" << endl;
				}
				else if (strcmp(wordsOfCommand[1], "find") == 0 && numOfWords >=4){ 
					if (strcmp(wordsOfCommand[2], "author") != 0 && strcmp(wordsOfCommand[2], "title") != 0 && strcmp(wordsOfCommand[2], "tag") != 0) {
						cout << "That command does not exist! Enter a valid one." << endl;
					}
					else {
						int lenghtOfStringOption = 0;
						for (int i = 3; i < numOfWords; i++) {
							lenghtOfStringOption += strlen(wordsOfCommand[i]);
						}
						char* stringOption = new char[lenghtOfStringOption + numOfWords - 2];
						stringOption[0] = '\0';
						for (int i = 3; i < numOfWords; i++) {
							strcat(stringOption, wordsOfCommand[i]);
							if (i < numOfWords - 1) strcat(stringOption, " ");
						}
						lib.booksFind(wordsOfCommand[2], stringOption);
					}
				}
				else if (strcmp(wordsOfCommand[1], "sort") == 0 && numOfWords == 3) {
					if (strcmp(wordsOfCommand[2], "title") != 0 && strcmp(wordsOfCommand[2], "author") != 0 && strcmp(wordsOfCommand[2], "year") != 0 && strcmp(wordsOfCommand[2], "rating") != 0) {
						cout << "That command does not exist! Enter a valid one." << endl;
					}
					else lib.booksSort(tempBooks, wordsOfCommand[2]);
				}
				else if (strcmp(wordsOfCommand[1], "sort") == 0 && numOfWords == 4) {
					if (strcmp(wordsOfCommand[2], "title") != 0 && strcmp(wordsOfCommand[2], "author") != 0 && strcmp(wordsOfCommand[2], "year") != 0 && strcmp(wordsOfCommand[2], "rating") != 0) {
						cout << "That command does not exist! Enter a valid one." << endl;
					}
					else {
						if (strcmp(wordsOfCommand[3], "asc") == 0) lib.booksSort(tempBooks, wordsOfCommand[2]);
						else if (strcmp(wordsOfCommand[3], "desc") == 0) lib.booksSort(tempBooks, wordsOfCommand[2], "desc");
						else cout << "That command does not exist! Enter a valid one." << endl;
					}
				}
				else cout << "That command does not exist! Enter a valid one." << endl;
			}
			else cout << "You haven't opened a file yet." << endl;
		}
		else if (strcmp(wordsOfCommand[0], "users") == 0 && numOfWords > 1) {
			if (fileOpened) {
				if (strcmp(wordsOfCommand[1], "add") == 0 && numOfWords == 4) lib.addUser(wordsOfCommand[2], wordsOfCommand[3], tempUsers);
				else if (strcmp(wordsOfCommand[1], "remove") == 0 && numOfWords == 2) lib.removeUser(tempUsers);
				else cout << "That command does not exist! Enter a valid one." << endl;
			}
			else cout << "You haven't opened a file yet." << endl;
		}
		else cout << "That command does not exist! Enter a valid one." << endl;

		for (int i = 0; i < numOfWords; i++) {
			delete[] wordsOfCommand[i];
		}
		delete[] wordsOfCommand;
		command.clear();
	}
	delete[] dir;
	return 0;
}


