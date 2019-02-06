#include "FBullCowGame.h"
#include <map>
#include <iostream>

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

bool FBullCowGame::IsGuessValid(FString guess)  //returns true if guess is valid, false otherwise
{
	if (guess.length() != MyHiddenWord.length()) {  //check if lengths are equal
		std::cout << "INVALID WORD LENGTH! Please enter a word of " << MyHiddenWord.length() << " letters\n";
		return false;
	}

	//guess.
	return true;
}


//receives a valid guess, increments turn and return counts
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	FBullCowCount BCCount = { 0,0 }; //initialize Bulls and Cows to 0
	//MyCurrentTry++; // increment try when a guess is submitted

	int32 hiddenWordLength = WordLength;
	for (int32 i = 0; i < hiddenWordLength; i++) { //loop over hidden word
		for (int32 j=0; j < hiddenWordLength; j++) //loop over guess
			if (MyHiddenWord[i] == guess[j]) {
				if (i == j) {
					BCCount.Bulls++;
				}
				else {
					BCCount.Cows++;
				}
			}
	}
	return BCCount;
}


