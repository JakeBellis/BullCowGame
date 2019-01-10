#pragma once
#include <string>

using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};
class FBullCowGame {

public:
	FBullCowGame();
	void Reset(); 
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	void IncrementTries();
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);
	//TODO provide a method for counting bulls and cows and increasing turn number
	BullCowCount SubmitGuess(std::string) const;
	


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	
};