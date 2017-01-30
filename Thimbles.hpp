#include <vector>
#include <string>

class Thimbles
{
public:
	int thimbleWithBall(std::vector<std::string> swaps)
	{
		// Ball starts underneath first thimble
		char position = '1';
		for (int i = 0; i < swaps.size(); i++) {
			// Ball is now underneath thimble Y (swap X-Y)
			if (position == swaps[i][0]) {
				position = swaps[i][2];
			}
			// Ball is now underneath thimble X (swap X-Y)
			else if (position == swaps[i][2]) {
				position = swaps[i][0];
			}
		}
		return position - '0';
	}
};