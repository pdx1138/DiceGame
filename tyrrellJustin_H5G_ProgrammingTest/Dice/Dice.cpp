// Dice.cpp
//
// Contains the definitions for the member functions of the various Die Classes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//#include <stdio.h>

#include "Dice.h"

namespace DiceGame {
	Die::Die() {
		this->type = (DICE_TYPE*)malloc(sizeof(DICE_TYPE));
		
		*this->type = DICE_TYPE::TYPE_ONE;

		//cout << "Adding Type One" << endl;
	}

	Die::~Die() {
		free(this->type);
	}

	DICE_TYPE Die::GetType() {
		return *this->type;
	}

	TypeTwoDie::TypeTwoDie() {
		*this->type = DICE_TYPE::TYPE_TWO;

		//cout << "Adding Type Two" << endl;
	}

	TypeThreeDie::TypeThreeDie() {
		*this->type = DICE_TYPE::TYPE_THREE;
		
		//cout << "Adding Type Three" << endl;
	}

	int TypeOneDie::GetDieRoll() {
		return Utility::GetRandomNumber(DICE_MIN, DICE_MAX);
	}

	int TypeTwoDie::GetDieRoll() {
		return Utility::GetRandomNumber(DICE_MIN, DICE_MAX) * 3;
	}

	int TypeThreeDie::GetDieRoll() {
		return Utility::GetRandomNumber(DICE_MIN, DICE_MAX) * 5;
	}

	Die* GetTypeOneDie() {
		return new TypeOneDie();
	}

	Die* GetTypeTwoDie() {
		return new TypeTwoDie();
	}

	Die* GetTypeThreeDie() {
		return new TypeThreeDie();
	}
}