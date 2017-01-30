class Truckloads
{
public:
    // Calculates minimum number of trucks required
    // Params: numCrates - no. of crates, loadSize - max. size of crate
    // Return: no. of trucks
    int numTrucks(int numCrates, int loadSize)
    {
        // Pile fits on truck
        if (numCrates <= loadSize) {
            return 1;
        }
        // Divide pile into half
        return numTrucks(numCrates / 2, loadSize) + numTrucks(numCrates / 2 + numCrates % 2, loadSize);
    }
};
