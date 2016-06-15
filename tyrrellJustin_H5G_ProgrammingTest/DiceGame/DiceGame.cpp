// DiceGame.cpp
//
// Contains all the definitions for the DiceGame.h Header File.
// Defines all functionality laied out in the programming test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DiceGame.h"

namespace DiceGame {

	// Set Singleton to Null
	Game* Game::instance = NULL;

	// Constructors
	/////////////////////////////////////////////////

	Game::Game() {
		this->player = new Player();
		this->diceFactory = new DiceFactory();
		this->gameTable = new Table();
	}

	GameResult::GameResult() {
		this->winAmount = (unsigned int*)malloc(sizeof(unsigned int));
		this->scoreTracker = (unsigned int*)malloc(sizeof(unsigned int));
		this->scoreToDate = (unsigned int*)malloc(sizeof(unsigned int));
		this->betToDate = (unsigned int*)malloc(sizeof(unsigned int));
		this->numGamesTracker = (unsigned int*)malloc(sizeof(unsigned int));

		for (int i = 0; i < BAG_MAX_DICE; ++i) {
			this->dieRolls[i] = 0;
		}

		*this->winAmount = 0;
		*this->scoreTracker = 0;
		*this->scoreToDate = 0;
		*this->betToDate = 0;
		*this->numGamesTracker = 0;
	}

	// Destructors
	/////////////////////////////////////////////////

	Game::~Game() {
		delete(instance->player);
		delete(instance->diceFactory);
		delete(instance->gameTable);
		recentResults.Purge();
	}

	GameResult::~GameResult() {
		free(this->winAmount);
		free(this->scoreToDate);
		free(this->scoreTracker);
		free(this->betToDate);
	}

	// Game Class Definitions
	/////////////////////////////////////////////////	

	// Get the instance of the Game Singleton
	// If the instance does not exist, create one
	Game* Game::GetInstance() {
		if (instance == nullptr) {
			instance = new Game();
		}
		return instance;
	}

	// Run the Dice Game until the user chooses to leave
	int Game::RunDiceGame() {
		int menuOption = -1;

		do {
			instance->ResetGameResults();
			instance->player->ResetPlayerData();
			menuOption = instance->DisplayMenuOptoins();
			instance->ExecuteMenuOption(menuOption);
		} while (menuOption != QUIT_MENU_OPTION);

		system("pause");
		return 0;
	}

	// Loop based on user input
	void Game::GameLoop() {
		char key = NULL;
		
		do {
			instance->player->ReadyPlayerForGame(instance->diceFactory);

			// Run Game
			instance->PlayAGame();

			// Draw Result
			DrawScreen();
			
		} while (CheckContinue());
	}

	// Loop for a set number of iterations
	void Game::AutomatedGameLoop(unsigned int iterations) {
		unsigned int count = 0;

		do {
			instance->player->ReadyPlayerForGame(instance->diceFactory);
			
			// Run Game
			instance->PlayAGame();

			// Draw Result
			DrawScreen();

			++count;
		} while (count < iterations);

	}

	bool Game::CheckContinue() {
		char key = NULL;

		cout << "Do You Want To Continue? (n/N to exit): ";
		cin >> key;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any input other than the first character

		if (key == 'n' || key == 'N') return false;
		return true;
	}

	void Game::PlayAGame() {
		GameResult* newResult = new GameResult();

		instance->player->IncreaseBet(COST_OF_GAME);

		instance->RollForGame(newResult);		
	}

	void Game::GameWin(GameResult* result) {
		instance->player->RecordScore(result->GameWin());
		instance->GameEnd(result);
	}

	void Game::GameLose(GameResult* result) {
		instance->player->RecordScore(result->GameLose());
		instance->GameEnd(result);
	}

	void Game::DrawScreen() {
		system("cls");

		// Draw the screen header
		cout << "  D1\tD2\tD3\tD4\tD5\tD6\tD7\tD8\tD9\tD10\tWin\tTotal\t\tTotal Bet\t# Games\n";
		
		// Draw all game results
		for (int i = 0; i < this->recentResults.Size(); ++i) {
			recentResults.Find(i)->DrawGameResult();
		}

		cout << endl;
	}

	void Game::AddGameResult(GameResult* result) {
		if (this->recentResults.Size() >= MAX_NUM_OF_VISIBLE_GAMES) {
			this->recentResults.Export(0);
		}
		recentResults.Append(result);
	}

	// Record the data and end the game
	void Game::GameEnd(GameResult* result) {
		// Set all the values (total score/bet/games) as of this game iteration
		result->SetToDateValues(instance->player->GetMyTotalScore(), 
								instance->player->GetMyTotalBet(), 
								instance->player->GetMyNumberOfGames());

		instance->AddGameResult(result);
		instance->gameTable->PurgeTableOfDice();
	}

	void Game::RollForGame(GameResult* resultTracking) {
		Die* die = instance->player->GetDieFromBag();

		// Add die to the table
		gameTable->AddDieToTable(die);

		// Get Result
		int result = die->GetDieRoll();

		// Record Die Result
		resultTracking->AddDieResult(result);

		// Check Win Condition
		if (Utility::IsPrimeNumber(resultTracking->GetCurrentGameScore()) == true) {
			instance->GameWin(resultTracking);			
			return;
		}
		else if (instance->player->GetRemainingNumberOfDieInBag() == 0) {
			instance->GameLose(resultTracking);
			return;
		}
		else {
			RollForGame(resultTracking);
		}
	}

	int Game::DisplayMenuOptoins() {
		int iOption = int();

		do {
			char option = char();
			cout << "Options" << endl
				<< "1. Run for " << MENU_OPTION_ONE_ITERATIONS << " iterations" << endl
				<< "2. Run for " << MENU_OPTION_TWO_ITERATIONS << " iterations" << endl
				<< "3. Run for " << MENU_OPTION_THREE_ITERATIONS << " iterations" << endl
				<< "4. Run for " << MENU_OPTION_FOUR_ITERATIONS << " iterations" << endl
				<< "5. Run for " << MENU_OPTION_FIVE_ITERATIONS << " iterations" << endl
				<< "6. Run for Custom Amount of iterations (" << MAX_NUMBER_OF_CUSTOM_ITERATIONS << " MAX)" << endl
				<< "7. Run 1 Game at a time" << endl
				<< "8. Exit Application" << endl;
			cin >> option;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any input other than the first character

			iOption = atoi(&option);
		} while (iOption < 1 || iOption > 8);

		return iOption;
	}

	void Game::ExecuteMenuOption(int option) {
		if (option == QUIT_MENU_OPTION) return;
		instance->menuOptoins[option - 1]();
	}

	void Game::ExecuteCustomCount() {
		// Get Ready for Inpu
		int num = -1;
		char buff[512];
		
		// Get Input
		cout << "Please Enter an amount between 1 and " << MAX_NUMBER_OF_CUSTOM_ITERATIONS << endl;
		cin.getline(buff, 512);
		
		// Change Input to Int
		num = atoi(buff);
		
		// Constrain the data
		if (num <= 0) num = 1;
		if (num > MAX_NUMBER_OF_CUSTOM_ITERATIONS) num = MAX_NUMBER_OF_CUSTOM_ITERATIONS;
		
		// Enter Game Loop
		instance->AutomatedGameLoop((unsigned int)num);
	}

	void Game::ResetGameResults() {
		instance->recentResults.Purge();
	}

	// GameResult Class Definitions
	/////////////////////////////////////////////////	

	void GameResult::AddDieResult(int result) {
		for (int i = 0; i < BAG_MAX_DICE; ++i) {
			if (this->dieRolls[i] != 0) continue;
			else {
				this->dieRolls[i] = result;		// Set result for individual die roll
				*this->scoreTracker += result;	// Increase the total sum of die rolled
				break;
			}
		}
	}

	unsigned int GameResult::GetCurrentGameScore() {
		return *this->scoreTracker;
	}

	void GameResult::DrawGameResult() {
		cout << "  ";		// Spacing to line up with header

		for (int i = 0; i < BAG_MAX_DICE; ++i) {
			if (this->dieRolls[i] == 0) cout << " \t";
			else cout << this->dieRolls[i] << "\t";
		}

		cout << *this->winAmount << "\t"
			 << *this->scoreToDate << "\t\t"
			 << *this->betToDate << "\t\t"
			 << *this->numGamesTracker << "\n";
	}

	unsigned int GameResult::GameWin() {
		*this->winAmount = *this->scoreTracker;
		return *this->winAmount;
	}

	unsigned int GameResult::GameLose() {
		*this->winAmount = 0;
		return 0;
	}

	void GameResult::SetToDateValues(unsigned int score, unsigned int bet, unsigned int ngames) {
		*this->scoreToDate = score;
		*this->betToDate = bet;
		*this->numGamesTracker = ngames;
	}

	// Basic Global Dice Game Function Definitions
	/////////////////////////////////////////////////	

	void RunMenuOptionOne() {
		Game::GetInstance()->AutomatedGameLoop(MENU_OPTION_ONE_ITERATIONS);
	}

	void RunMenuOptionTwo() {
		Game::GetInstance()->AutomatedGameLoop(MENU_OPTION_TWO_ITERATIONS);
	}

	void RunMenuOptionThree() {
		Game::GetInstance()->AutomatedGameLoop(MENU_OPTION_THREE_ITERATIONS);
	}

	void RunMenuOptionFour() {
		Game::GetInstance()->AutomatedGameLoop(MENU_OPTION_FOUR_ITERATIONS);
	}

	void RunMenuOptionFive() {
		Game::GetInstance()->AutomatedGameLoop(MENU_OPTION_FIVE_ITERATIONS);
	}

	void RunMenuOptionSix() {
		Game::GetInstance()->ExecuteCustomCount();
	}

	void RunMenuOptionSeven() {
		Game::GetInstance()->GameLoop();
	}
}