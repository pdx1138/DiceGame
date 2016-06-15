// Bag.h
//
// This Header File will contain all the class definitions for the Table Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef TABLE_H
#define TABLE_H

#include "Dice\Dice.h"
#include "Bag.h"
#include "../Utility/LinkedList.h"

#define TABLE_MAX_DICE 10

namespace DiceGame {
	
	class Table {
		public:
			Table();
			~Table();

			void ReturnDiceToBag(DiceBag* bag);
			void AddDieToTable(Die* die);
			Die* RemoveDieFromTable();
			unsigned int GetRemainingNumberOfDiceOnTable();

			void PurgeTableOfDice();

		protected:
			LinkedList<Die*> dice;
			int* maxDice;
	};
}

#endif