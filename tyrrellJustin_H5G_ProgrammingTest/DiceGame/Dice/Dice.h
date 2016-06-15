// Dice.h
//
// This Header File will contain all the class definitions for all Die Classes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef DICE_H
#define DICE_H

#define DICE_MIN 1
#define DICE_MAX 6

#include "../../Utility/Utility.h"

using namespace std;

namespace DiceGame {

	enum DICE_TYPE {
		TYPE_ONE,
		TYPE_TWO,
		TYPE_THREE
	};

	// Base Virtual Class for Die
	class Die {

		public:
			Die();
			~Die();

			virtual int GetDieRoll() = 0;
			DICE_TYPE GetType();

		protected:
			DICE_TYPE* type;
	};

	// Die of Type One
	class TypeOneDie : public Die {
		public:
			TypeOneDie() : Die() { }

			virtual int GetDieRoll();
	};

	// Die of Type Two
	class TypeTwoDie : public TypeOneDie {
		public:
			TypeTwoDie();

			virtual int GetDieRoll();
	};

	// Die of Type Three
	class TypeThreeDie : public TypeOneDie {
		public:
			TypeThreeDie();

			virtual int GetDieRoll();
	};

	Die* GetTypeOneDie();
	Die* GetTypeTwoDie();
	Die* GetTypeThreeDie();
}

#endif // !DICE_H