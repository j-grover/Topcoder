#include <string>
#include <algorithm>

class BridgeSort
{
public:
	bool comparison(std::string a, std::string b)
	{
		std::string suit = "CDHS";
		std::string value = "23456789TJQKA";

		// If suits are different, return a < b
		if (suit.find_first_of(a[0]) != suit.find_first_of(b[0])) {
			return suit.find_first_of(a[0]) < suit.find_first_of(b[0]);
		}

		// Suits are same, compare values and return
		return value.find_first_of(a[1]) <= value.find_first_of(b[1]);
	}

	std::string sortedHand(std::string hand)
	{
		std::string a;
		std::string b;

		// Selection sort to sort cards
		for (int j = 0; j < hand.size() - 1; j += 2) {
			
			int iMin = j;

			// Advance position by 2 through string each time
			for (int i = j + 2; i < hand.size(); i += 2) {
				a = hand.substr(i, 2);
				b = hand.substr(iMin, 2);

				// If card is less, it is new minimum
				if (comparison(a, b)) {
					iMin = i;
				}
			}

			// If not same card, swap cards
			if (iMin != j) {
				a = hand.substr(j, 2);
				b = hand.substr(iMin, 2);

				hand.replace(iMin, 2, a);
				hand.replace(j, 2, b);
			}
			std::cout << hand << std::endl;
		}

		return hand;
	}
};