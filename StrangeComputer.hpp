#include <string>

class StrangeComputer
{
public:
    // Calculates minmum operations required to set mem
    // Params: mem - string with bits to be set
    // Return: operations - no. of changes required
    int setMemory(std::string mem)
    {
        int operations = 0;
        char bit = '0';

        for (int i = 0; i < mem.size(); i++) {
            // Bit has changed
            if (mem[i] != bit) {
                bit = mem[i];
                operations++;
            }
        }
        return operations;
    }
};