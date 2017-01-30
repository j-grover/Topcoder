#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

class LostParentheses
{
public:
	int minResult(std::string e)
	{
		std::vector<std::string> operators;

		// Make new vector consisting of operators
		// Remove operators from string e
		for (int i = 0; i < e.size(); i++) {
			if (e[i] == '+') {
				operators.push_back("+");
				e[i] = ' ';
			}
			else if (e[i] == '-') {
				operators.push_back("-");
				e[i] = ' ';
			}
		}

		std::vector<int> digits;
		std::stringstream ss(e);
		std::string digit;

		// Make new vector consisting of operands
		while (ss >> digit) {
			digits.push_back(std::atoi(digit.c_str()));
		}

		// Set value to first number in vector
		int value = digits[0];

		int i = 0;
		// Evaluate expression until first '-' is reached
		while (i < operators.size() && operators[i] == "+") {
			value += digits[i + 1];
			i++;
		}

		int sum = 0;
		// Sum numbers after first '-'
		for (int j = i + 1; j < digits.size(); j++) {
			sum += digits[j];
		}

		// Difference between the two expressions
		return value - sum;
	}
};