#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node : public Element
{
public:

	Node();
	Node(long value);
	Node(const Element& elmnt);
	Node(const Node& other);

	virtual ~Node();
	//Element
	Node *next;
	Element element;
    /***** Complete this class. *****/
};

#endif /* NODE_H_ */
