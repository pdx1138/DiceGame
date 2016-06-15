// Utility.cpp
//
// Contains declarations for Utility functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Utility.h"

namespace Utility {

	int GetRandomNumber(int min, int max) {
		mt19937::result_type seed = (unsigned int)chrono::high_resolution_clock::now().time_since_epoch().count();
		auto realRand = bind(uniform_int_distribution<int>(min, max), mt19937(seed)/*mtRand.seed*/);

		return realRand();
	}

	bool IsPrimeNumber(unsigned int num) {
		if (num == 1) return false;

		bool isPrime = true;

		//primeNumber

		for (int i = 0; i < MAX_NUMBER_OF_POSSIBLE_PRIME_NUMBERS; ++i) {
			if (num == primeNumbers[i]) return true;
		}
		return false;

		//for (int i = 2; i < num; ++i) {
		//	if (num % i == 0) isPrime = false;//return false;
		//}

		//return isPrime;
		//return true;
	}

}