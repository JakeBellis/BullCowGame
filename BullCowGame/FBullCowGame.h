#pragma once
#include <string>

class FBullCowGame {

public:
	FBullCowGame();
	void Reset(); //TODO make a more rich return return value
	int GetMaxTries();
	int GetCurrentTry();
	void IncrementTries();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
	int * GetBullsAndCows(std::string);
	


private:
	int MyCurrentTry;
	int MyMaxTries;
	
};