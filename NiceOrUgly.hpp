#include <string>

class NiceOrUgly
{
public:
	std::string describe(std::string s)
	{
		for (int i = 0; i < s.size(); i++) {
			// Replace all vowels with 'A'
			if (s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				s[i] = 'A';
			}
			// Replace all consonants with 'B'
			else if (s[i] != 'A' && s[i] != '?') {
				s[i] = 'B';
			}
		}

		int vowels = 0;
		int maxVowels = 0;
		int consonants = 0;
		int maxConsonants = 0;

		bool isNice = true;
		bool isUgly = false;

		for (int i=0;i<s.size();++i)
		{
			// Increment counts for a vowel 
			// Reset consonant counts
			if (s[i]=='A') {
				vowels++;
				maxVowels++;
				consonants = 0;
				maxConsonants = 0;
			}
			// Increment counts for a consonant
			// Reset vowel counts
			else if (s[i] == 'B') {
				consonants++;
				maxConsonants++;
				vowels = 0;
				maxVowels = 0;
			}
			// Question mark found
			else if (s[i] =='?')
			{
				// Choose a consonant for '?'
				if (vowels == 2) {
					vowels = 0;
					consonants = 1;
				}
				// Choose a vowel for '?'
				else if (consonants == 4) {
					vowels = 1;
					consonants = 0; 
				}
				// Reset counts
				else {
					vowels = 0;
					consonants = 0; 
				}
				maxVowels++;
				maxConsonants++;
			} 

			// Check if string is nice
			isNice = isNice && (consonants < 5 && vowels < 3);

			// Check if string is ugly
			isUgly = isUgly || (maxConsonants >= 5 || maxVowels >= 3);
		}

		// String is nice and ugly
		if (isNice && isUgly) {
			return "42";
		}
		// String is only nice
		else if (isNice) {
			return "NICE";
		}
		// String is only ugly
		else {
			return "UGLY";
		}
	}
};