#include "City.h"

/**
 * Default constructor.
 */
City::City() : name(""), state("")
{
}

/**
 * Destructor.
 */
City::~City()
{
    //cout << "Delete city " << name << " " << state << endl;
}

/**
 * Getter.
 * @return the city's name.
 */
string City::get_name() const { return name; }

/**
 * Getter.
 * @return the city's state.
 */
string City::get_state() const { return state; }

/**
 * Getter.
 * @return the city's coordinate.
 */
Coordinate City::get_coordinate() const { return coordinate; }

/**
 * Overloaded output stream insertion operator.
 * @param ostream the output stream.
 * @param city the city to output.
 * @return the output stream.
 */
ostream& operator <<(ostream& outs, const City& city)
{
    outs << "*" << city.name << " " << city.state;
    return outs;
}

/**
 * Overloaded input stream extraction operator.
 * Read city data from a CSV file.
 * @param istream the input stream.
 * @param city the city to input.
 * @return the input stream.
 */
istream& operator >>(istream& ins, City& city)
{
    string str;

    // Name and state.
    getline(ins, city.name,  ',');
    getline(ins, city.state, ',');

    // Coordinate.
    ins >> city.coordinate;

    return ins;
}
