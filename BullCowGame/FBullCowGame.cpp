#include "FBullCowGame.h"
#include <map>
#include <set>
#include <iostream>
#include <wchar.h>

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

FBullCowGame::FBullCowGame(bool suppress)
{
	//suppresses the output of the game so it doesn't show the hidden word the first time
}

void FBullCowGame::Reset()
{
	const int32 MAX_TRIES = 5;
	//const int32 WORD_LENGTH = 3;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = GetHiddenWord();
	WordLength = GetHiddenWordLength();
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


int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

void FBullCowGame::IncrementTries()
{
	MyCurrentTry++;
	return;
}

bool FBullCowGame::IsGameWon(int32 bullCount) const
{
	return (bullCount == GetHiddenWordLength()) ? true :  false;
}

/*Verifies the guess meets the criteria of the game and gives user feedback if not

	returns: EWordStatus - Status code of guess
*/
EWordStatus FBullCowGame::VerifyGuess(FString guess) const  //returns true if guess is valid, false
{
	if (guess.length() != GetHiddenWordLength()) {  //check if lengths are equal
		std::cout << "Invalid word length! Please enter a word of " << GetHiddenWordLength() << " letters\n\n";
		return EWordStatus::Invalid_Length;
	}

	std::set<char> characterSet = std::set<char>(); 
	for (unsigned int i = 0; i < guess.length(); i++) {
		if (!islower(guess[i])) {
			std::cout << "Input was not all lowercase or contained invalid character\n\n";
			return EWordStatus::Not_Lowercase;
		}
		if (characterSet.find(guess[i]) == characterSet.cend()) { //checks against current set of characters to see if there's a match
			characterSet.insert(guess[i]);
		}
		else {
			std::cout << "Please enter a valid Isogram\n\n";
			return EWordStatus::Not_Isogram;
		}


	}

	//guess.
	return EWordStatus::OK;
}


//receives a valid guess, increments turn and return counts
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	FBullCowCount BCCount = { 0,0 }; //initialize Bulls and Cows to 0
	//MyCurrentTry++; // increment try when a guess is submitted

	int32 hiddenWordLength = WordLength;
	for (int32 i = 0; i < hiddenWordLength; i++) { //loop over hidden word
		for (int32 j=0; j < hiddenWordLength; j++) //loop over guess
			if (MyHiddenWord[i] == Guess[j]) {
				if (i == j) { 
					BCCount.Bulls++;
				}
				else { //increment cows
					BCCount.Cows++;
				}
			}
	}
	return BCCount;
}

void FBullCowGame::SummarizeGame() const
{
	if (GetCurrentTry() == GetMaxTries()) {
		std::cout << "Out of Guesses\n";
		std::cout << "The hidden word was: " << MyHiddenWord << std::endl << std::endl;
	}
	else {
		std::cout << "CONGRATS!!!\n ";
		std::cout << "It took you " << GetCurrentTry() << " guesses to win!\n\n";
	}
}

FString FBullCowGame::GetHiddenWord()
{
	std::cout << "Hello! Please enter a word for the other player to guess: ";
	FString hiddenWord = "";
	//std::getline(std::cin, hiddenWord);
	hiddenWord = MaskInput();
	std::cout << std::endl;
	while (VerifyHiddenWord(hiddenWord) != EWordStatus::OK) { //makes sure hidden word is valid for gameplay
		std::cout << "Please enter a valid hidden word: ";
		hiddenWord = MaskInput();
		std::cout << std::endl;
		
	}
	return hiddenWord;
}

FString FBullCowGame::MaskInput() {
	FString retString = "";
	char c = 0;
	while ((c=_getwch()) != '\r') {
		retString.push_back(c);
		_putwch('*');
	}

	return retString;

}

EWordStatus FBullCowGame::VerifyHiddenWord(FString hiddenWord)
{
	const int MIN_WORD_LENGTH = 3;
	if (hiddenWord.length() < MIN_WORD_LENGTH) {  //check if lengths are equal
		std::cout << "Invalid word length! Please enter a word of at least " << MIN_WORD_LENGTH << " letters\n\n";
		return EWordStatus::Invalid_Length;
	}

	std::set<char> characterSet = std::set<char>();
	for (unsigned int i = 0; i < hiddenWord.length(); i++) {
		if (!islower(hiddenWord[i])) {
			std::cout << "Input was not all lowercase or contained invalid character\n\n";
			return EWordStatus::Not_Lowercase;
		}
		if (characterSet.find(hiddenWord[i]) == characterSet.cend()) { //checks against current set of characters to see if there's a match
			characterSet.insert(hiddenWord[i]);
		}
		else {
			std::cout << "Please enter a valid Isogram\n\n";
			return EWordStatus::Not_Isogram;
		}


	}

	//guess.
	return EWordStatus::OK;
}


