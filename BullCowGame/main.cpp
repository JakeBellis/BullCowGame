#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void displayIntro();

string GetGuess();

int main() {
	displayIntro();

	string Guess = "";
	Guess = GetGuess();


	char holdChar = getchar();
	return 420;


}

void displayIntro() {
	const int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a word game!\n";  //introduce the game
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
}

string GetGuess() {
	//get a guess from the player
	string Guess = "";
	cout << "Enter a Guess: ";
	getline(cin, Guess);
	cout << endl;

	//repeat the guess back from them
	cout << "You've entered: ";
	cout << Guess << endl;

	//return guess to calling function
	return Guess;
}