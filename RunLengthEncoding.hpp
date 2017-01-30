#include <string>
#include <cctype>
#include <cstdlib>

class RunLengthEncoding
{
public:
    // Returns decoded string if not longer than 50 chars
    // Params: text - encoded string
    // Return: decoded - decoded string ("TOO LONG" for > 50 chars)
    std::string decode(std::string text)
    {
        std::string decoded;
        std::string digits;
        int number;
        int length = 0;

        // Handle no digit in front of first letter
        if (!(std::isdigit(text[0]))) {
            text.insert(0, "1");
        }

        for (int i = 1; i < text.size(); i++) {
            // Add 1 before all single letters
            if (!(std::isdigit(text[i])) && !(std::isdigit(text[i-1]))) {
                text.insert(i, "1");
            }
        }

        for (std::string::iterator i = text.begin(); i < text.end(); i++) {
            // Char is a digit
            if (std::isdigit(*i)) {
                digits += *i;

                // Look for number with more than 2 digits
                if (digits.size() > 2) {
                    return "TOO LONG";
                }
            }
            else {
                // Convert string to int
                number = std::atoi(digits.c_str());
                length += number;

                // More than 50 chars in decoded string
                if (length > 50) {
                    return "TOO LONG";
                }

                // Build decoded string
                for (int j = 0; j < number; j++) {
                    decoded += *i;
                }
                digits.clear();
            }
        }
        return decoded;        
    }
};