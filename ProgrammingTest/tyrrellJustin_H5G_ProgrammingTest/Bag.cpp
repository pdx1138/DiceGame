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
		//this->diceCount = (unsigned int*)malloc(sizeof(unsigned int) * NUM_DICE_TYPE);

		*this->maxDice = BAG_MAX_DICE;
		*this->numTypeOneDice = 0;
		*this->numTypeTwoDice = 0;
		*this->numTypeThreeDice = 0;

		/*for (int i = 0; i < NUM_DICE_TYPE; ++i) {
			*this->diceCount[i] = 0;
		}*/
	}

	DiceBag::~DiceBag() {
		this->dice.Purge();
		free(this->maxDice);
		free(this->numTypeOneDice);
		free(this->numTypeTwoDice);
		free(this->numTypeThreeDice);
		/*for (int i = 0; i < NUM_DICE_TYPE; ++i) {
			free(this->diceCount[i]);
		}*/
	}

	Die* DiceBag::GetRandomDieFromBag() {
		unsigned int count = this->GetNumberOfRemainingDie();
		
		unsigned int index = -1;
		if(count > 1) index = Utility::GetRandomNumber(0, count - 1);
		else if (count == 1) index = 0;
		
		Die* returnValue = dice.Export((int)index);
		if (returnValue == NULL)
			cout << "Null Retrun Value" << endl;
		this->UpdateBagCount(returnValue->GetType());
		
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
			//if(this->diceCount[(int)die->GetType()])
			this->dice.Append(die);
			//++(this->diceCount[(int)die->GetType()]);
		}
		/*else {
			cout << "Already at max" << endl;
			system("pause");
		}*/

	}
	
	void DiceBag::PopulateBag(DiceFactory* factory) {
		if (factory == nullptr) return;
		if (this->dice.Size() > 0) this->PurgeDiceFromBag();
		for (int i = 0; i < BAG_MAX_DICE; ++i) {
			// Whenever i is divisible by 5 
			// AND We have less than MAX_TYPETHREE_DICE
			// Create a TypeThree Die
			if (i % 5 == 0 && *this->numTypeThreeDice < MAX_TYPETHREE_DICE) {
				this->dice.Append(factory->GetDieFromFactory(DICE_TYPE::TYPE_THREE));
				++(*this->numTypeThreeDice);//++(*this->diceCount[(int)DICE_TYPE::TYPE_THREE]);//++(*this->numTypeThreeDice);
			}
			else if (i % 4 == 0 && *this->numTypeTwoDice < MAX_TYPETWO_DICE) {
				this->dice.Append(factory->GetDieFromFactory(DICE_TYPE::TYPE_TWO));
				++(*this->numTypeTwoDice);//++(*this->diceCount[(int)DICE_TYPE::TYPE_TWO]); //++(*this->numTypeTwoDice);
			}
			else if (*this->numTypeOneDice < MAX_TYPEONE_DICE) {
				this->dice.Append(factory->GetDieFromFactory(DICE_TYPE::TYPE_ONE));
				++(*this->numTypeOneDice);//++(*this->diceCount[(int)DICE_TYPE::TYPE_ONE]); //++(*this->numTypeOneDice);
			}
			else {
				cout << "Error with adding dice into the bag.";
				system("pause");
			}
		}

		//if (this->VerifyDiceInBag(DICE_TYPE::TYPE_ONE, MAX_TYPEONE_DICE) == true) cout << "TYPE ONE VERIFIED\n";
		//if (this->VerifyDiceInBag(DICE_TYPE::TYPE_TWO, MAX_TYPETWO_DICE) == true) cout << "TYPE TWO VERIFIED\n";
		//if (this->VerifyDiceInBag(DICE_TYPE::TYPE_THREE, MAX_TYPETHREE_DICE) == true) cout << "TYPE THREE VERIFIED\n";
		//
		//system("pause");
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

	void DiceBag::PurgeDiceFromBag() {
		this->dice.Purge();
		*this->numTypeOneDice = 0;
		*this->numTypeTwoDice = 0;
		*this->numTypeThreeDice = 0;
	}

	void DiceBag::UpdateBagCount(DICE_TYPE dt) {
		if (dt == DICE_TYPE::TYPE_ONE) {
			DiceBag::UpdateSingleCount(this->numTypeOneDice);
			/*if (*this->numTypeOneDice <= 0) {
				cout << "\nError With Bag Count Update\n";
				return;
			}
			--(*this->numTypeOneDice);*/
		}
		else if (dt == DICE_TYPE::TYPE_TWO) {
			DiceBag::UpdateSingleCount(this->numTypeTwoDice);
			/*if (*this->numTypeTwoDice <= 0) {
				cout << "\nError With Bag Count Update\n";
				return;
			}
			--(*this->numTypeTwoDice);*/
		}
		else if (dt == DICE_TYPE::TYPE_THREE) {
			DiceBag::UpdateSingleCount(this->numTypeThreeDice);
			/*if (*this->numTypeThreeDice <= 0) {
				cout << "\nError With Bag Count Update\n";
				return;
			}
			--(*this->numTypeThreeDice);*/
		}
	}

	void DiceBag::UpdateSingleCount(unsigned int* num) {
		//if (*num == 0) {
		//	cout << "\nNumber Already Zero\n";

		//	system("pause");/**/
		//	return;
		//}
		if (*num == 0) return;
		--(*num);
	}

	bool DiceBag::VerifyDiceInBag(DICE_TYPE dt, unsigned int size) {
		int count = 0;

		for (int n = 0; n < this->dice.Size(); ++n) {
			if (this->dice.Find(n)->GetType() == dt) {
				++count;
			}
		}

		if (count == size) return true;
		return false;
	}
}