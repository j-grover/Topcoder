#include <vector>
#include <string>
#include <algorithm>

class CastleGuards
{
public:
	int missing(std::vector<std::string> castle)
	{
		int emptyColumns = 0;
		int emptyRows = 0;
		bool noGuards;

		// Calcualte no. of columns with no guards
		for (int i = 0; i < castle[0].size(); i++) {
			noGuards = true;
			for (int j = 0; j < castle.size(); j++) {
				if (castle[j][i] == 'X') {
					noGuards = false;
				}
			}
			// No guards in column
			if (noGuards) {
				emptyColumns++;
			}
		}

		// Calcualte no. of rows with no guards
		for (int i = 0; i < castle.size(); i++) {
			noGuards = true;
			for (int j = 0; j < castle[0].size(); j++) {
				if (castle[i][j] == 'X') {
					noGuards = false;
				}
			}
			// No guards in row
			if (noGuards) {
				emptyRows++;
			}
		}

		return std::max(emptyColumns, emptyRows);
	}
};
