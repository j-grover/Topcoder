#include <string>
#include <cstddef>

class SimpleCompressor
{
public:
    // Uncompresses string to original string
    // Params: data - string with shortened data
    // Return: data - expanded string with only A-Z
    std::string uncompress(std::string data)
    {
        int digit;
        std::string sequence;

        // String has been uncompressed
        if (!(data.find('[') != std::string::npos)) {
            return data;
        }

        // Store index of last occurrence of '['
        std::size_t start = data.find_last_of('[');
        // Store index of first occurrence of ']' after the '['
        std::size_t end = data.find_first_of(']', start + 1);
        
        // Store single digit
        digit = data[start + 1] - '0';
        // Store sequence to be uncompressed
        sequence = data.substr(start + 2, (end - start) - 2);
        // Remove uncompressed sequence
        data.erase(start, (end - start) + 1);

        // Insert uncompressed sequence into data string
        for (int i = 0; i < digit; i++) {
            data.insert(start, sequence);
        }
        return uncompress(data);
    }
};