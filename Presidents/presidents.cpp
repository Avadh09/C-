#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const string INPUT_FILE_NAME = "presidents.txt";

/**
 * The main: Read the input file and print the report.
 */
int main()
{
    // Open the input file.
    ifstream input;
    string content,str1,str2,str3,str4;
    string firstname,middlename,lastname,party;
    int Born,Died,age,start,end;
    char delim[]=" ,;!?";

    char line;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    while(getline(input,content))
    {

    	// parse the line until "(" << use substring function of the string

    	input>>firstname>>middlename>>lastname>>Born>>Died;

    	cout<<firstname<<middlename<<lastname<<Born<<Died;

    	std::string delimiter1 = "(";
    	std::string delimiter2= " ";
    	std::string delimiter3=")";

    	//std::string str1 = content.substr(0, content.find(delimiter1));
    	//cout<<content;

    	for(int i=0 ; i<content.length();i++)
    	{
    		cin>>firstname>>middlename>>lastname;
    	}

    	/*for(int i = 0; i < tokens.size() - 1; i++) {
    	        cout << left << setw(tokenWidth) << setfill(space) << tokens[i];
    	        cout << "|";
    	        cout << right << setw(lengthWidth) << setfill(space) << tokens[i].size();
    	        cout << endl;
    	    }
*/

    	// parse first name, middle name and last name by " " << use substring

    	//std::string str2 = content.substr(0, content.find(delimiter2));
    	//cout<<str2<<endl;
    	//int firstname=str2.length();
    	//int nextvalue=firstname+1;
    	//cout<<firstname<<endl;
    	//std::string str3 = content.substr(nextvalue,str1.find(delimiter3));

    	//cout<<str3<<endl;
    	//size_t pos = 0;

    	//std::string str4 = content.substr(content.find(delimiter1)+1);
    	//cout<<str4<<endl;
    	// save first name and last name in a variable



    	// parse line from "(" until ")"

    	// parse born and died with "-" and save them in a variable

    	// parse party from ")" until next occurrence of " "

    	// save part in a string variable

    	// parse start and end from " " after party until end of line

    	// parse start and end using "-" and save them in variables

    	// print the entire out for a line by filling spaces in between

    }

    /***** Complete this program. *****/

    return 0;
}
