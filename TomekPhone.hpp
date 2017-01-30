#include <vector>
#include <map>
#include <algorithm>

class TomekPhone
{
public:
	// Returns minimum number of keystrokes
	// Params: frequencies - int vector, keySizes - int vector
	// Return: keyStrokes - min no, -1 if not possible
	int minKeystrokes(std::vector<int> frequencies, std::vector<int> keySizes)
	{
		std::multimap<int, int> key_map;
		std::multimap<int, int>::iterator it;
		std::vector<int>::iterator max;
		int keyStrokes = 0;
		int count = 0;
		int currKey;

		// Sum up no. of keys available
		for (int i = 0; i < keySizes.size(); i++) {
			count += keySizes[i];
		}
		
		// Not enough room on keys
		if (frequencies.size() > count) {
			return -1;
		}

		// Insert (1, no. of letters) into multimap
		for (int k = 0; k < keySizes.size(); k++) {
			key_map.insert(std::pair<int, int> (1, keySizes[k]));
		}

		for (int j = 0; j < frequencies.size(); j++) {
			// Get smallest key (always 1st one)
			it = key_map.begin();
			currKey = (*it).first;

			// Get key with max frequency
			max = std::max_element(frequencies.begin(), frequencies.end());
			// Sum no. of keystrokes required for current key
			keyStrokes += (*max) * currKey;
			*max = -1;

			// Check if all letters on the current key are filled
			if (!(currKey + 1 > (*it).second)) {
				// Add new pair with incremented key
				key_map.insert(std::pair<int, int> (currKey + 1, (*it).second));
			}
			// Remove old pair
			key_map.erase(it);
		}
		return keyStrokes;
	}
};