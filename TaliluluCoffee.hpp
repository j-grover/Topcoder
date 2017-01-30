#include <vector>
#include <string>
#include <algorithm>

class TaliluluCoffee
{
public:
	int maxTip(std::vector<int> tips)
	{
		int sum = 0;
		int tip = 0;

		// Sort in descending order
		std::sort(tips.begin(), tips.end(), std::greater<int>());

		for (int i = 0; i < tips.size(); i++) {
			// Calculate customer tip
			tip = tips[i] - i;
			// Tip must be positive
			if (tip > 0) {
				sum += tip;
			}
		}
		return sum;
	}
};