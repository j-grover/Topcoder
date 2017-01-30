#include <string>
#include <algorithm>

class Arrows
{
public:
    // Calculates length of longest arrow in string
    // Params: s - string with <, >, -, =
    // Return: maxLength - no. of elements of longest arrow, -1 if invalid
    int longestArrow(std::string s)
    {
        int currLength = -1;
        int maxLength = -1;
        int flag = -1;

        for (int i = 0; i < s.size(); i++) {
            currLength = -1;

            // Set variables for specific arrow
            if (s[i] == '<') {
                flag = 0;
                currLength = 1;
            }
            else if (s[i] == '>') {
                flag = 1;
                currLength = 1;
            }

            // < arrow, check elements to right
            if (flag == 0) {
                for (int j = i + 1; j < s.size(); j++) {
                    // Check for end of arrow, change of tail to right
                    if (s[j] == '<' || s[j] == '>' || s[j] != s[i + 1]) {
                        break;
                    }
                    currLength++;
                }
            }
            // > arrow, check elements to left
            else if (flag == 1) {
                for (int k = i - 1; k >= 0; k--) {
                    // Check for end of arrow, change of tail to left
                    if (s[k] == '<' || s[k] == '>' || s[k] != s[i - 1]) {
                        break;
                    }
                    currLength++;
                }
            }
            // Update maxLength
            maxLength = std::max(currLength, maxLength);
            flag = -1;
        }
        return maxLength;
    }
};