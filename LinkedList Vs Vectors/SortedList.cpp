#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedList::SortedList()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedList::~SortedList()
{
    Node::reset();
}

/**
 * @return the size of the data list.
 */
int SortedList::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

/**
 * Return a forward iterator pointing at the indexed position.
 * @param index the index
 * @return the iterator.
 */
list<Node>::iterator SortedList::position(const int index)
{
    // The index is closer to the beginning of the list.
    if (index < data.size() - index)
    {
        // Use a forward iterator starting from the beginning
        // to reach the desired node.
        list<Node>::iterator it = data.begin();
        advance(it, index);
        return it;
    }

    // The index is closer to the end of the list.
    else
    {
        // Use a reverse iterator starting from the end
        // to read the desired node.
        list<Node>::reverse_iterator rit = data.rbegin();
        advance(rit, data.size() - index - 1);

        // Convert the reverse iterator to a forward iterator.
        list<Node>::iterator it = --(rit.base());
        return it;
    }
}

/**
 * Insert a new node at the beginning of the data list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
    list<Node>::iterator it = data.begin();
    data.insert(it, Node(value));
}

/**
 * Append a new node at the end of the data list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
    data.push_back(Node(value));
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
    list<Node>::iterator it = position(index);
    data.erase(it);
}

/**
 * Insert a new node into the data list at the
 * appropriate position to keep the list sorted.
 */
void SortedList::insert(const long value)
{
    list<Node>::const_iterator it = data.begin();

    // Look for the appropriate position to insert.
    while ((it != data.end()) && (value > it->get_value())) it++;
    data.insert(it, Node(value));
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node& SortedList::at(const int index)
{
    list<Node>::iterator it = position(index);
    return *it;
}
