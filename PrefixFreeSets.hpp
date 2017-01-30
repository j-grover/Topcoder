#include <vector>
#include <string>

class PrefixFreeSets
{
public:
	int maxElements(std::vector<std::string> words)
	{
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size(); j++) {
				// Don't compare string with itself
				if (i != j) {
					// Prefix found
					if (words[j].compare(0, words[i].size(), words[i]) == 0) {
						// Remove string from vector
						words.erase(words.begin() + i);
						i--;
						break;
					}
				}
			}
		}
		return words.size();
	}
};