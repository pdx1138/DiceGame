// Utility.cpp
//
// Contains definitions for basic test functionality for
// parts 2 and 3 of the test.
/////////////////////////////////////////////////////////////////////

#include "Utility.h"

namespace UTILITY {
	
	// Main Test Functions
	//////////////////////////////////////////////////////////////////////////////////

	void sum_str(char* a, char const* b, char const* c) {
		unsigned int bDigitCount = 0;	// Hold the number of digits in (b)
		unsigned int cDigitCount = 0;	// Hold the number of digits in (c)
		unsigned int aDigitCount = 0;	// Hold the number of digits in (a)
		int carry = 0;					// Holds the carry value when addition results in a number greater than 9
		
		bDigitCount = GetNumberOfDigits(b);
		cDigitCount = GetNumberOfDigits(c);

		// Determine Bigger Number
		(bDigitCount >= cDigitCount ?
						   PerformSum(a, b, c, bDigitCount, cDigitCount) :	// If b is larger, or equal, than make b the large number
						   PerformSum(a, c, b, cDigitCount, bDigitCount));	// If c is larger, then make c the large number		
	}

	void rotate(char* s, int n) {
		int progress = 0;

		while (progress < n) {
			for (int i = 1; s[i] != NULL; ++i) {
				char temp = s[i - 1];
				s[i - 1] = s[i];
				s[i] = temp;
			}
			++progress;
		}
	}

	// Test Helper Functions
	//////////////////////////////////////////////////////////////////////////////////

	int GetNumberOfDigits(char const* s) {
		int count = 0;
		for (int i = 0; s[i] != NULL; ++i) {
			++count;
		}

		return count;
	}

	// PerformSum will add the smaller number (s) into the larger number (l) and
	// store the result in the string (a).  It is assumed that (a) is properly
	// initialized and ready to hold the data.
	void PerformSum(char* a, char const* l, char const* s, unsigned int const lDigits, unsigned int const sDigits) {
		unsigned int resultDigitCount = lDigits;  // The smallest the resulting number could possibly be
		unsigned int cCurrentPosition = sDigits;  // Get our index for the ones position on the smaller (c) String
		
		unsigned int tracker = 0;
		char* rResult = nullptr;	// Temporary pointer to house the result in reverse order
		int carry = 0;				// Holds the carry value when addition results in a number greater than 9
		char buff[2];				// Temporary buffer for itoa _Buffer parameter

		// Need an additional space to ensure null termination, 
		// and make room for a potential extra digit.
		rResult = (char*)malloc(sizeof(char) * (resultDigitCount + 2));
		memset(rResult, NULL, (resultDigitCount + 2));

		for (unsigned int n = lDigits - 1; ; --n) {
			if (cCurrentPosition != 0) {
				char x = l[n];
				char y = s[cCurrentPosition - 1];

				int bNum = atoi(&x);
				int cNum = atoi(&y);

				int result = bNum + cNum + carry;

				carry = result / BASE_TEN;
				result %= BASE_TEN;

				char* z = _itoa(result, buff, BASE_TEN);
				rResult[tracker] = *z;
				rResult[tracker + 1] = NULL;
				--cCurrentPosition;
			}
			else {
				if (carry > 0) {
					char x = l[n];
					int bNum = atoi(&x);
					int result = bNum + carry;

					carry = result / BASE_TEN;
					result %= BASE_TEN;

					char* z = _itoa(result, buff, BASE_TEN);
					rResult[tracker] = *z;
					rResult[tracker + 1] = NULL;
				}
				else {
					char x = l[n];
					rResult[tracker] = x;
					rResult[tracker + 1] = NULL;
				}
			}

			++tracker;

			if (n == 0) break;
		}

		if (carry > 0) {
			// Addition resulted in another digit being added!!
			char buff[2];
			char* z = itoa(carry, buff, BASE_TEN);
			rResult[tracker] = *z;
			rResult[tracker + 1] = NULL;
		}

		// Put the result in the correct digit order
		ReverseString(a, rResult);
	}

	// Reverse the string (r) and store into string (a).
	// It is assumed that (a) is properly initialized and ready to hold the data.
	void ReverseString(char* a, char* r) {
		int size = GetNumberOfDigits(r);
		int aPosition = 0;		// Holds the current index into (a)

		for (int i = size - 1; i >= 0; --i, ++aPosition) {
			a[aPosition] = r[i];
		}
	}

	// Utility functions for parsing definitions
	//////////////////////////////////////////////////////////////////////////////////

	bool Check(char* sz, int readIndex, char* match) {
		int length = strlen(match);

		for (int i = 0; i < length; ++i) {
			if (Check(sz[i + readIndex], match[i]) == false) return false;
		}

		return true;
	}

	bool Check(char a, char b) {
		if (a == b) return true;
		return false;
	}

	bool IsDigit(char ch) {
		if (ch >= '0' && ch <= '9') return true;
		return false;
	}

	bool IsText(char ch) {
		if ((ch >= 'a' && ch <= 'z') == true ||
			(ch >= 'A' && ch <= 'Z') == true)
			return true;
		
		return false;
	}

	bool IsWhiteSpace(char ch) {
		if (ch == ' ') return true;
		if (ch == '\t') return true;
		if (ch == '\n') return true;
		
		return false;
	}
}