#include "SortedLinkedList.h"

/**
 * Default constructor.
 */
SortedLinkedList::SortedLinkedList() : head(nullptr)
{
}

/**
 * Destructor.
 */
SortedLinkedList::~SortedLinkedList()
{
    Node *next;

    //cout << endl << "Delete linked list:" << endl;

    // Loop to deallocate each node in the list.
    for (Node *ptr = head; ptr != nullptr; ptr = next)
    {
        next = ptr->next;
        delete ptr;
    }

    head = nullptr;
}

/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */
void SortedLinkedList::insert(Node *node)
{
    // First node of the list.
    if (head == nullptr)
    {
        head = node;
    }

    // Insert before the first node.
    else if (!(*node > *head))
    {
        node->next = head;
        head = node;
    }

    // Insert somewhere else in the list.
    else
    {
        Node *ptr = head;  // pointer to iterate through the list
        Node *prev;        // stays one node behind ptr

        // Loop until ptr reaches the end of the list or the
        // insertion node is greater than the node ptr points to.
        while ((ptr != nullptr) && (*node > *ptr))
        {
            prev = ptr;
            ptr = ptr->next;
        }

        // Insert the new node between the node that prev points to
        // and the node that ptr points to.
        prev->next = node;
        node->next = ptr;
    }
}

/**
 * Overloaded stream output insertion operator.
 * @param outs the output stream.
 * @param list the list of nodes to output.
 * @return the output stream.
 */
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
    int line = 0;      // current line
    int position = 0;  // current position in the current line

    // Loop over the nodes in the list.
    // Each time through the loop, ptr points to the next node.
    for (Node *ptr = list.get_head(); ptr != nullptr; ptr = ptr->next)
    {
        // Output blank lines to catch up to the next node's line.
        if (line != ptr->get_row())
        {
            position = 0;

            do
            {
                cout << endl;  // output a blank line
                line++;
            } while (line < ptr->get_row());
        }

        // Output the next node only if its column is at or before
        // the current print position.
        if (position <= ptr->get_col())
        {
            // Output blank characters to catch up to the next node's column.
            while (position < ptr->get_col())
            {
                cout << " ";  // output a blank character
                position++;
            }

            cout << *ptr;  // output the next node
            position++;

            // If it's a city node, advance the position
            // to account for the city's name and state.
            if (ptr->get_name().length() > 0)
            {
                position +=   ptr->get_name().length()
                            + ptr->get_state().length() + 1;
            }
        }
    }

    return outs;
}
