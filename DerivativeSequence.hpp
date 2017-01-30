#include <vector>
using namespace std;

class DerivativeSequence
{
public:
    // Calculates order n difference sequence
    // Params: a - vector with K integers, n - no. of times difference to be applied
    // Return: a - updated vector of order n of a
    vector<int> derSeq(vector<int> a, int n)
    {
        // Perform difference calculation n times
        for (int i = 0; i < n; i++) {
            vector<int> sequence;
            // Difference sequence has one less element than original
            for (int j = 0; j < a.size()-1; j++) {
                // Push difference between adjacent elements onto vector
                sequence.push_back(a[j+1] - a[j]);
            }
            // Set new a and clear sequence for next use
            a = sequence;
            sequence.clear();
        }
        return a;
    }
};