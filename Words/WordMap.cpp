#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

/**
 * Default constructor.
 */
WordMap::WordMap()
{
}

/**
 * Destructor.
 */

WordMap::~WordMap()
{
}

/**
 * Getter.
 * @return a reference to the data map.
 */
map<string, Word>& WordMap::get_data() { return data; }

/**
 * Getter.
 * @return the frequency count.
 */
int WordMap::get_count(const string text) const
{
    map<string, Word>::const_iterator it = data.find(text);
    return it != data.end() ? (it->second).get_count() : -1;
}

/**
 * Insert a new word into the map,
 * or increment the count of an existing word.
 * Time this operation.
 * @param text the text of the word to insert or increment.
 */
void WordMap::insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = data.find(text);

    // Not already in the map: Enter the new word.
    if (it == data.end())
    {
        data[text] = Word(text);
    }

    // Already in the map: Increment the word's count.
    else
    {
        (it->second).increment_count();
    }

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());
}

/**
 * Search the map for a word entry with the given text.
 * Time this operation.
 * @param text the text of the word to find.
 * @return an iterator pointing to the word entry if found, or data.end() if not.
 */
map<string, Word>::iterator WordMap::search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = data.find(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());

    // Return the iterator.
    return it;
}
