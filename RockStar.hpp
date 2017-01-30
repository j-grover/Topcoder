class RockStar
{
public:
	int getNumSongs(int ff, int fs, int sf, int ss)
	{
		int songCount = 0;

		// Start with a fast starting song
		if (fs > 0 || ff > 0) {
			// Play all ff songs
			songCount += ff;

			// Equal or less fs songs than sf songs
			if (fs > 0 && fs <= sf) {
				songCount += 2 * fs + ss;
			}
			// More fs songs than sf songs
			else if (fs > 0) {
				songCount += 2 * sf + ss + 1;
			}
		}
		// Only slow starting songs
		else {
			// Play all ss songs
			songCount += ss;
			// Play one sf song if possible
			if (sf > 0) {
				songCount++;
			}
		}
		return songCount;
	}
};