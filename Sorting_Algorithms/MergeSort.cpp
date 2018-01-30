#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm() throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */

// reference d.s malik
void MergeSort::mergesort(LinkedList& list)
{
//	LinkedList list1;
//	LinkedList list2;
//
//	list.split(list1,list2);
//		move_count+=2;
//
//		mergesort(list1);
//		mergesort(list2);
//
//		merge(list,list1,list2);

}
/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list, LinkedList& sublist1, LinkedList& sublist2)
{
/*
	Node* node1=sublist1.get_head();
	Node* node2=sublist2.get_head();

	list.reset();

		while((node1!=nullptr) && (node2!=nullptr))
		{
			if(node1->element.get_value() <= node2->element.get_value())
			{
				list.add(sublist1.remove_head());

				node1=sublist1.get_head();
			}
			else
			{
				list.add(sublist2.remove_head());

				node2=sublist1.get_head();
			}

			compare_count++;
			move_count++;
		}

		if(node1!=nullptr)
		{
			list.concatenate(sublist1);
			move_count++;
		}
		if(node2!=nullptr)
		{
			list.concatenate(sublist2);
			move_count++;
		}*/
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }
