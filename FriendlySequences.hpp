#include <vector>
#include <string>
#include <sstream>

class FriendlySequences
{
public:
    // Returns number of different friendly contiguous subsequences 
    // Params: array - int vector with numbers
    // Return: count - no. of sequences
    int count(std::vector<int> array)
    {
        std::vector<std::string> digits;

        // Only one number in vector
        if (array.size() == 1) {
            return 0;
        }

        // Create new string vector from array
        for (int i = 0; i < array.size(); i++) {
            std::ostringstream ss;
            ss << array[i];
            digits.push_back(ss.str());
        }

        int count = 0;
        bool flag;

        // For elements in sequence
        for (int j = 0; j < digits.size(); j++) {
            
            flag = true;

            // For elements in sequence minus current element
            for (int k = j + 1; k < digits.size() && flag; k++) {
                
                // Compare digits in current with next
                for (int l = 0; l < digits[j].size(); l++) {
                    // Numbers aren't friendly
                    if (!(digits[k].find(digits[j][l]) != std::string::npos)) {
                        flag = false;
                        break;
                    }
                }

                // Compare digits in next with current
                for (int m = 0; m < digits[k].size(); m++) {
                    // Numbers aren't friendly
                    if (!(digits[j].find(digits[k][m]) != std::string::npos)) {
                        flag = false;
                        break;
                    }
                }

                if (!flag) {
                    break;
                }
                count++;
            }
        }
        return count;
    }
};