#include <vector>
#include <map>

class SimpleDuplicateRemover
{
public:
    // Removes all duplicate integers from sequence
    // Params: sequence - integer vector with possible duplicates
    // Return: sequence - vector with only rightmost occurrences
    std::vector<int> process(std::vector<int> sequence)
    {
        std::map<int, int> int_map;
        std::map<int, int>::iterator it;

        for (int i = 0; i < sequence.size(); i++) {
            
            // Search for duplicate in map
            it = int_map.find(sequence[i]);
            
            // Duplicate is found
            if (it != int_map.end()) {

                // Set duplicate to -1
                sequence[it -> second] = -1;
                // Update index
                it -> second = i;
            }
            else {
                // Insert current integer into map (int value, index)
                int_map.insert(std::pair<int, int> (sequence[i], i));
            }
        }

        // Remove all -1s from sequence
        for (int j = 0; j < sequence.size(); j++) {
            if (sequence[j] == -1) {
                sequence.erase(sequence.begin() + j);
                j--;
            }
        }
        return sequence;
    }
};