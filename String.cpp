#include "String.h"

void String::copyStrings(const char* arr_, const int capacity_, const int size_) {
	arr = new(std::nothrow) char[strlen(arr_) + 1];
	if (arr == nullptr) {
		throw ("No memory for string!(String::copyString)");
		return;
	}
	strcpy(arr, arr_);
	capacity = capacity_;
	size = size_;
}

void String::deleteString() {
	if (arr != nullptr) delete[] arr;
}

String::String() {
	arr = new(std::nothrow) char[1];
	if (arr == nullptr) {
		throw ("No memory for string!(default constructor)");
	}
	capacity = 1;
	size = 0;
}

String::String(const char* arr_, const int capacity_, const int size_) {
	copyStrings(arr_, capacity_, size_);
}

String::String(const String& other) {
	copyStrings(other.arr, other.capacity, other.size);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		deleteString();
		copyStrings(other.arr, other.capacity, other.size);
	}
	return *this;
}

String& String::operator=(const char* str) {
	deleteString();
	int l = strlen(str);
	arr = new(std::nothrow) char[l + 1];
	if (arr == nullptr) {
		throw ("No memory for string!(operator= (const char*))");
	}
	for (int i = 0; i < l; i++) {
		arr[i] = str[i];
	}
	arr[l] = '\0';
	capacity = l + 1;
	size = l;
	return *this;
}

String::~String() {
	deleteString();
}

std::istream& operator>>(std::istream& in, String& str) { // vuvejdane simvol po simvol
	char letter;
	int br = 2;
	in.get(letter);
	while (letter != '\n') {
		char* tempArr = new(std::nothrow) char[br];
		if (tempArr == nullptr) {
			if (str.arr != nullptr) delete[] str.arr;
			throw ("No memory for string!(operator>>)");
			return in;
		}
		if (br == 2) {
			tempArr[0] = letter;
			tempArr[1] = '\0';
		}
		else {
			strcpy(tempArr, str.arr);
			tempArr[br - 2] = letter;
			tempArr[br - 1] = '\0';
		}
		str.deleteString();
		str.arr = new(std::nothrow) char[br];
		if (str.arr == nullptr) {
			delete[] tempArr;
			throw ("No memory for string!(operator>>)");
			return in;
		}
		strcpy(str.arr, tempArr);
		br++;
		delete[] tempArr;
		
		in.get(letter);
	}
	str.capacity = br - 1;
	str.size = br - 2;
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& str){
	int i = 0;
	while (str.arr[i]) {
		out << str.arr[i];
		i++;
	}
	return out;
}

std::ifstream& operator>>(std::ifstream& iFile, String& str) { // chetene simvol po simvol
	char letter;
	int br = 2;
	iFile.get(letter);
	while (letter != '\n') {
		char* tempArr = new(std::nothrow) char[br];
		if (tempArr == nullptr) {
			if (str.arr != nullptr) delete[] str.arr;
			throw ("No memory for string!(operator>>)");
			return iFile;
		}
		if (br == 2) {
			tempArr[0] = letter;
			tempArr[1] = '\0';
		}
		else {
			strcpy(tempArr, str.arr);
			tempArr[br - 2] = letter;
			tempArr[br - 1] = '\0';
		}
		str.deleteString();
		str.arr = new(std::nothrow) char[br];
		if (str.arr == nullptr) {
			delete[] tempArr;
			throw ("No memory for string!(operator>>)");
			return iFile;
		}
		strcpy(str.arr, tempArr);
		br++;
		delete[] tempArr;

		iFile.get(letter);
	}
	str.capacity = br - 1;
	str.size = br - 2;
	return iFile;
}

std::ofstream& operator<<(std::ofstream& oFile, const String& str) {
	int i = 0;
	while (str.arr[i]) {
		oFile << str.arr[i];
		i++;
	}
	return oFile;
}


char& String::operator[](const int i){
	if (i <= size && i >= 0) {
		return arr[i];
	}
}

int String::getCapacity() const{
	return capacity;
}

int String::getSize() const{
	return size;
}

void String::clear() {
	delete[] arr;
	arr = new char[1];
	if (arr == nullptr) {
		throw ("No memory for string(String::clear())!");
		return;
	}
	capacity = 1;
	size = 0;
}

bool String::operator==(const String& other) const{
	if (size != other.getSize()) return false;
	if (strcmp(arr, other.arr) == 0) return true;
	else return false;
}

bool String::operator==(const char* str) const {
	if (size != strlen(str)) return false;
	if (strcmp(arr, str) == 0) return true;
	else return false;
}

bool String::operator!=(const String& other) const {
	return !(*this == other);
}

bool String::operator!=(const char* str) const {
	return !(*this == str);
}
