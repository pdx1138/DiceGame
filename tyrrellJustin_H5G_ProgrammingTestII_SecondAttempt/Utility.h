// Utility.h
//
// Contains declarations for basic test functionality for
// parts 2 and 3 of the test.
//////////////////////////////////////////////////////////////////////

#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <iostream>

#define STRING_SIZE 512
#define BASE_TEN 10
#define LARGE_NUMBER 1000000

namespace UTILITY {

	// Main Test Functions
	void sum_str(char* a, char const* b, char const* c);
	void rotate(char* s, int n);

	// Test Helper Functions
	int GetNumberOfDigits(char const* s);
	void PerformSum(char* a, char const* l, char const* s, unsigned int const lDigits, unsigned int const sDigits);
	void ReverseString(char* a, char* r);

	// Utility functions for parsing
	bool Check(char* sz, int readIndex, char* match);
	bool Check(char a, char b);
	bool IsDigit(char ch);
	bool IsText(char ch);
	bool IsWhiteSpace(char ch);
}

#endif // !UTILITY_H
