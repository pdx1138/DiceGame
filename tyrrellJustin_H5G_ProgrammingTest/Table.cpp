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

	void Table::ReturnDiceToBag(DiceBag* bag) {
		while (this->dice.Size() > 0) {
			bag->AddDieToBag(this->dice.Export(0));
		}
	}

	void Table::AddDieToTable(Die* die) {
		if (this->dice.Size() <= *this->maxDice) {
			this->dice.Append(die);
		}
	}

	Die* Table::RemoveDieFromTable() {
		if(this-dice.Size() > 0)
			return this->dice.Export(0);
		return nullptr;
	}

	unsigned int Table::GetRemainingNumberOfDiceOnTable() {
		return this->dice.Size();
	}

	void Table::PurgeTableOfDice() {
		this->dice.Purge();
	}
}