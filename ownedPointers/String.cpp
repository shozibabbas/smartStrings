#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
	this->_str = new StringBuffer();
	this->ownership = true;
}
//destructor

String::~String() {

	if (this->ownership) {
		delete[] this->_str;
	}

}

//copy a const String into this string

String::String(String& newString) {
	if (newString.ownership) {
		this->_str = newString._str;
		newString.ownership = false;
		this->ownership = true;
	}
}

//copy a char* into your string

String::String(char* newString, int length) {
	this->_str = new StringBuffer(newString, length);
	this->ownership = true;
}

void String::append(char c) {

	if (this->ownership) {
		this->_str->reserve(this->_str->length() + 1);
		this->_str->smartCopy(this->_str);

		this->_str->append(c);
	}
}

//get length of the string

int String::length() const {
	return this->_str->length();
}

//get character at index if it is less than length

char String::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		throw new exception();
	}
}