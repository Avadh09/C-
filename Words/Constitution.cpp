//SAMPLE

/**
 * Assignment 11. STL Vector and Map
 *
 * Construct a concordance with an STL vector and an STL map.
 * Time word insertion and search operations.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <stdlib.h>
#include "Word.h"
#include "WordVector.h"
#include "WordMap.h"

using namespace std;

const string INPUT_FILE_NAME = "USConstitution.txt";
const int    MAX_SEARCHES    = 100000;

void time_word_insertions(ifstream& in, WordVector& v, WordMap& m);
void make_spot_checks(WordVector& v, WordMap& m) throw(string);
void check_concordances(WordVector& v, WordMap& m) throw(string);
void time_word_searches(WordVector& v, WordMap& m) throw(string);
string commafy(const long n);

/**
 * The main.
 */
int main()
{
    ifstream in;
    in.open(INPUT_FILE_NAME);
    if (in.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    WordVector v;  // the concordance based on an STL vector
    WordMap    m;  // the concordance based on an STL map

    try {
        time_word_insertions(in, v, m);
        make_spot_checks(v, m);
        check_concordances(v, m);
        time_word_searches(v, m);
    }
    catch (string& msg)
    {
        cout << endl << endl << "***** " << msg << endl;
    }

    return 0;
}

/**
 * Insert words into the concordances.
 * Time this operation.
 * @param in the input stream.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void time_word_insertions(ifstream& in, WordVector& v, WordMap& m)
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;

    cout << "Timed insertions ..." << endl;

    // Loop once per line of the input file.
    while (getline(in, line))
    {
        ++line_count;

        int i = 0;
        int length = line.length();
        string text = "";

        // Loop once per character of the line.
        while (i < length)
        {
            character_count++;

            // Have we found a word?
            if (isalpha(line[i]))
            {
                // Make the word all lower case.
                do
                {
                    text += tolower(line[i]);
                    i++;
                } while ((i < length) && (isalpha(line[i])));

                word_count++;

                // Insert the word into the concordances.
                v.insert(text);
                m.insert(text);

                text = "";  // get ready for the next word
            }

            i++;
        }
    }

    cout << "          Lines: " << setw(6) << commafy(line_count) << endl;
    cout << "     Characters: " << setw(6) << commafy(character_count) << endl;
    cout << "          Words: " << setw(6) << commafy(word_count) << endl;
    cout << endl;
    cout << "    Vector size: " << commafy(v.get_data().size()) << endl;
    cout << "       Map size: " << commafy(m.get_data().size()) << endl;
    cout << endl;
    cout << "    Vector total insertion time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total insertion time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

/**
 * Perform spot checks of some words.
 * Make sure the vector and map concordances agree with each other.
 * Throw an exception if they don't agree.
 */
void make_spot_checks(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Spot checks of word counts ..." << endl;

    vector<Word>       vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    // Words to check.
    vector<string> texts = {
        "amendment", "article", "ballot", "citizens", "congress",
        "constitution", "democracy", "electors", "government", "law",
        "legislature", "people", "president", "representatives",
        "right", "trust", "united", "vice", "vote"
    };

    // Loop over each word.
    for (string text : texts)
    {
        cout << "    " << text << ": ";

        // Search both concordances.
        vector<Word>::iterator      itv = v.search(text);
        map<string, Word>::iterator itm = m.search(text);

        int vcount = 0;
        int mcount = 0;

        // If the word exists, get the counts from both concordances.
        if (itv != vdata.end()) vcount = itv->get_count();
        if (itm != mdata.end()) mcount = itm->second.get_count();

        cout << "vector:";
        if (vcount > 0) cout << vcount;
        else            cout << "(not found)";

        cout << " map:";
        if (mcount > 0) cout << mcount;
        else            cout << "(not found)";

        // Do the counts match?
        if (vcount != mcount) throw(string("Count mismatch: ") + text + " "
                                              + to_string(vcount) + ":"
                                              + to_string(mcount));
        cout << endl;
    }
}

/**
 * Iterate over the vector and map concordances in parallel and
 * ensure that both agree over all the entries and in the same order.
 * Throw an exception if they don't agree.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void check_concordances(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Checking concordances ... ";  cout.flush();

    vector<Word>      vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    int vsize = vdata.size();
    int msize = mdata.size();

    if (vsize == 0) throw("Empty vector.");
    if (msize == 0) throw("Empty map.");

    // Do the number of unique words agree?
    if (vsize != msize ) throw(string("Size mismatch: ") + to_string(vsize) +
                                                 " and " + to_string(msize));

    vector<Word>::iterator      itv = vdata.begin();
    map<string, Word>::iterator itm = mdata.begin();

    // Iterate over both concordances in parallel.
    while (itv != vdata.end())
    {
        // Does each word agree?
        if (*itv != itm->second)
        {
            throw string(string("Data mismatch: ")
                    + itv->get_text() + ":" + to_string(itv->get_count())
                    + " and " + itm->second.get_text() + ":"
                    + to_string(itm->second.get_count()));
        }

        ++itv;
        ++itm;
    }

    cout << "both match!" << endl;
}

/**
 * Perform random searches of words in the concordances.
 * Time this operation.
 * Throw an exception if a word isn't found.
 * @param v the vector concordance.
 * @param m the map concordance.
 */
void time_word_searches(WordVector& v, WordMap& m) throw(string)
{
    cout << endl << "Timed searches (" << commafy(MAX_SEARCHES)
                 << " searches) ..." << endl;

    vector<Word>       vdata = v.get_data();
    map<string, Word>& mdata = m.get_data();

    int size = vdata.size();
    srand(time(NULL));

    v.reset_elapsed_time();
    m.reset_elapsed_time();

    // Loop to perform searches.
    for (int i = 1; i <= MAX_SEARCHES; i++)
    {
        // Pick a random word in the concordance.
        int index = rand()%size;
        string text = v.get_data()[index].get_text();

        // Is it in the vector concordance?
        if (v.search(text) == vdata.end())
        {
            throw string("Not found in vector: ") + text;
        }

        // Is it in the map concordance?
        if (m.search(text) == mdata.end())
        {
            throw string("Not found in map: ") + text;
        }
    }

    cout << endl;
    cout << "    Vector total search time: " << setw(8)
         << commafy(v.get_elapsed_time()) << " usec" << endl;
    cout << "       Map total search time: " << setw(8)
         << commafy(m.get_elapsed_time()) << " usec" << endl;
}

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(const long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
