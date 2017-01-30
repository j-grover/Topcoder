#include <string>
#include <vector>

class VeryInterestingMovie
{
public:
	int maximumPupils(std::vector<std::string> seats)
	{
		int students = 0;
		int count = 0;

		// Number of rows in the theatre
		int rows = seats.size();
		// Number of seats in each row
		int rowSeats = seats[0].size();

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rowSeats; j++) {	
				// Count number of adjacent available seats	
				while (seats[i][j] != 'N' && j < rowSeats) {
					count++;
					j++;
				}
				// Number of adjacent available seats is even
				if (count % 2 == 0) {
					students += count / 2;
				}
				// Number of adjacent available seats is odd
				else {
					students += (count / 2) + 1;
				}
				count = 0;
			}
		}
		return students;
	}
};