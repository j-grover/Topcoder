#include <vector>
#include <string>
#include <climits>
#include <algorithm>

class HouseBuilding
{
public:
	int getMinimum(std::vector<std::string> area)
	{
		int minEffort = INT_MAX;
		int effort = 0;

		// For height 0 to 9
		for (int i = 0; i < 9; i++) {
			// For each row
			for (int j = 0; j < (int)area.size(); j++) {
				// For each element in row
				for (int k = 0; k < (int)area[0].size(); k++) {
					// Sum minimum of 0 units away and 1 unit away
					effort += std::min(abs(i - area[j][k] + '0'), abs(i - area[j][k] + '0' + 1));
				}
			}

			// Update minimum 
			minEffort = std::min(minEffort, effort);
			effort = 0;
		}
		return minEffort;
	}
};