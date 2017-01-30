#include <vector>
#include <algorithm>
#include <map>

class ColorfulRabbits
{
public:
	int getMinimum(std::vector<int> replies)
	{
		std::multimap<int, int> rabbits;
		std::sort(replies.begin(), replies.end());
		int frequency = 0;
		int numRabbits = 0;

		// Store replies frequencies in map
		for (int i = 0; i < replies.size(); i++) {
			frequency = std::count(replies.begin(), replies.end(), replies[i]);
			rabbits.insert(std::pair<int, int> (frequency, replies[i] + 1));
			i += frequency - 1;
		}

		std::multimap<int, int>::iterator it;
		int value = 0;

		// Iterate over map contents
		for (it = rabbits.begin(); it != rabbits.end(); it++) {
			// Rabbits have same color
			if ((it -> first) <= (it -> second)) {
				numRabbits += (it -> second);
			}
			// Rabbits have different color
			else {
				value = it -> second;
				while ((it -> second) < (it -> first)) {
					(it -> second) += value;
				}
				numRabbits += (it -> second);
			}
		}
		return numRabbits;
	}
};