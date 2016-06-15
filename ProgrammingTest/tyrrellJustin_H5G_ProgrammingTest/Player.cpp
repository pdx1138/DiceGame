// Player.cpp
//
// Contains the definitions for the Player Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Player.h"

namespace DiceGame {
	
	Player::Player() {
		this->numGames = (unsigned int*)malloc(sizeof(unsigned int));
		this->totalScore = (unsigned int*)malloc(sizeof(unsigned int));
		this->totalBet = (unsigned int*)malloc(sizeof(unsigned int));

		this->myDiceBag = new DiceBag();
		*this->numGames = 0;
		*this->totalBet = 0;
		*this->totalScore = 0;
	}

	Player::~Player() {
		free(this->myDiceBag);
		free(this->numGames);
		free(this->totalBet);
		free(this->totalScore);
	}

	/*void Player::PopulatePlayerDiceBag(DiceFactory* df) {
		this->myDiceBag->PopulateBag(df);
	}*/

	void Player::IncreaseBet(unsigned int betAmount) {
		*this->totalBet += betAmount;
		++(*this->numGames);
	}

	Die* Player::RollDie() {
		return this->myDiceBag->GetRandomDieFromBag();
	}

	void Player::RecordScore(unsigned int score) {
		*this->totalScore += score;
	}

	unsigned int Player::GetRemainingNumberOfDieInBag() {
		return this->myDiceBag->GetNumberOfRemainingDie();
	}

	void Player::ReturnDieToBag(Die* die) {
		if (die == nullptr) return;
		this->myDiceBag->AddDieToBag(die);
	}

	DiceBag* Player::GetMyDiceBag() {
		return this->myDiceBag;
	}

	unsigned int Player::GetMyTotalScore() {
		return *this->totalScore;
	}

	unsigned int Player::GetMyTotalBet() {
		return *this->totalBet;
	}

	unsigned int Player::GetMyNumberOfGames() {
		return *this->numGames;
	}

	void Player::ReadyPlayerForGame(DiceFactory* df) {
		this->myDiceBag->PopulateBag(df);
		//++(*this->numGames);
	}

	void Player::ResetPlayerData() {
		*this->totalBet = 0;
		*this->totalScore = 0;
		*this->numGames = 0;
	}

	/*void Player::PurgeMyDiceBag() {
		*this->myDiceBag->	}*/
}