#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	OK,
	Not_Isogram,
	Invalid_Length,
	Not_Lowercase

};

class FBullCowGame {

public:
	FBullCowGame();
	FBullCowGame(bool);
	void Reset(); 
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	void IncrementTries();
	bool IsGameWon(int32) const;
	EWordStatus VerifyGuess(FString) const;
	//TODO provide a method for counting bulls and cows and increasing turn number
	FBullCowCount SubmitGuess(FString);
	void SummarizeGame() const;
	


private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	int32 WordLength;
	FString MyHiddenWord;
	FString GetHiddenWord();
	EWordStatus VerifyHiddenWord(FString);
	FString MaskInput();
};