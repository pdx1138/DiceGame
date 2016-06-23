// BNF_Parser.h
//
// Contains declarations and classes necessary for parsing
// via a Backus-Naur Form.
/////////////////////////////////////////////////////////////////////

#pragma once

#ifndef BNF_PARSER_H
#define BNF_PARSER_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>

#include "Utility.h"
#include "PartOne\Interface.h"
#include "PartOne\Spinner.h"
#include "PartOne\RollUp.h"

using namespace std;

namespace BNF_Parser {

	// declare basic global singlegons for fileStream
	extern ifstream fileStream;
	extern char* lineToParse;
	extern Interface* iFace;
	extern Spinner* spinner;
	extern RollUp* rUp;
	extern int lineIndex;

	bool ParseFile(char* fileName);
	void ReadNextLine();
	void DetermineAction();

	// Determine if line is a Header, a Footer, or a property
	bool IsHeader(char* sz, int readIndex);
	bool IsFooter(char* sz, int readIndex);
	bool IsProperty(char*sz, int readIndex);

	// Parse a Header, Footer, or Property
	bool ParseHeader();
	bool ParseFooter();
	bool ParseProperty();
	bool ParseColon();
	void ParseWhiteSpace();
	void ParseHeaderName();
	void ParseText();
	void ParseBackgroundData();
	int ParseInt();
}

#endif // !BNF_PARSER_H
