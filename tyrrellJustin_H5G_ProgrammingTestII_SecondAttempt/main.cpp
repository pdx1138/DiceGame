// main.cpp
//
// Contains definitions for basic program functionality
/////////////////////////////////////////////////////////////////

#include "main.h"

int main(int argc, char* argv[]) {

	StringRotateTest();

	SumStringTest();

	ParseTest();

	return 0;
}

void SumStringTest() {

	char* str1 = (char*)malloc(sizeof(char) * STRING_SIZE);
	char* str2 = (char*)malloc(sizeof(char) * STRING_SIZE);
	char* str3 = (char*)malloc(sizeof(char) * LARGE_NUMBER);

	memset(str1, 0, STRING_SIZE);
	strcpy(str1, "85848848484848484886");
	//strcpy(str1, "119553");

	memset(str2, 0, STRING_SIZE);
	strcpy(str2, "78748484848484848878");
	//strcpy(str2, "457");

	memset(str3, 0, LARGE_NUMBER);

	sum_str(str3, str1, str2);

	cout << "Value 1: " << str1 << endl
		 << "Value 2: " << str2 << endl
		 << "Result: " << str3 << endl;

	system("pause");

	free(str1);
	free(str2);
	free(str3);
}

void StringRotateTest() {
	char* str = (char*)malloc(sizeof(char) * STRING_SIZE);
	memset(str, 0, STRING_SIZE);
	strcpy(str, "hello My Buddy, Guy, and Fwend!");
	rotate(str, 87);
	cout << str << endl;

	system("pause");

	free(str);
}

void ParseTest() {
	//"testFile.txt"
	BNF_Parser::ParseFile("testFile.txt");
	
	system("pause");

	delete BNF_Parser::iFace;		// Make sure we free our data!!
	delete BNF_Parser::spinner;
	delete BNF_Parser::rUp;

	free(BNF_Parser::lineToParse);
}