#include <iostream>
#include "Element.h"

using namespace std;



long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {//copy_count++;
}


/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{

	copy_count++;
	value=other.value;

}

/**
 * Destructor.
 */
Element::~Element()
{
	destructor_count++;

}

long Element::get_copy_count()
{
	return copy_count;
}

long Element::get_destructor_count()
{
	return destructor_count;
}

void Element::reset()
{

	copy_count=0;
	destructor_count=0;
	//value=0;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

bool Element::operator <(Element& other)
{
	return value < other.value;
}
bool Element::operator >(const Element& other) const
{
	return value > other.value;
}

ostream& operator <<(ostream& outs,const Element& other)
{
	outs<<other.get_value();
	return outs;
}
