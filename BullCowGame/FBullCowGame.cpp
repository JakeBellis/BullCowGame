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
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
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

void FBullCowGame::IncrementTries()
{
	MyCurrentTry++;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
//receives a valid guess, increments turn and return counts
BullCowCount FBullCowGame::SubmitGuess(std::string) const
{
	return BullCowCount();
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

int32 * FBullCowGame::GetBullsAndCows(FString) const
{
	return nullptr;
}
