class UnsealTheSafe
{
public:
    // Returns number of possible passwords
    // Params: N - number of digits in password
    // Return: passCount - no. of passwords
    long countPasswords(int N)
    {
        // Final digit x No. of steps
        // 10 (0 - 9) x 31 (Max N= 30, first col not used)
        long table[10][31];

        long passCount = 0;

        // 1 way to enter single digit in 1 step
        for (int i = 0; i <= 9; i++) {
            table[i][1] = 1;
        }

        // Fill no. of ways to get to each digit after j steps upto N
        for (int j = 2; j <= N; j++) {
            table[0][j] = table[7][j-1];  
            table[1][j] = table[2][j-1] + table[4][j-1];
            table[2][j] = table[1][j-1] + table[3][j-1] + table[5][j-1];
            table[3][j] = table[2][j-1] + table[6][j-1]; 
            table[4][j] = table[1][j-1] + table[5][j-1] + table[7][j-1]; 
            table[5][j] = table[2][j-1] + table[4][j-1] + table[6][j-1] + table[8][j-1]; 
            table[6][j] = table[3][j-1] + table[5][j-1] + table[9][j-1]; 
            table[7][j] = table[4][j-1] + table[8][j-1] + table[0][j-1]; 
            table[8][j] = table[5][j-1] + table[7][j-1] + table[9][j-1]; 
            table[9][j] = table[6][j-1] + table[8][j-1]; 
            table[0][j] = table[7][j-1];
        }

        // Sum no. of ways to get to each digit in N steps
        for (int k = 0; k <= 9; k++) {
            passCount += table[k][N];
        }
        return passCount;
    }
};