#include <vector>
#include <climits>
#include <algorithm>

class ProblemsToSolve
{
public:
	int minNumber(std::vector<int> pleasantness, int variety)
	{
		int problems = INT_MAX;

		// For all pairs of problems
		for (int i = 0; i < pleasantness.size(); i++) {
			for (int j = i + 1; j < pleasantness.size(); j++) {

				// Difference between problems is greater than variety
				if (abs(pleasantness[j] - pleasantness[i]) >= variety) {
					// Minimum of previous and current no. of problems required
					problems = std::min(problems, 1 + (i + 1) / 2 + (j - i + 1) / 2);
				}
			}
		}
		// Minimum of problems and size of pleasantness
		return std::min(problems, (int)pleasantness.size());
	}
};