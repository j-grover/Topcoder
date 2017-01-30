#include <vector>
#include <string>

class CorporationSalary
{
public:
	long calcSalary(std::vector<std::string> &relations, std::vector<int> &employees, int n)
	{
		// Base case, employee salary already calculated
		if (employees[n] != 0) {
			return employees[n];
		}

		long count = 0;
		for (int i = 0; i < relations.size(); i++) {
			// Employee has a subordinate
			if (relations[n][i] == 'Y') {
				// Recursive call
				count += calcSalary(relations, employees, i);
			}
		}
		
		// Employee has no subordinates
		if (count == 0) {
			count++;
		}
		return employees[n] = count;
	}

	long totalSalary(std::vector<std::string> relations)
	{
		int salary = 0;
		std::vector<int> employees;

		// Fill vector with 0s
		for (int i = 0; i < relations.size(); i++) {
			employees.push_back(0);
		}

		// Sum salaries of each emplyee
		for (int i = 0; i < relations.size(); i++) {
			salary += calcSalary(relations, employees, i);
		}
		return salary;
	}
};