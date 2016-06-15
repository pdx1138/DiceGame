// Bag.h
//
// This Header File will contain all the class definitions for the Bag Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef BAG_H
#define BAG_H

#include "Dice\DiceFactory.h"
#include "..\Utility\LinkedList.h"

#define BAG_MAX_DICE 10
#define NUM_DICE_TYPE 3
#define MAX_TYPEONE_DICE 7
#define MAX_TYPETWO_DICE 2
#define MAX_TYPETHREE_DICE 1

namespace DiceGame {

	class DiceBag{
		public:
			DiceBag();
			~DiceBag();

			Die* GetRandomDieFromBag();
			void AddDieToBag(Die* die);
			void PopulateBag(DiceFactory* factory);
			unsigned int GetNumberOfRemainingDie();

			unsigned int GetNumberOfTypeOneDice();
			unsigned int GetNumberOfTypeTwoDice();
			unsigned int GetNumberOfTypeThreeDice();

		protected:
			LinkedList<Die*> dice;
			unsigned int* maxDice;
			unsigned int* numTypeOneDice;
			unsigned int* numTypeTwoDice;
			unsigned int* numTypeThreeDice;

			void PurgeDiceFromBag();
			void UpdateBagCount(DICE_TYPE dt, int amount);
			static void UpdateSingleCount(unsigned int* num, int amount);
			bool VerifyDiceCountInBag(DICE_TYPE dt, unsigned int count);
	};

}

#endif // !BAG_H
