#include "io.h"

/**
 * Ignores rest of input.
 * 
 */
void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * Resets and clear cin stream.
 * 
 */
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
int readInt(int rangeStart, int rangeEnd) {
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
