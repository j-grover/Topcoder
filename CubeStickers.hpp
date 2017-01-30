#include <vector>
#include <string>
#include <map>

class CubeStickers
{
public:
	std::string isPossible(std::vector<std::string> sticker)
	{
		std::map<std::string, int> colors;
		std::map<std::string, int>::iterator it;

		// Store stickers and values in map
		for (int i = 0; i < sticker.size(); i++) {
			if ((it = colors.find(sticker[i])) != colors.end()) {
				(it->second)++;
			}
			else {
				colors.insert(std::pair<std::string, int>(sticker[i], 1));
			}
		}

		int single = 0;
		int pair = 0;

		// Run through map
		for (it = colors.begin(); it != colors.end(); ++it) {
			// One sticker of this type
			if (it->second == 1) {
				single++;
			}
			// More than one sticker of this type
			else {
				pair++;
			}
		}

		// Single or pairs of stickers can be used
		if ((single + 2 * pair) >= 6) {
			return "YES";
		}
		return "NO";
	}
};