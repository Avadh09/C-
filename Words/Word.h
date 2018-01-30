#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    Word();
    Word(string text);
    virtual ~Word();

    string get_text() const;
    int get_count() const;

    void increment_count();

    friend bool operator!=(Word w1, Word w2);

private:
    string text;
    int count;
};

#endif /* WORD_H_ */
