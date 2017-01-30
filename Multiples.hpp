class Multiples
{
public:
    // Calculates numbers divisible by factor in range given
    // Params: min - minimum no., max - maximum no., factor - dividing no. 
    // Return: count - no. of evenly divisble in range
    int number(int min, int max, int factor)
    {
        int count = 0;

        // For integers from min to max (inclusive)
        for (int i = min; i <= max; i++) {
            // Add 1 to count if evenly divisble
            if (i % factor == 0) {
                count++;
            }
        }
        return count;
    }
};