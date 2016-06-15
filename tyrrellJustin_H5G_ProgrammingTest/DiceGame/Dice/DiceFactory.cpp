// DiceFactory.cpp
//
// Contians the definitions for the Dice Factory Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DiceFactory.h"

namespace DiceGame {

	DiceFactory::DiceFactory() {
		// No Op
	}

	DiceFactory::~DiceFactory() {
		// No Op
	}

	Die* DiceFactory::GetDieFromFactory(DICE_TYPE dieType) {
		return options[(int)dieType]();
	}
}