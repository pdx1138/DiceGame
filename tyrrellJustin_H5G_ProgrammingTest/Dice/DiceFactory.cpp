// DiceFactory.cpp
//
// Contians the definitions for the Dice Factory Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DiceFactory.h"

namespace DiceGame {

	DiceFactory::DiceFactory() {

	}

	DiceFactory::~DiceFactory() {
	}

	Die* DiceFactory::GetDieFromFactory(DICE_TYPE dieType) {
		return options[(int)dieType]();
	}
}