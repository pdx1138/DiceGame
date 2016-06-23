// BNF_Parser.cpp
//
// Contains function and class definitions for Backus-Naur From Parsing
/////////////////////////////////////////////////////////////////////

#include "BNF_Parser.h"

namespace BNF_Parser {

	// define basic global singlegons for fileStream
	ifstream fileStream;
	char* lineToParse = nullptr;
	Interface* iFace = nullptr;
	Spinner* spinner = nullptr;
	RollUp* rUp = nullptr;
	int lineIndex = 0;

	bool ParseFile(char* fileName) {
		//ifstream fileStream;
		fileStream.open(fileName);

		// Initialize Global Variables for File
		lineToParse = (char*)malloc(sizeof(char) * STRING_SIZE);
		memset(lineToParse, NULL, STRING_SIZE);
		iFace = new Interface();
		spinner = new Spinner();
		rUp = new RollUp();

		while (!fileStream.eof()) {
			ReadNextLine();
			DetermineAction();
		}

		return true;
	}

	void ReadNextLine() {
		fileStream.getline(lineToParse, STRING_SIZE, '\n');
		lineIndex = 0;
		ParseWhiteSpace();	// Get rid of any leading white space
	}

	void DetermineAction() {
		if (IsHeader(lineToParse, lineIndex) == true) {
			ParseHeader();
		}
		else if (IsFooter(lineToParse, lineIndex) == true) {

		}
		else {
			// Since we know the file is properly formated, 
			// We can assume this case will always be a property.
			ParseProperty();
		}
	}

	// Definitions for determination functions
	//////////////////////////////////////////////////////////////////

	bool IsHeader(char* sz, int readIndex) {
		if (UTILITY::Check(sz, readIndex, "TAG") == false) return false;
		return true;
	}

	bool IsFooter(char* sz, int readIndex) {
		if (UTILITY::Check(sz, readIndex, "END") == false) return false;
		return true;
	}

	bool IsProperty(char*sz, int readIndex) {
		return false;
	}

	// Parsing Definitions
	//////////////////////////////////////////////////////////////////

	bool ParseHeader() {
		ParseText();	// Parse the Header Tags, since we've alraedy verified their existence.

		ParseWhiteSpace();

		ParseHeaderName();
		return true;
	}

	bool ParseFooter() {
		return false;
	}

	bool ParseProperty() {
		ParseText();
		ParseColon();

		return false;
	}

	bool ParseColon() {
		if (lineToParse[lineIndex] == ':') {
			++lineIndex;
			return true;
		}

		return false;
	}

	void ParseWhiteSpace() {
		while (UTILITY::IsWhiteSpace(lineToParse[lineIndex]) == true) {
			++lineIndex;
		}
	}

	void ParseHeaderName() {
		if (UTILITY::Check(lineToParse, lineIndex, "INTERFACE") == true) {
			lineIndex += strlen("INTERFACE");
			// Get Redy to Parse an Interface...
			ReadNextLine();
			DetermineAction();
		}
		else if (UTILITY::Check(lineToParse, lineIndex, "BACKGROUND") == true) {
			lineIndex += strlen("BACKGROUND");
			ParseBackgroundData();
		}
		else if (UTILITY::Check(lineToParse, lineIndex, "SYMBOL") == true) lineIndex += strlen("SYMBOL");//return false;
		else if (UTILITY::Check(lineToParse, lineIndex, "SPINNER") == true) lineIndex += strlen("SPINNER");//return false;
		else if (UTILITY::Check(lineToParse, lineIndex, "DIRECTION") == true) lineIndex += strlen("DIRECTION");//return false;
		else if (UTILITY::Check(lineToParse, lineIndex, "ROLLUP") == true) lineIndex += strlen("ROLLUP");//return false;
		//return true;
	}

	void ParseText() {
		while (UTILITY::IsText(lineToParse[lineIndex]) == true) {
			++lineIndex;
		}
	}

	void ParseBackgroundData() {
		ReadNextLine();
		ParseProperty();
		iFace->GetBackground()->SetX(ParseInt());
		ReadNextLine();
		ParseProperty();
		iFace->GetBackground()->SetY(ParseInt());
		ReadNextLine();
		ParseProperty();
		iFace->GetBackground()->SetWidth(ParseInt());
		ReadNextLine();
		ParseProperty();
		iFace->GetBackground()->SetHeight(ParseInt());
	}

	int ParseInt() {
		// Check for number of digits
		int count = 0;
		while (UTILITY::IsDigit(lineToParse[lineIndex + count]) == true) {
			++count;
		}

		// Parse into int value
		int value = 0;

		if (count == 1) {
			char cNum = lineToParse[lineIndex];
			value = atoi(&cNum);
		}
		else if (count > 1) {
			// Implement support for more than one digit
			int temp = 0;
			while (count > 0) {
				char cNum = lineToParse[lineIndex + temp];
				int n = atoi(&cNum);
				value += pow(BASE_TEN, count - 1) * n;
				++temp;
				--count;
			}
		}		

		// return that int value
		return value;
	}
}