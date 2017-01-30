#include <string>
#include <climits>
#include <algorithm>

class DifferentStrings
{
public:
	int minimize(std::string A, std::string B)
	{
		int currentDifference;
		int minDifference = INT_MAX;
		int lengthDifference = B.size() - A.size();

		// Check difference for all possiblities of inserting
		// characters at front or end of string
		for (int i = 0; i <= lengthDifference; i++) {
			currentDifference = 0;
			for (int j = 0; j < A.size(); j++) {
				if (A[j] != B[i + j]) {
					currentDifference++;
				}
			}
			// Update minimum if required
			minDifference = std::min(currentDifference, minDifference);
		}

		return minDifference;
	}
};