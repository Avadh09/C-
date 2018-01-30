#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */

// mycodeschool code
void QuickSorter::quicksort(const int left, const int right)
{
    /***** Complete this member function. *****/

	Element pivot = choose_pivot(left,right);
	if(left < right)
	{
		int partitionIndex = partition(left,right,pivot);
		quicksort(left,partitionIndex-1);
		quicksort(partitionIndex+1,right);

	}
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 *
 *
 */


// reference https://www.youtube.com/watch?v=COk73cpQbFQ(my codeschool)

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    /***** Complete this member function. *****/

		//pivot=data[right];
		int partitionindex=left;

		for (int i=left ; i<right; i++)
		{
			compare_count++;
			if(data[i].get_value() < pivot.get_value())
			{
				swap(i,partitionindex);
				partitionindex++;
			}
		}
			swap(partitionindex,right);
			return partitionindex;

}
