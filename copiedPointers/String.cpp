#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
	this->_str = new StringBuffer();
}
//destructor

String::~String() {

	delete[] this->_str;

}

//copy a const String into this string

String::String(const String& newString) {
	this->_str = newString._str;
}

//copy a char* into your string

String::String(char* newString, int length) {
	this->_str = new StringBuffer(newString, length);
}

void String::append(char c) {
	auto_ptr<StringBuffer> newdata(new StringBuffer);
	newdata.get()->reserve(this->_str->length() + 1);
	newdata.get()->smartCopy(this->_str);

	//now split the object instances
	this->_str = newdata.release();

	//copy the new character at the end of this string
	this->_str->append(c);

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