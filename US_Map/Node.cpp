#include <math.h>
#include "Node.h"

/**
 * Default constructor.
 */
Node::Node() : next(nullptr), name(""), state(""), row(0), col(0)
{
}

/**
 * Constructor.
 * @param coordinate a geographic coordinate.
 */
Node::Node(Coordinate coordinate) : next(nullptr), name(""), state("")
{
    convert_coordinate(coordinate);
}

/**
 * Constructor.
 * @param city a city.
 */
Node::Node(City city)
    : next(nullptr), name(city.get_name()), state(city.get_state())
{
    convert_coordinate(city.get_coordinate());
}

/**
 * Destructor.
 */
Node::~Node()
{
    //cout << "Delete node " << row << "," << col
    //     << " " << name << " " << state << endl;
}

/**
 * Convert a coordinate's latitude and longitude
 * into a row and column, respectively, for printing.
 */
void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

/**
 * Getter.
 * @return the pointer to the next node.
 */
Node *Node::get_next() const { return next; }

/**
 * Getter.
 * @return the row.
 */
int Node::get_row() const { return row; }

/**
 * Getter.
 * @return the column.
 */
int Node::get_col() const { return col; }

/**
 * Getter.
 * @return the city's name.
 */
string Node::get_name() const { return name; }

/**
 * Getter.
 * @return the city's state.
 */
string Node::get_state() const { return state; }

/**
 * Overloaded > operator used to determine
 * where to insert a node into the linked list.
 * The list is sorted first by row and then by column.
 */
bool Node::operator >(const Node &other)
{
    // This node is greater than the other node if and only if
    // this node's row is greater than the other node's row,
    // or, if the two rows are equal, this node's column is greater
    // than the other node's column.
    return    (row > other.row)
           || ((row == other.row) && (col > other.col));
}

/**
 * Overloaded stream output insertion operator.
 * @param outs the output stream.
 * @param node the node to output.
 * @return the output stream.
 */
ostream& operator <<(ostream& outs, const Node& node)
{
    // City node: Output a * followed by the city's name and state.
    if (node.name.length() > 0)
    {
        outs << "*" << node.name << " " << node.state;
    }

    // Boundary node: Output a #
    else
    {
        cout << "#";
    }

    return outs;
}
