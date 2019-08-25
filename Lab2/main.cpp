/************************************************
** Name: Jamie Loebe
** Date: 10-07-2018
** Description: This program reads in an input file,
** and outputs the frequencies of each letter in 
** each paragraph. The program terminates in case of
** not being able to find the file.
*************************************************/

#include <iostream>
#include <fstream>

#include "inputFile.hpp"
#include "outputFile.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::ofstream;
using std::fstream;

using namespace std;

int main()
{
    string word;
    ifstream inputFile;
    ofstream outputFile;
    string inFileName,outFileName; 

    int count[26] = {0}, j=1; // Initialize array to 0, set array size to 26.

    cout << "This program will read your file, count the letter frequencies in each " << endl;
    cout << "paragraph, then write the results to a new file.\n";
    cout << endl;
    cout << "Which file would you like to read?" << endl;
    cin >> inFileName; // User inputs file name
    cout << endl;

    inputFile.open(inFileName.c_str()); // Open input file
    
    if (inputFile.fail()) // If input fails to open
    {
        cout << "File open error!" << endl;
        return 1; // Terminate
    }

    while (inputFile) // While input file opens
    {
        count_letters(inputFile, count); // Read in paragraph string, count letter frequencies and store them in the array
        cout << " What output file do you want for paragraph " << j << "?" << endl; // Prompt user for output file
        cin >> outFileName; // User inputs new output file name

	    j = j+1; // Add 1 to j

	    outputFile.open(outFileName.c_str()); // Open output file

	    if(outputFile.fail()) // If output file fails to open
	        {
		        cout << "The output file cannot be opened!" << endl;
			    return 1; // Terminate
	        }
    
        output_letters(outputFile, count); // Output letter frequencies to output file

        outputFile.close(); // Close output file

        inputFile.close(); // Close input file

        cout << "Files updated successfully!" << endl;

        return 0;
	}
}
