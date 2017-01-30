#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ChangingString
{
public:
    // Calculates minimum possible distance between A and B
    // Params: A, B - strings with lowercase letters, K - characters to change
    // Return: minDistance - minimum possible distance after K changes
    int distance(string A, string B, int K)
    {
        vector<int> distance;
        int minDistance = 0;

        // Calculate and store distances for each pair of characters
        for (int i = 0; i < A.size(); i++) {
            distance.push_back(abs(int(A[i]) - int(B[i])));
        }

        // Sort array in descending order 
        sort(distance.begin(), distance.end(), greater<int>());

        // Change K distances 
        for (int j = 0; j < K; j++) {
            if (distance[j] == 0) {
                distance[j] = 1;
            }
            else {
                distance[j] = 0;
            }
        }
        
        // Sum up all distances
        for (int k = 0; k < distance.size(); k++) {
            minDistance += distance[k];
        }
        return minDistance;
    }
};