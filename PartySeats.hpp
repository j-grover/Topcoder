#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class PartySeats
{
public:
    // Sorts seating alternatively with boys and girls
    // Params: attendees - vector with attendees names and their genders
    // Return: sortedAttendees - sorted seating vector including HOST and HOSTESS
    vector<string> seating(vector<string> attendees)
    {
       vector<string> boys;
       vector<string> girls;
       vector<string> sortedAttendees;
       int noAttendees = attendees.size();

       // No way to alternate gender if:
       // Less than 4 attendees OR Odd no. of attendees OR No. of attendees / 2 is not even 
       if (noAttendees < 4 || noAttendees % 2 != 0 || (noAttendees / 2) % 2 != 0) {
           return sortedAttendees;
       }
       else {   
           int bCount = 0;
           int gCount = 0;

           // Separate boys and girls into 2 different vectors
           // Remove "boy" and "girl" from strings
           for (int i = 0; i < noAttendees; i++) {
               if (attendees[i].find("boy") != string::npos) {
                   boys.push_back(attendees[i]);
                   boys[bCount].erase(boys[bCount].find(' '), 4);
                   bCount++;
               }
               else {
                   girls.push_back(attendees[i]);
                   girls[gCount].erase(girls[gCount].find(' '), 5);
                   gCount++;
               }
           }
           // No. of boys must be equal to no. of girls for alternate seating
           if (boys.size() != girls.size()) {
               return sortedAttendees;
           }
           else {               
               // Sort vectors lexicographically
               sort(boys.begin(), boys.end());
               sort(girls.begin(), girls.end());

               int totalSeats = (2 * boys.size()) + 2;
               for (int i = 1; i <= totalSeats; i++) {
                   // Start with "HOST"
                   if (i == 1) {
                       sortedAttendees.push_back("HOST");
                   }
                   // "HOSTESS" across from "HOST"
                   else if (i == (noAttendees / 2) + 2) {
                       sortedAttendees.push_back("HOSTESS");
                   }
                   // Girls in even spots
                   else if (i % 2 == 0) {
                       sortedAttendees.push_back(girls[0]);
                       girls.erase(girls.begin());
                   }
                   // Boys in odd spots
                   else {
                       sortedAttendees.push_back(boys[0]);
                       boys.erase(boys.begin());
                   }
               }
               return sortedAttendees;
           }
       }
    }
};