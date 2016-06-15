// DiceFactory.h
//
// This Header File will contain the class definition for the Die Factory;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef DICE_FACTORY_H
#define DICE_FACTORY_H

#include "Dice.h"

namespace DiceGame {

	typedef Die* (*DieOptions)();

	class DiceFactory {
	public:
		DiceFactory();
		~DiceFactory();

		Die* GetDieFromFactory(DICE_TYPE dieType);

	private:
		DieOptions options[3] = {
			GetTypeOneDie,
			GetTypeTwoDie,
			GetTypeThreeDie
		};
	};
}

#endif // !DICE_FACTORY_H