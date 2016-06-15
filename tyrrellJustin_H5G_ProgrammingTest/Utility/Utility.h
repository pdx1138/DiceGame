// Utility.h
//
// This Header File contains declarations and inclusions necessary 
// to run basic functions necessary throughout the program.  Also
// contains some #defines that will be used at various points
// in the program.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#define QUIT_MENU_OPTION 8

#define COST_OF_GAME 17
#define MAX_NUM_OF_VISIBLE_GAMES 20 

#define MENU_OPTION_ONE_ITERATIONS 10
#define MENU_OPTION_TWO_ITERATIONS 100
#define MENU_OPTION_THREE_ITERATIONS 1000
#define MENU_OPTION_FOUR_ITERATIONS 10000
#define MENU_OPTION_FIVE_ITERATIONS 100000
#define MAX_NUMBER_OF_CUSTOM_ITERATIONS 10000000

#define MAX_NUMBER_OF_POSSIBLE_PRIME_NUMBERS 28

using namespace std;

namespace Utility {

	static unsigned int primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107 };

	int GetRandomNumber(int min, int max);
	bool IsPrimeNumber(unsigned int num);
}


#endif // !UTILITY_H
