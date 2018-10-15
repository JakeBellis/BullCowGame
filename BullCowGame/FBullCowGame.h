#pragma once
#include <string>

class FBullCowGame {

public:
	void Reset(); //TODO make a more rich return return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
	int * GetBullsAndCows(std::string);
	


private:
	int CurrentTry;
	int MaxTries;
	
};