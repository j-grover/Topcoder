#include <climits>
#include <cstdlib>

class MinimalDifference
{
public:
	int sum(int number)
	{
		int sum = 0;
		while (number > 0) {
			// Add ones digit to sum
			sum += number % 10;
			// Shift decimal left one place
			number /= 10;
		}
		return sum;
	}

	int findNumber(int A, int B, int C)
	{
		int sum_C = sum(C);
		int min_diff = INT_MAX;
		int curr_diff = 0;
		int X = 0;

		for (int i = A; i <= B; i++) {
			// Absolute difference between digit sum of i and C
			curr_diff = std::abs(sum(i) - sum_C);
			
			// New minimum difference found
			if (curr_diff < min_diff) {
				// Set new minimum difference
				min_diff = curr_diff;
				// Set current number as return value
				X = i;
			}
		}
		return X;
	}
};