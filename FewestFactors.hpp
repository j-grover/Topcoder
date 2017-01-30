#include <vector>
#include <climits>
#include <algorithm>
#include <sstream>
#include <cmath>

class FewestFactors
{
public:
    // Calculates fewest factors from set of digits
    // Params: digits - vector with integers
    // Return: minNumber - no. with least factors
    int number(std::vector<int> digits)
    {
        int currNumber;
        int minNumber;
        int currFactor;
        int minFactor = INT_MAX;

        // Sort digits ascending order
        std::sort(digits.begin(), digits.end());

        do {
            int number;
            std::ostringstream oss;
            currFactor = 0;

            for (int i = 0; i < digits.size(); i++) {
                oss << digits[i];
            }
            
            // Store current permutation
            std::istringstream iss(oss.str());
            iss >> number;
            currNumber = number;

            int root = std::sqrt(currNumber);

            // Calculate no. of factors
            for (int j = 1; j <= root; j++) {
                if (currNumber % j == 0) {
                    currFactor += 2;
                }
            }

			// One less factor for squares
            if (root * root == currNumber) {
                currFactor--;
            }

            // Choose smallest no. with same no. of factors
            if (currFactor == minFactor) {
                if (currNumber < minNumber) {
                    minNumber = currNumber;
                    minFactor = currFactor;
                }
            }

            // Choose minimum no. of factors
            if (currFactor < minFactor) {
                minNumber = currNumber;
                minFactor = currFactor;
            }

        } while (std::next_permutation(digits.begin(), digits.end()));

        return minNumber;
    }
};