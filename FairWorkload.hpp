#include <vector>

class FairWorkload
{
public:
	int getMostWork(std::vector<int> folders, int workers)
	{
		int minWorkload = folders[0];
		int maxWorkload = 0;
		int workload;
		int workerCount;
		int folder;

		// Calcualte minimum and maximum workloads
		for (int i = 0; i < folders.size(); i++) {
			maxWorkload += folders[i];
			if (minWorkload < folders[i]) {
				minWorkload = folders[i];
			}
		}

		// Binary search to assign folders
		while (minWorkload < maxWorkload) {

			// Initial folder
			folder = minWorkload + (maxWorkload - minWorkload) / 2;
			workerCount = 1;
			workload = 0;

			for (int i = 0; i < folders.size(); i++) {
				// Add folder to current worker
				if (workload + folders[i] <= folder) {
					workload += folders[i];
				}
				// Add folder to next worker
				else {
					workerCount++;
					workload = folders[i];
				}
			}

			// Assign folders
			if (workerCount <= workers) {
				maxWorkload = folder;
			}
			else {
				minWorkload = folder + 1;
			}
		}
		return minWorkload;
	}
};