#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    	static long get_constructor_count();
        static long get_copy_count();
        static long get_destructor_count();
        //static long get_moves();
       // static long get_compares();
        static void reset();

        bool operator <(Element& other);
        bool operator >(const Element& other) const;
        friend ostream& operator <<(ostream& outs, const Element& other);
    /***** Complete this class. *****/

private:
    long value;

   // static long moves;
    //static long compares;
    static long copy_count;     // To get copy constructor count
    static long destructor_count; // To get destructor count

};

#endif /* DATA_H_ */
