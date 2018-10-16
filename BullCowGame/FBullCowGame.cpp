#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	MyCurrentTry = 0;
	MyMaxTries = 5;

}

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetMaxTries()
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry()
{
	return MyCurrentTry;
}

void FBullCowGame::IncrementTries()
{
	MyCurrentTry++;
	return;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

int * FBullCowGame::GetBullsAndCows(std::string)
{
	return nullptr;
}
