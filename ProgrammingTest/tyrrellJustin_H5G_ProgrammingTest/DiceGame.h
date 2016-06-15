// DiceGame.h
//
// This Header File contains all the necessary declarations and 
// inclusions necessary to run the dice game laid out in the 
// programming test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef DICEGAME_H
#define DICEGAME_H
//
//#define COST_OF_GAME 17
//#define MAX_NUM_OF_VISIBLE_GAMES 20 

#include "Player.h"
#include "Bag.h"
#include "Table.h"

namespace DiceGame {

	class GameResult {
	public:
		GameResult();
		~GameResult();

		void AddDieResult(int result);
		unsigned int GetCurrentGameScore();
		void DrawGameResult();
		unsigned int GameWin();
		unsigned int GameLose();
		void SetToDateValues(unsigned int score, unsigned int bet, unsigned int ngames);
		/*int numDie;
		int numTable;*/

	private:
		int dieRolls[BAG_MAX_DICE];
		unsigned int* winAmount;
		unsigned int* scoreToDate;
		unsigned int* betToDate;
		unsigned int* scoreTracker;
		unsigned int* numGamesTracker;
	};

	class Game {
		public:
			Game();
			~Game();

			static Game* GetInstance();
			int RunDiceGame();
			void GameLoop();
			void AutomatedGameLoop(unsigned int itterations);
			bool CheckContinue();
			void PlayAGame();
			void GameWin(GameResult* result);
			void GameLose(GameResult* result);
			void DrawScreen();
			void AddGameResult(GameResult* result);

			int DisplayMenuOptoins();
			void ExecuteMenuOption(int option);
			void ExecuteCustomCount();
			void ResetGameResults();

		private:
			static Game* instance;
			Player* player;
			DiceFactory* diceFactory;
			Table* gameTable;
			LinkedList<GameResult*> recentResults;

			void GameEnd(GameResult* result);
			void RollForGame(GameResult* resultTracking);
			//void PurgeGameData();
	};
}

#endif // ! DICEGAME_H
