#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:
	FBullCowGame();
	void Reset(); 
	void Reset(int32); //sets the word length
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;
	void IncrementTries();
	bool IsGameWon() const;
	bool IsGuessValid(FString);
	//TODO provide a method for counting bulls and cows and increasing turn number
	FBullCowCount SubmitGuess(FString);
	


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	int32 WordLength;
	FString MyHiddenWord;
};