#include "ShellSortOptimal.h"
#include <math.h>


/**
 * Constructor.
 * @param name the name of this algorithm.
 */

int interval_optimal(int k);

ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */

int interval_optimal(int k)
{
	return ((pow(3,k)-1)/2);
}

//

void ShellSortOptimal::run_sort_algorithm() throw (string)
{

		int k = 1;

		while (k > 0) {
			if (interval_optimal(k) < size) {
				k++;

			}

			if (interval_optimal(k) > size) {
				break;
			}
		}

		k = k - 1;
		int interval;
		//for(int i=k ; k > 0 ; )
		for (; k > 0; k--) {
			interval = interval_optimal(k);
			for (int i = interval; i < size; i += 1) {

				Element temp = data[i];

				int j;
				for (j = i; j >= interval && data[j - interval] > temp; j -= interval)
				{
					compare_count++;
					if(data[j].get_value()!= data[j-interval].get_value())
					{
						data[j] = data[j - interval];
						move_count++;

					}
				}

				compare_count++;
				if(data[j].get_value()!= temp.get_value())
				{
					data[j] = temp;
					move_count++;
				}

			}
		}
}
