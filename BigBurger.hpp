#include <vector>
#include <algorithm>

class BigBurger
{
public:
	int maxWait(std::vector<int> arrival, std::vector<int> service)
	{
		// First customer does not need to wait
		if (arrival.size() == 1) {
			return 0;
		}

		int maxTime = 0;
		int timeSpent = 0;

		// Time at which first customer leaves
		int currentTime = arrival[0] + service[0];

		for (int i = 1; i < arrival.size(); i++) {
			// Customer arrives when there are no waiting customers
			if (arrival[i] - currentTime > 0) {
				currentTime += (arrival[i] - currentTime);
			}
			timeSpent = currentTime - arrival[i];
			maxTime = std::max(timeSpent, maxTime);
			currentTime += service[i];
		}

		return maxTime;
	}
};