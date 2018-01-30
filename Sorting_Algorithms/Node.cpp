#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/
Node::Node() : next(nullptr){}

Node::Node(long value) : Element(value),next(nullptr){}

Node::Node(const Node& other)
{
	this->element=other;
	next=nullptr;
}

Node::Node(const Element& elmnt)
{
	this->element=elmnt;
	next=nullptr;
}
Node::~Node(){}
