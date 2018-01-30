#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */

// reference geeksforgeeks
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{

		 for (int interval = size/2; interval > 0; interval /= 2)
		    {
		        for (int i = interval; i < size; i += 1)
		        {
		            Element temp = data[i];

		            int j;

		            for (j = i; j >= interval && data[j - interval] > temp; j -= interval)
		            {
		            	compare_count++;
		            	if(data[j-interval].get_value()!= data[j].get_value())
		            	{
		            		data[j] = data[j - interval];
		            		move_count++;
		            	}



		            }
		            compare_count++;
		            if(data[j].get_value() != temp.get_value())
		            {
		            	data[j] = temp;
		            	move_count++;
		            }

		        }
		    }
}
