#include <vector>
#include <climits>
#include <algorithm>

class TimeTravellingCellar
{
public:
    // Returns maximum profit possible
    // Params: profit - vector with profit values, decay - vector with loss values
    // Return: maxProfit - difference in profit and decay
    int determineProfit(std::vector<int> profit, std::vector<int> decay)
    {
        int maxProfit = INT_MIN;
        int currProfit = 0;

        for (int i = 0; i < profit.size(); i++) {
            for (int j = 0; j < decay.size(); j++) {
                // Cellar cannot be used more than once
                if (i != j) {
                    currProfit = profit[i] - decay[j];
                }
                // Update maximum profit
                maxProfit = std::max(currProfit, maxProfit);
            }
        }
        return maxProfit;
    }
};