/*
* File:   String.h
*
* Created on February 18, 2016, 6:17 PM
*/

#ifndef STRING_H
#define	STRING_H

class String {

public:
	String();
	~String();
	String(const String&);
	String(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
	StringBuffer* _str;
};


#endif	/* STRING_H */

