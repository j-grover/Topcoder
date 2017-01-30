#include <string>
#include <algorithm>

class BlackAndWhiteSolitaire
{
public:
	// Returns minimum no. of cards to be flipped
	// Params: cardFront - string with current sequence
	// Return: min of the two counts for black start and white start
	int minimumTurns(std::string cardFront)
	{
		std::string blackStart; // Start with black side up
		std::string whiteStart; // Start with white side up

		int blackStartCount = 0;    // Flip count for black first  
		int whiteStartCount = 0;    // Flip count for white first

		for (int i = 0; i < cardFront.size(); i++) {

			// Populate strings with alternating sequence with
			// different starting sides
			if (i % 2 == 0) {
				blackStart += "B";
				whiteStart += "W";
			}
			else {
				blackStart += "W";
				whiteStart += "B";
			}

			// Count for black starting sequence
			if (cardFront[i] != blackStart[i]) {
				blackStartCount++;
			}

			// Count for white starting sequence
			if (cardFront[i] != whiteStart[i]) {
				whiteStartCount++;
			}
		}

		// Return the minimum out of the two counts
		return std::min(blackStartCount, whiteStartCount);
	}
};