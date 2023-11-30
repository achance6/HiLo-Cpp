#include <iostream>
#include <random>
#include <chrono>
#include <ctype.h>
#include "io.h"
#include "Random.h"

/**
 * Plays game of HiLo at console.
 * 
 * @param target Target number
 * @param maxGuesses Max guesses allowed of user. Default 7.
 */
void playHiLo(int target, int maxGuesses = 7) {
	using std::cin, std::cout;

	cout << "Let's play a game. I'm thinking of a number between 1 and 100." << 
		" You have " << maxGuesses << " tries to guess what it is." << '\n';
	int guess{};

	for (int i{ 0 }; i < maxGuesses; ++i) {

		cout << "Guess #" << i + 1 << ": ";
		guess = readInt();

		if (guess == target || i == maxGuesses - 1) break;

		cout << "Your guess is ";
		if (guess < target) {
			cout << "too low!" << '\n';
		}
		else {
			cout << "too high!" << '\n';
		}
	}

	cout << (guess == target ? "Correct! You win!" : "Sorry, you lose!") << '\n';
	cout << "The number was: " << target << '\n';
}

int main() {
	using std::cin, std::cout;

	char in{ 'Y' };
	while (in == 'Y') {
		playHiLo(Random::get(1, 100));

		do {
			cout << "Play again? [Y/N]: ";
			cin >> in;
			in = static_cast<char>(std::toupper(in));
		} while (in != 'Y' && in != 'N');
	}
	
	return 0;
}