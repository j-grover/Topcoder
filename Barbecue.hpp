#include <vector>

class Barbecue
{
public:
	int eliminate(int n, std::vector<int> voter, std::vector<int> excluded)
	{
		std::vector<int> votes;
		for (int i = 0; i < n; i++) {
			votes.push_back(0); 
		}

		for (int i = 0; i < voter.size() ; i++) {
			// Add voter count
			votes[voter[i]]++; 
			// Exclusion count is arbitrarly chosen to be larger
			votes[excluded[i]] += 50;
		}
		
		// Initially person 0 is to be excluded
		int maxVotes = votes[0];
		int exlcudedIndex = 0; 
		
		for (int i = 0; i < n; i++) {
			// New max votes is found
			if(votes[i] > maxVotes) { 
				maxVotes = votes[i]; 
				exlcudedIndex = i; 
			}
		}
		return exlcudedIndex; 
	}
};