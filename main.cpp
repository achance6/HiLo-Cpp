#include <iostream>
#include <random>
#include <chrono>
#include <ctype.h>

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cinClear() {
	std::cin.clear();
	ignoreLine();
}

/**
 * Reads an integer from user input within given range with error handling.
 * Range defaults to 1 (inclusive) to 101 (exclusive)
 * 
 * @param rangeStart Start of range of valid ints inclusive. Default 1.
 * @param rangeEnd End of range of valid ints exclusive. Default 101.
 * @return integer read from input
 */
int readInt(int rangeStart = 1, int rangeEnd = 101) {
	using std::cin, std::cout;

	int in{};

	while (true) {
		cin >> in;
		// Remove extraneous input from buffer
		ignoreLine();

		if (!cin) {
			if (cin.eof()) exit(0); // prevents loop on closing input stream

			cout << "Bad input. Try again: ";
			cinClear();
			continue; // in not extracted properly
		}

		if (in >= rangeStart && in < rangeEnd) break;

		else cout << "Invalid guess. Enter a number from " << rangeStart << 
			" to " << rangeEnd - 1 << ": ";
	}

	return in;
}

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

	// Using system clock to seed prng
	std::mt19937 mt{ 
		static_cast<std::mt19937::result_type>
		(std::chrono::steady_clock::now().time_since_epoch().count())
	};
	std::uniform_int_distribution<> tRange{ 1, 100 }; // 1 <= target <= 100

	char in{ 'Y' };
	while (in == 'Y') {
		playHiLo(tRange(mt));

		do {
			cout << "Play again? [Y/N]: ";
			cin >> in;
			in = static_cast<char>(std::toupper(in));
		} while (in != 'Y' && in != 'N');
	}
	
	return 0;
}