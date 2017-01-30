#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class AzimuthMonitoring
{
public:
    // Calculates azimuth - angle between north and direction robot is facing
    // Params: instructions - vector with robot's instruction set
    // Return: azimuth - the robot's final azimuth
    int getAzimuth(vector<string> instructions) 
    {
        int azimuth = 0;

        // Iterate over all instructions or until "HALT" instruction
        for (int i = 0; i < instructions.size() && instructions[i] != "HALT"; i++) {
            
            // Turn left 90 degrees
            if (instructions[i] == "LEFT") {
                azimuth -= 90;
            }
            // Turn right 90 degrees
            else if (instructions[i] == "RIGHT") {
                azimuth += 90;
            }
            // Turn 180 degrees
            else if (instructions[i] == "TURN AROUND") {
                azimuth += 180;
            }
            // Handle X degrees of rotation of form "direction X" where direction is LEFT or RIGHT
            else {
                // New string with direction part of the instruction
                string direction = instructions[i].substr(0, instructions[i].find(' '));
                
                // New string with degrees part of the instruction
                string degrees = instructions[i].substr(instructions[i].find(' ') + 1);
                
                // Update azimuth according to direction
                if (direction == "LEFT") {
                    azimuth -= atoi(degrees.c_str());
                }
                else {
                    azimuth += atoi(degrees.c_str());
                }
            }
        }
        
        // Wrap azimuth to be between 0 and 360
        while (azimuth < 0) {
            azimuth += 360;
        }
        while (azimuth >= 360) {
            azimuth -= 360;
        }
        return azimuth;
    }
};