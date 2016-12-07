
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
	char* hello = "67LHFfgrMOoCV6VKpXfOTDh3fm30TszwgmW3NRGR27YqqxflXgsTXteTBICjTX2MbxszH48T1N4yVCv33EuzRax3gprV58EDAITEygnCSNkAUi4v3QTM7BKWjwNRo";


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

