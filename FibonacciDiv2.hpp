#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class FibonacciDiv2
{
public:
    // Calculates no. of inc/dec required to make no. a fibonacci no.
    // Params: N - integer to be changed
    // Return: minSteps - minimum no. of steps required
    int find(int N)
    {
        vector<int> Fib;
        Fib.push_back(0);   // Fib[0] = 0
        Fib.push_back(1);   // Fib[1] = 1

        // Fill fibonacci values for i >= 2
        for (int i = 2; i < 32; i++) {
            Fib.push_back(Fib[i - 1] + Fib[i - 2]);
        }

        int currSteps = 0;
        int minSteps = INT_MAX;

        // Compute minimum no. of steps required
        for (int j = 0; j < Fib.size(); j++) {
            currSteps = abs(Fib[j] - N);
            if (currSteps < minSteps) {
                minSteps = currSteps;
            }
        }
        return minSteps;
    }
};
