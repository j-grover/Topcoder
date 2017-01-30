class ThrowTheBall
{
public:
    // Calculates number of times the ball is passed around
    // Params: N - no. of friends, M - no. of times ball recieved by player, L - no. of places to pass
    // Return: passCount - no. of times ball is passed
    int timesThrown(int N, int M, int L) 
    {
        // Allocate space for N friends to hold no of times ball recieved
        int *friends = new int[N];
        int currPlayer = 0;
        int passCount = 0;

        while (true) {
            // Increment player ball recieved count
            friends[currPlayer]++;

            // currPlayer player has recieved ball M times (game over) return passCount
            if (friends[currPlayer] == M) {
                return passCount;
            }
            // Pass ball L places to left
            else if (friends[currPlayer] % 2 == 0) {
                currPlayer -= L;
                // Wrap player index to be between 1 and N
                while (currPlayer < 0) {
                    currPlayer += N;
                }
            }
            // Pass ball L places to right
            else {
                currPlayer += L;
                // Wrap player index to be between 1 and N
                while (currPlayer > N-1) {
                    currPlayer -= N;
                }
            }
            // Increment ball passed count
            passCount++;
        }
    }
};