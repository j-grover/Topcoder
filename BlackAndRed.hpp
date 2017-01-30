#include <string>
#include <vector>
#include <climits>
using namespace std;

class BlackAndRed
{
public:
    // Calculates number of cards to remove from top of deck
    // Params: deck - string representing the cards
    // Return: minCards - index at which to add cards at front to back
    int cut(string deck)
    {
        int redCount = 0;
        int blackCount = 0;
        bool flag = true;
        vector<int> noCards;
        string deckCopy;

        for (int i = 0; i < deck.size(); i++) {

            // Create copy of string 
            deckCopy = deck;
            // Create copy of cards to be added to back
            string cards = deckCopy.substr(0, i);
            // Remove copied sub string from original string
            deckCopy.erase(0, i);
            // Add copied sub string to end of original string
            deckCopy = deckCopy + cards;

            flag = true;

            for (int j = 0; j < deck.size() && flag; j++) {
                // Current card is red
                if (deckCopy[j] == 'R') {
                    redCount++;
                }
                // Current card is black
                if (deckCopy[j] == 'B') {
                    blackCount++;
                }
                // More red cards showing, you lose
                if (redCount > blackCount) {
                    flag = false;
                }
            }

            // Reset card counts
            redCount = 0;
            blackCount = 0;

            // Add index for cut to a vector
            if (flag) {
                noCards.push_back(i);
            }
        }

        int minCards = INT_MAX;
        // Determine smallest no. out of possiblities
        for (int k = 0; k < noCards.size(); k++) {
            if (noCards[k] <= minCards) {
                minCards = noCards[k];
            }
        }
        return minCards;
    }
}; 