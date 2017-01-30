#include <vector>
#include <algorithm>

class CircularLine
{
public:
	int longestTravel(std::vector<int> t)
	{
		int timeA;
		int timeB;
		int minTime;
		int maxTime = 0;

		// Calculate distance between every pair of stations i and j
		for (int i = 0; i < t.size(); i++) {	
			for (int j = i + 1; j < t.size(); j++) {

				timeA = 0;
				timeB = 0;

				// Time from station i to station j
				for (int k = i; k < j; k++) {
					timeA += t[k];
				}

				// Time from station j to station n-1
				for (int l = j; l < t.size(); l++) {
					timeB += t[l];
				}

				// Time from station 0 to station i
				for (int m = 0; m < i; m++) {
					timeB += t[m];
				}

				// Fastest travel time between two stations
				minTime = std::min(timeA, timeB);
				// Fastest maximal travel time
				maxTime = std::max(maxTime, minTime);
			}
		}

		return maxTime;
	}
};