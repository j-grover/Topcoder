#include <string>
using namespace std;

class StreetParking
{
public:
    // Calculates total number of possible parking spaces 
    // Params: street - string where each char represents 5m in length
    // Return: freeSpaces - no. of free spaces to park in street
    int freeParks(string street)
    {
        int freeSpaces = 0;

        // Go through all positions in street
        for (int i = 0; i < street.length(); i++) {
            
            // Ignore positions with D driveway, B bus stop and S side street
            if (street[i] != 'D' && street[i] != 'B' && street[i] != 'S') {
                // First position in street
                if (i == 0) {
                    // Check for no side street in next 5m and no bus stop in next 10m 
                    if (street[i+1] != 'B' && street[i+2] != 'B' && street[i+1] != 'S') {
                        freeSpaces++;
                    }
                }
                // Second last position in street
                else if (i == (street.length() - 2)) {
                    // Check for no side street 5m either side and no bus stop in next 5m
                    if (street[i+1] != 'S' && street[i-1] != 'S' && street[i+1] != 'B') {
                        freeSpaces++;
                    }
                }
                // Last position in street
                else if (i == (street.length() - 1)) {
                    // Check for no side street in previous 5m
                    if (street[i-1] != 'S') {
                        freeSpaces++;
                    }
                }
                // All other positions in street
                else {
                    // Check for no side street 5m either side and no bus stop in next 10m
                    if (street[i+1] != 'B' && street[i+2] != 'B' && street[i+1] != 'S' && street[i-1] != 'S') {
                        freeSpaces++;
                    }
                }
            }
        }
        return freeSpaces;
    }
};