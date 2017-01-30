#include <vector>

class HandsShaking
{
public:
	long handshakes(std::vector<long> &mem, int n) {
		// Already calculated
		if (mem[n] != 0) {
			return mem[n];
		}

		long count = 0;
		// Each buisnessmen shakes hand with every other
		for (int i = 0; i < n; i += 2) {
			// Handshake divides table in two of size i and n-i-2
			// Count recursively no. of shakes for the two groups
			count += handshakes(mem, i) * handshakes(mem, n - i - 2);
		}
		return mem[n] = count;
	}

	long countPerfect(int n)
	{
		std::vector<long> mem;

		// Fill vector with 0s
		for (int i = 0; i < n; i++) {
			mem.push_back(0);
		}

		// Zero buisnessmen produce one possibility
		mem[0] = 1;
		return handshakes(mem, n);
	}
};