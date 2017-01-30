class Inchworm
{
public:
    // Calculates number of leaves consumed by inchworm
    // Params: branch - length of branch, rest - distance travelled between rests,
    //         leaf - distance between leaves
    // Return: consumed - no. of leaves consumed
    int lunchtime(int branch, int rest, int leaf)
    {
        int consumed = 0;
        // Iterate over the length of the branch
        for (int i = 0; i <= branch; i += rest) {
            // Inchworm has stopped at a leaf
            if (i % leaf == 0)
                consumed++;
        }
        return consumed;
    }
};