#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
    this->_str = new StringBuffer();
	this->prev = NULL;
	this->next = NULL;
}
//destructor

String::~String() {

    if (this->prev == this->next) {
		this->prev = NULL;
		this->next = NULL;
		delete[] this->_str;
    }
}

//copy a const String into this string

String::String(String& newString) {
    this->_str = newString._str;
	this->next = NULL;
	this->prev = NULL;

	String* temp = &newString;

	if (temp->next != NULL) {
		while (temp->next != this) {
			temp = temp->next;
		}
		this->prev = &newString;
		this->next = &newString;
		temp->next = this;
		newString.prev = this;
	}
	else
	{
		this->next = &newString;
		this->prev = &newString;
		newString.next = this;
		newString.prev = this;


	}

	    
}

//copy a char* into your string

String::String(char* newString, int length) {
    this->_str = new StringBuffer(newString, length);
    
	this->next = NULL;
	this->prev = NULL;
}

void String::append(char c)
{
	if (this->next != NULL) {
		auto_ptr<StringBuffer> newdata(new StringBuffer);
		newdata.get()->reserve(this->_str->length() + 1);
		newdata.get()->smartCopy(this->_str);

		this->next->prev = this->prev;
		this->prev->next = this->next;
		this->next = NULL;
		this->prev = NULL;

		this->_str = newdata.release();
	}
	else {
		this->_str->reserve(this->_str->length() + 1);
	}

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
    } else {
        //throw new IndexOutOfBoundException();

    }
}

//get reference count of the string

int String::referenceCount()
{
	int count = 1;
	String* temp = this;
	while ((temp->next != this) && (temp->next != NULL))
	{
		temp = temp->next;
		count++;
	}

	return count;
}