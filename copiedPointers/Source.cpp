
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "StringBuffer.h"
#include "String.h"
#include <stdlib.h>
using namespace std;

/*
*
*/
int main() {
	//create a smart string
	//String ss;
	//create a smart string with const char*
	char* hello = "QVweNsV0XWOpcpz6wGU4ZFbCHgJVqaHTNwMg8qpMRimKpnaoRDFY8ZqgKnl4jx2h76YpLHNqkM8lY0xqgScavsnCHDqebLhbzK1ZXywpLWoUpF3YhTOsbllVtxZNz";


	String ss2(hello, 5);
	std::cout << "ss2 length = " << ss2.length() << std::endl;
	cout << hello << endl;
	//multiple references
	String ss(ss2);
	cout << hello << endl;
	//output statements
	std::cout << "ss length = " << ss.length() << std::endl;
	std::cout << "new ss charAt 0 = " << ss.charAt(0) << std::endl;
	//append a character
	ss2.append('w');
	cout << hello << endl;
	hello = "bye";

	std::cout << "new ss length = " << ss.length() << std::endl;
	std::cout << "new ss2 length = " << ss2.length() << std::endl;
	return 0;
}

