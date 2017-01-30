#include <vector>
#include <algorithm>

class CellRemoval
{
public:
	void remove(std::vector<int> &parent, int index) 
	{
		// Remove index cell and its descendants 
		for (int i = 0; i < parent.size(); i++) {
			if (parent[i] == index) {
				parent[i] = -2;
				remove(parent, i);
			}
		}
	}

	int cellsLeft(std::vector<int> parent, int deletedCell)
	{
		// Set deletedCell to "removed"
		parent[deletedCell] = -2;
		
		// Recursive call to set all descendants of deletedCell to "removed"
		remove(parent, deletedCell);

		int cellCount = 0;
		// Count cells left in mature organism
		for (int i = 0; i < parent.size(); i++) {
			// Cell is not the root and hasn't been removed
			if (parent[i] != -1 && parent[i] != -2) {
				// Cell does not have any descendants 
				if (!(std::find(parent.begin(), parent.end(), i) != parent.end())) {
					cellCount++;
				}				
			}
		}
		return cellCount;
	}
};
