// Table.cpp
//
// Contains the definitions for the Table Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Table.h"

namespace DiceGame {

	Table::Table() {
		this->maxDice = (int*)malloc(sizeof(int));

		*this->maxDice = TABLE_MAX_DICE;
	}

	Table::~Table() {
		this->dice.Purge();
		free(this->maxDice);
	}

	// Given a Dice Bag, export all our dice to said bag
	void Table::ReturnDiceToBag(DiceBag* bag) {
		while (this->dice.Size() > 0) {
			bag->AddDieToBag(this->dice.Export(0));
		}
	}

	// Accept a die to the table, provided we have enough room
	void Table::AddDieToTable(Die* die) {
		if (this->dice.Size() <= *this->maxDice) {
			this->dice.Append(die);
		}
	}

	// Remove die from table via FIFO method
	Die* Table::RemoveDieFromTable() {
		if(this-dice.Size() > 0)
			return this->dice.Export(0);
		return nullptr;
	}

	// Get the total number of die currently on the table
	unsigned int Table::GetRemainingNumberOfDiceOnTable() {
		return this->dice.Size();
	}

	// Delete all die from the table
	// This will delete pointer data
	void Table::PurgeTableOfDice() {
		this->dice.Purge();
	}
}