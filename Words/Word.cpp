#include <string>
#include "Word.h"
using namespace std;

/**
 * Default constructor.
 */
Word::Word() : text(""), count(0)
{
}

/**
 * Constructor.
 * Create a word entry with the given text. Initialize the count to 1.
 * @param text the text of the word.
 */
Word::Word(string text) : text(text), count(1)
{
}

/**
 * Destructor.
 */
Word::~Word()
{
}

/**
 * Getter.
 * @return the text.
 */
string Word::get_text()  const { return text; }

/**
 * Getter.
 * @return the count.
 */
int Word::get_count() const { return count; }

/**
 * Increment the count by 1.
 */
void Word::increment_count() { count++; }

/**
 * Overloaded != operator. Two word entries are unequal
 * if either their texts or their counts are unequal.
 */
bool operator!=(Word w1, Word w2)
{
    return (w1.text != w2.text) || (w1.count != w2.count);
}
