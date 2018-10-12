#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void displayIntro();
string GetGuess();
void printGuess(string);
void playGame();
bool AskToPlayAgain();

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
	cout << "Welcome to Bulls and Cows, a word game!\n";  
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
}

string GetGuess() {
	//get a guess from the player
	string Guess = "";
	cout << "Enter a Guess: ";
	getline(cin, Guess);
	cout << endl;

	//return guess to calling function
	return Guess;
}

//use for printing full feedback eventually
void printGuess(string guess) {
	//display the guess on the console
	cout << "You've entered: ";
	cout << guess << endl;
	return;
}

void playGame() {
	string Guess = "";

	//give user certain number of guesses
	const int NUMBER_OF_GUESSES = 5;

	for (int i = 0; i < NUMBER_OF_GUESSES; i++) {
		Guess = GetGuess();
		printGuess(Guess);
		cout << "Guess Number: " << i + 1 << "\n";
	}

	cout << "OUT OF GUESSES!\n";
}

bool AskToPlayAgain() {
	cout << "Would you like to play again? (y/n)\n";
	while (true) {
		string response = "";
		getline(cin, response);
		cout << endl;
		if ((response[0] == 'y') || (response[0] == 'Y')) {
			return true;
		}
		else if ((response[0] == 'n') || (response[0] == 'N')) {
			return false;
		}
		cout << "please enter (y/n)\n";
	}
}