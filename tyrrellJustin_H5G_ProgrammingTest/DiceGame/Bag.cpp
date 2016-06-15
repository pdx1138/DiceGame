// Bag.cpp
//
// Contains all the definitions for the Bag Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Bag.h"

namespace DiceGame {
	
	DiceBag::DiceBag() {
		this->maxDice = (unsigned int*)malloc(sizeof(unsigned int));
		this->numTypeOneDice = (unsigned int*)malloc(sizeof(unsigned int));
		this->numTypeTwoDice = (unsigned int*)malloc(sizeof(unsigned int));
		this->numTypeThreeDice = (unsigned int*)malloc(sizeof(unsigned int));
		
		*this->maxDice = BAG_MAX_DICE;
		*this->numTypeOneDice = 0;
		*this->numTypeTwoDice = 0;
		*this->numTypeThreeDice = 0;
	}

	DiceBag::~DiceBag() {
		this->dice.Purge();
		free(this->maxDice);
		free(this->numTypeOneDice);
		free(this->numTypeTwoDice);
		free(this->numTypeThreeDice);
	}

	Die* DiceBag::GetRandomDieFromBag() {
		unsigned int count = this->GetNumberOfRemainingDie();
		
		unsigned int index = 0;
		if(count > 1) index = Utility::GetRandomNumber(0, count - 1);
		else if (count == 1) index = 0;
		
		Die* returnValue = dice.Export((int)index);

		// Basic Error Check 
		if (returnValue == nullptr)
			cout << "Null Retrun Value" << endl;

		this->UpdateBagCount(returnValue->GetType(), -1);
		
 		return returnValue;
	}

	void DiceBag::AddDieToBag(Die* die) {
		if (die == nullptr) {
			cout << "null pointer" << endl;
			system("pause");
			return;
		}
		if (this->dice.IsInList(die) == true) {
			cout << "Die Already In List" << endl;
			system("pause");
			return;
		}
		if (*this->maxDice > (unsigned int) this->dice.Size()) {
			this->dice.Append(die);
			this->UpdateBagCount(die->GetType(), 1);
		}
	}
	
	void DiceBag::PopulateBag(DiceFactory* factory) {
		if (factory == nullptr) return;
		
		// If the Bag contains any die, get rid of them
		if (this->dice.Size() > 0) this->PurgeDiceFromBag();

		// Add die to the bag
		for (int i = 0; i < BAG_MAX_DICE; ++i) {
			if (*this->numTypeThreeDice < MAX_TYPETHREE_DICE) {
				this->dice.Append(factory->GetDieFromFactory(DICE_TYPE::TYPE_THREE));
				this->UpdateBagCount(DICE_TYPE::TYPE_THREE, 1);
			}
			else if (*this->numTypeTwoDice < MAX_TYPETWO_DICE) {
				this->dice.Append(factory->GetDieFromFactory(DICE_TYPE::TYPE_TWO));
				this->UpdateBagCount(DICE_TYPE::TYPE_TWO, 1);
			}
			else if (*this->numTypeOneDice < MAX_TYPEONE_DICE) {
				this->dice.Append(factory->GetDieFromFactory(DICE_TYPE::TYPE_ONE));
				this->UpdateBagCount(DICE_TYPE::TYPE_ONE, 1);
			}
			else {
				// Basic Error Checking
				cout << "Error with adding dice into the bag.";
				system("pause");
			}
		}
	}

	unsigned int DiceBag::GetNumberOfRemainingDie() {
		return dice.Size();
	}

	unsigned int DiceBag::GetNumberOfTypeOneDice() {
		return *this->numTypeOneDice;
	}

	unsigned int DiceBag::GetNumberOfTypeTwoDice() {
		return *this->numTypeTwoDice;
	}

	unsigned int DiceBag::GetNumberOfTypeThreeDice() {
		return *this->numTypeThreeDice;
	}

	// Private Member Declarations
	/////////////////////////////////////////////////////////////////////////////

	// Get rid of all dice
	void DiceBag::PurgeDiceFromBag() {
		this->dice.Purge();
		*this->numTypeOneDice = 0;
		*this->numTypeTwoDice = 0;
		*this->numTypeThreeDice = 0;
	}

	// Update the amount in the bag of the given type of die
	// returns (true) if update successful
	// return (false) if update unsuccessful
	void DiceBag::UpdateBagCount(DICE_TYPE dt, int amount) {
		if (dt == DICE_TYPE::TYPE_ONE) {
			DiceBag::UpdateSingleCount(this->numTypeOneDice, amount);
		}
		else if (dt == DICE_TYPE::TYPE_TWO) {
			DiceBag::UpdateSingleCount(this->numTypeTwoDice, amount);
		}
		else if (dt == DICE_TYPE::TYPE_THREE) {
			DiceBag::UpdateSingleCount(this->numTypeThreeDice, amount);
		}
	}

	// Given a pointer to data, update that location with the 
	// given amount, provided it won't drop the num to below zero
	// and cause the unsigned int MSb to be set.
	void DiceBag::UpdateSingleCount(unsigned int* num, int amount) {
		if (*num == 0 && amount < 0) return;
		*num += amount;
	}

	// Given a type and count, Verify that the bag contains the 
	// count of the given type.
	bool DiceBag::VerifyDiceCountInBag(DICE_TYPE dt, unsigned int count) {
		int tracker = 0;

		for (int n = 0; n < this->dice.Size(); ++n) {
			if (this->dice.Find(n)->GetType() == dt) {
				++tracker;
			}
		}

		if (tracker == count) return true;
		return false;
	}
}