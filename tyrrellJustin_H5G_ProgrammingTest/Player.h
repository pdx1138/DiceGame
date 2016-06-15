// Player.h
//
// This Header File will contain all the class definitions for the Player Class
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Dice\DiceFactory.h"
#include "Bag.h"

namespace DiceGame {

	class Player {
		public:
			Player();
			~Player();

			/*void PopulatePlayerDiceBag(DiceFactory* df);*/
			void IncreaseBet(unsigned int betAmount);
			Die* RollDie();
			void RecordScore(unsigned int score);
			unsigned int GetRemainingNumberOfDieInBag();
			void ReturnDieToBag(Die* die);

			DiceBag* GetMyDiceBag();
			unsigned int GetMyTotalScore();
			unsigned int GetMyTotalBet();
			unsigned int GetMyNumberOfGames();

			void ReadyPlayerForGame(DiceFactory* df);

			void ResetPlayerData();

		private:
			DiceBag* myDiceBag;
			unsigned int* numGames;
			unsigned int* totalScore;
			unsigned int* totalBet;

			void PurgeMyDiceBag();
			//void ReadyPlayerForGame(DiceFactory* df);
	};
}

#endif // !PLAYER_H
