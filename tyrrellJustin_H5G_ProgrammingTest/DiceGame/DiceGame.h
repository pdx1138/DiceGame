// DiceGame.h
//
// This Header File contains all the necessary declarations and 
// inclusions necessary to run the dice game laid out in the 
// programming test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef DICEGAME_H
#define DICEGAME_H

#include "Player.h"
#include "Bag.h"
#include "Table.h"

namespace DiceGame {

	void RunMenuOptionOne();
	void RunMenuOptionTwo();
	void RunMenuOptionThree();
	void RunMenuOptionFour();
	void RunMenuOptionFive();
	void RunMenuOptionSix();
	void RunMenuOptionSeven();

	typedef void (*MenuOptions)();

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
			void AutomatedGameLoop(unsigned int iterations);
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

			MenuOptions menuOptoins[7] = {
				RunMenuOptionOne,
				RunMenuOptionTwo,
				RunMenuOptionThree,
				RunMenuOptionFour,
				RunMenuOptionFive,
				RunMenuOptionSix,
				RunMenuOptionSeven
			};
	};
}

#endif // ! DICEGAME_H
