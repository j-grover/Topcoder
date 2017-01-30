#include <string>
#include <algorithm>

class MagicSpell
{
public:
    // Decrypts string by swapping order of 'A' and 'Z'
    // Params: spell - encrypted string
    // Return: spell - decrypted string
    std::string fixTheSpell(std::string spell)
    {
        std::string temp;

        // Store 'A' and 'Z' from encrypted string
        for (int i = 0; i < spell.size(); i++) {
            if (spell[i] == 'A' || spell[i] == 'Z') {
                temp += spell[i];
            }
        }

        // Reverse order of 'A' and 'Z'
        std::reverse(temp.begin(), temp.end());

        int k = 0;
        // Replace order of 'A', 'Z' in spell with temp string
        for (int j = 0; j < spell.size(); j++)
        {
            if (spell[j] == 'A' || spell[j] == 'Z') {
                spell[j] = temp[k];
                k++;
            }
        }
        return spell;
    }
};