#include "FBullCowGame.h"


using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	const int32 MAX_TRIES = 8;
	const int32 WORD_LENGTH = 6;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	WordLength = WORD_LENGTH;
	MyHiddenWord = "planet";
	return;
}

void FBullCowGame::Reset(int32 inputLength)
{
	const int32 MAX_TRIES = 8;
	const int32 WORD_LENGTH = inputLength;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	WordLength = WORD_LENGTH;
	MyHiddenWord = "planet";
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetWordLength() const
{
	return WordLength;
}

void FBullCowGame::IncrementTries()
{
	MyCurrentTry++;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}


//receives a valid guess, increments turn and return counts
FBullCowCount FBullCowGame::SubmitGuess(FString)
{

	MyCurrentTry++; 

	int32 hiddenWordLength = WordLength;
	for (int32 i = 0; i < hiddenWordLength; i++) {
		//hello
	}
	return FBullCowCount();
}


