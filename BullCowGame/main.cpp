#include <iostream>
#include <string>
#include <cstdio>
#include "FBullCowGame.h"

void displayIntro();
std::string GetGuess();
void printGuess(std::string);
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
	const int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a word game!\n";  
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
}

std::string GetGuess() {
	//get a guess from the player
	std::string Guess = "";
	std::cout << "Enter a Guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;

	//return guess to calling function
	return Guess;
}

//use for printing full feedback eventually
void printGuess(std::string guess) {
	//display the guess on the console
	std::cout << "You've entered: ";
	std::cout << guess << std::endl;
	return;
}

void playGame() {

	FBullCowGame BCGame = FBullCowGame();
	std::string Guess = "";

	//give user certain number of guesses
	const int NUMBER_OF_GUESSES = BCGame.GetMaxTries();

	for (int i = 0; i < NUMBER_OF_GUESSES; i++) {
		Guess = GetGuess();
		printGuess(Guess);
		BCGame.IncrementTries();
		std::cout << "Guess Number: " << BCGame.GetCurrentTry() << "\n";
	}

	std::cout << "OUT OF GUESSES!\n";
}

bool AskToPlayAgain() {
	std::cout << "Would you like to play again? (y/n)\n";
	while (true) {
		std::string response = "";
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