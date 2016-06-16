#include "main.h"

int main(int argc, char* argv[]) {
	StringRotateTest();

	SumStringTest();	

	FileParseTest("testFile.txt");

	return 0;
}

void StringRotateTest() {
	char* str = (char*)malloc(sizeof(char) * STRING_SIZE);
	char ch;
	memset(str, 0, STRING_SIZE);
	strcpy(str, "hello");
	rotate(str, 3);
	cout << str << endl;

	system("pause");

	free(str);
}

void SumStringTest() {
	char* str1 = (char*)malloc(sizeof(char) * STRING_SIZE);
	char* str2 = (char*)malloc(sizeof(char) * STRING_SIZE);
	char* str3 = (char*)malloc(sizeof(char) * STRING_SIZE);

	memset(str1, 0, STRING_SIZE);
	strcpy(str1, "85886");

	memset(str2, 0, STRING_SIZE);
	strcpy(str2, "787878");

	memset(str3, 0, STRING_SIZE);
	//strcpy(str3, "");

	sum_str(str3, str1, str2);

	cout << "Value 1: " << str1 << endl
		 << "Value 2: " << str2 << endl
	     << "Result: " << str3 << endl;

	system("pause");

	free(str1);
	free(str2);
	free(str3);
}

void FileParseTest(char* fileName) {
	// Open File
	ifstream mystream;
	mystream.open(fileName);

	char* parseText = (char*)malloc(sizeof(char) * STRING_SIZE);
	memset(parseText, 0, STRING_SIZE);

	Interface* iFace = new Interface();

	while (!mystream.eof()) {
		// Read until WhiteSpace
		mystream >> parseText;
		// If a "TAG", then create a new instane of that tag type
		if (strcmp(parseText, "TAG") == 0) {
			//memset(parseText, 0, STRING_SIZE);
			mystream >> parseText;
			if (strcmp(parseText, "INTERFACE") == 0) {
				//cout << "interface\n";
				mystream >> parseText;		// Since we can assume the file will be properly formated, we can skip the TAG check
				mystream >> parseText;
				if (strcmp(parseText, "BACKGROUND") == 0) {
					//cout << "background\n";
					mystream.getline(parseText, STRING_SIZE, ':');// >> parseText;		// Since we can assume the file will be properly formated, we can skip the X check
					mystream >> parseText;
					int n = atoi(parseText);
					iFace->GetBackground()->SetX(n);
					mystream.getline(parseText, STRING_SIZE, ':');// >> parseText;		// Since we can assume the file will be properly formated, we can skip the X check
					mystream >> parseText;
					n = atoi(parseText);
					iFace->GetBackground()->SetY(n);
					mystream.getline(parseText, STRING_SIZE, ':');// >> parseText;		// Since we can assume the file will be properly formated, we can skip the X check
					mystream >> parseText; 
					n = atoi(parseText);
					iFace->GetBackground()->SetWidth(n);
					mystream.getline(parseText, STRING_SIZE, ':');// >> parseText;		// Since we can assume the file will be properly formated, we can skip the X check
					mystream >> parseText;
					n = atoi(parseText);
					iFace->GetBackground()->SetHeight(n);
				}
			}
			else if (strcmp(parseText, "SPINNER") == 0) {

			}
			else if (strcmp(parseText, "ROLLUP") == 0) {

			}
		}
		else if (strcmp(parseText, "END") == 0) {

		}
			// Access appropriate function to read in "PROPERTIES"
				// If Interface
					// read in Background data (x, y, w, h);
					// read in Symbol data (w, h);
				// If Spinner
					// Read in Spinner Data
				// if RollUp
					// Read in RollUp Data
		// If "FOOTER", we're done reading this portion

	}

	mystream.close();

	free(parseText);
}