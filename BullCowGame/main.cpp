#include <iostream>
#include <string>

using namespace std;

int main() {
	const int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a word game!\n";  //introduce the game
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	return 0;

	//get a guess from the player
	string Guess = "";
	cin >> Guess;
	cout << endl;

	//repeat the guess back from them
	cout << "You've entered: ";
	cout << Guess << endl;
	return 0xAA;
}