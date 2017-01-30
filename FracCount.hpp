class FracCount
{
public:
    // Calculates gcd using euclidean
    // Params: a - numerator, b - denominator
    // Return: a - greatest common denominator
    int euclidean(int a, int b)
    {
        int t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Calculates position of irreducible fraction
    // Params: numerator - top no., denominator - bottom no. 
    // Return: position - count of fraction in sequence
    int position(int numerator, int denominator)
    {
        // Start at 1/2 at position 0
        int position = 0;
        int currNum = 1;
        int currDen = 2;

        while (true) {
            // Fraction is irreducible
            if (euclidean(currNum, currDen) == 1) {
                position++;
                // Target fraction found
                if (currNum == numerator && currDen == denominator) {
                    return position;
                }
            }

            currNum++;
            // Update fraction to next in sequence
            if (currNum == currDen) {
                currNum = 1;
                currDen++;
            }
        }
    }
};