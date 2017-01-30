#include <string>
#include <vector>

class GoodHours
{
public:
	bool goodTime(std::vector<int> time)
	{
		// H and H:MM split
		if (time[0] == (time[1] * time[2] * time[3])) {
			return true;
		}
		// HH and MM split
		if ((time[0] * time[1]) == (time[2] * time[3])) {
			return true;
		}
		// HHM and M split
		if ((time[0] * time[1] * time[2]) == time[3]) {
			return true;
		}
		// Not a good time
		return false;
	}

	int howMany(std::string beforeTime, std::string afterTime)
	{
		std::vector<int> b_Time;
		std::vector<int> a_Time;

		// String to int vector
		for (int i = 0; i < beforeTime.size(); i++) {
			if (i != 2) {
				b_Time.push_back(beforeTime[i] - '0');
				a_Time.push_back(afterTime[i] - '0');
			}
		}

		// Number of good times
		int num_Good = 0;

		// Check if afterTime is a good time
		if (goodTime(a_Time)) {
			num_Good++;
		}

		int H1, H2, M1, M2;

		// Iterate through time range
		while (b_Time != a_Time) {
			
			// Check if current time is a good time
			if (goodTime(b_Time)) {
				num_Good++;
			}

			H1 = b_Time[0];
			H2 = b_Time[1];
			M1 = b_Time[2];
			M2 = b_Time[3];

			// Increment for time 23:59
			if (H1 == 2 && H2 == 3 && M1 == 5 && M2 == 9) {
				b_Time[0] = 0;
				b_Time[1] = 0;
				b_Time[2] = 0;
				b_Time[3] = 0;
			}
			// Increment for time H9:59
			else if (H2 == 9 && M1 == 5 && M2 == 9) {
				b_Time[0]++;
				b_Time[1] = 0;
				b_Time[2] = 0;
				b_Time[3] = 0;
			}
			// Increment for time HH:59
			else if (M1 == 5 && M2 == 9) {
				b_Time[1]++;
				b_Time[2] = 0;
				b_Time[3] = 0;
			}
			// Increment for time HH:M9
			else if (M2 == 9) {
				b_Time[2]++;
				b_Time[3] = 0;
			}
			// General minute increment
			else {
				b_Time[3]++;
			}
		}
		return num_Good;
	}
};