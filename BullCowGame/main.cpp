/* This is the console executable that uses the FBullCowGame Class
This is the view and user input screen.  For game logic see FBullCowGame.cpp
*/

#include <iostream>
#include <string>
#include <cstdio>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void displayIntro();
FText GetGuess();
void printGuess(FText);
void playGame();
bool AskToPlayAgain();

FBullCowGame BCGame = FBullCowGame();

int main() {
	bool wantToPlay = true; //play the game the first time

	displayIntro();

	while (wantToPlay == true) {
		playGame();
		wantToPlay = AskToPlayAgain();
	}

	return 0;

}

void displayIntro() {
	//introduce the game
	const int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a word game!\n";  
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
}

FText GetGuess() {
	//get a guess from the player
	FText Guess = "";
	std::cout << "Enter a Guess: ";
	std::getline(std::cin, Guess);
	

	//return guess to calling function
	return Guess;
}

//use for printing full feedback eventually
void printGuess(FText guess) {
	//display the guess on the console
	std::cout << "You've entered: ";
	std::cout << guess << std::endl;
	std::cout << std::endl;

	//TODO provide feedback about the users guess
	return;
}

void playGame() {

	FBullCowGame BCGame = FBullCowGame();
	FText Guess = "";

	//give user certain number of guesses
	const int32 NUMBER_OF_GUESSES = BCGame.GetMaxTries();

	for (int32 i = 0; i < NUMBER_OF_GUESSES; i++) {
		std::cout << "Guess Number: " << BCGame.GetCurrentTry() << std::endl;
		Guess = GetGuess();
		//TODO check validity of guess
		//submit guess 
		//TODO print number of bulls and cows
		printGuess(Guess);
		BCGame.IncrementTries();
	}

	std::cout << "OUT OF GUESSES!\n";
	//TODO Summarize game
}

bool AskToPlayAgain() {
	std::cout << "Would you like to play again? (y/n)\n";
	while (true) {
		FText response = "";
		std:: getline(std::cin, response);
		std::cout << std::endl;
		if ((response[0] == 'y') || (response[0] == 'Y')) {
			return true;
		}
		else if ((response[0] == 'n') || (response[0] == 'N')) {
			return false;
		}
		std::cout << "please enter (y/n)\n";
	}
}