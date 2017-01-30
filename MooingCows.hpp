#include <vector>
#include <string>
#include <climits>
using namespace std;

class MooingCows
{
public:
    // Calculates minmum total dissatisfaction
    // Params: farmland - vector with elements denoting squares
    // Return: minDiss - minimum sum of dissatisfaction of each cow
    int dissatisfaction(vector<string> farmland)
    {
        int rows = farmland.size();
        int cols = farmland[0].size();
        int currDiss = 0;
        int minDiss = INT_MAX;

        // For each cow in farmland
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                // Calculate dissatisfaction when cow at (x, y) moos
                if (farmland[x][y] == 'C') {
                    currDiss = 0;
                    // For all other cows in farmland
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            // Add dissatisfaction of cow at (i, j)
                            if (farmland[i][j] == 'C') {
                                currDiss += (x - i)*(x - i) + (y - j)*(y - j);
                            }
                        }
                    }
                    // Update minDiss if currDiss is minimum so far
                    if (currDiss < minDiss) {
                        minDiss = currDiss;
                    }
                }
            }
        }
        return minDiss;
    }
};