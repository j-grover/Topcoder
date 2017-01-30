#include <vector>
#include <algorithm>

class ImportantTasks
{
public:
    // Finds no. of tasks that can be performed
    // Params: complexity - vector of ints, computers - vector of ints
    // Return: maximal - max no. of tasks performed
    int maximalCost(std::vector<int> complexity, std::vector<int> computers)
    {
        std::vector<int>::iterator max_complexity;
        std::vector<int>::iterator max_computers;
        int maximal = 0;

        // While complexity and computers vectors aren't empty
        while (!complexity.empty() && !computers.empty()) {

            // Iterators for max elements of vectors
            max_complexity = std::max_element(complexity.begin(), complexity.end());
            max_computers = std::max_element(computers.begin(), computers.end());

            // Indices for max elements of vectors
            int max_1 = std::distance(complexity.begin(), max_complexity);
            int max_2 = std::distance(computers.begin(), max_computers);

            // If max complexity can be performed on max computer
            if (complexity[max_1] <= computers[max_2]) {
                maximal++;
                computers.erase(max_computers);
            }
            complexity.erase(max_complexity);
        }
        return maximal;
    }
};