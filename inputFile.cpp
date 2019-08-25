/***********************************************
** Name: Jamie Loebe
** Date: 10-07-2018
** Description: This is the source file for
** the inputFile file. 
***********************************************/

#include "inputFile.hpp"
#include <fstream>
#include <string>

using std::ifstream;
using std::string;



/**************************************************
** Description: This function loops through each 
** paragraph string in the input file, then counts 
** the frequencies of each letter in the paragraph and
** stores the frequencies of each in the array.
** It also specifies to count only lower case letters
**************************************************/

void count_letters(ifstream &inputFile, int* count)
{
    string paragraph = "", line;
    int j = 0;
    char ch;

    for (j = 0; j < 26; j++) // for loop through lower case letters
    {
        count [j] = 0; // initialize array to 0
    }

    while (getline(inputFile, line)) // Pull through each 'line' of input file
    {
        if (line.empty()) // If line is empty/has nothing
        {
            break; // Break from loop
        }
        else
        {
            for ( j = 0; j < line.length(); j++) // Otherwise, interate through until the end of the line
            {
                if (isalpha(line[j])) // Confirm if it is a letter or not, a-z
                {
                    ch = tolower(line[j]); // set chars to be lower case letters
                    count [(int)ch - 97] += 1; // Count through ASCII characters, cast as ints.
                }
            }
        }
    }
}
