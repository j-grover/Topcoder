#include <string>
#include <climits>
#include <algorithm>

class FoxAndMountainEasy
{
public:
	std::string possible(int n, int h0, int hn, std::string history)
	{
		int diff = 0;
		int minHeight = INT_MAX;

		for (int i = 0; i < history.size(); i++) {
			// Calcualte net change in history sequence
			if (history[i] == 'U') {
				diff++;
			}
			else {
				diff--;
			}
			// Minimum height of history sequence
			minHeight = std::min(minHeight, diff);
		}
		
		// Invert minimum height for later use
		minHeight *= -1;

		for (int i = 0; i <= (n - history.size()); i++) {
			// Check if sequence constraints are satisfied
			if ((h0 + i >= minHeight) && (h0 + i + diff - (n - i - history.size()) == hn)) {
				return "YES";
			}
		}
		
		return "NO";
	}
};