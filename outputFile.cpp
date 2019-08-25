/***********************************************
** Name: Jamie Loebe
** Date: 10-07-2018
** Decription: This is the source file for Outputfile.
************************************************/

#include "outputFile.hpp"

#include <fstream>
#include <string>

/**************************************************
** Description: This function prompts the user 
** for the output file name, then outputs the 
** frequencies of each letter to the output file
** the user input.
**************************************************/


void output_letters(ofstream &outputFile, int* count)
{
    int j;

    for (j = 0; j < 26; j++) // For loop through the alphabet/ASCII
    {
        outputFile << (char)(j+97) << ": " << count[j] << std::endl << std::endl; // Output to the file the
        // characters related to numbers 97 through 123 in ASCII
    }
}

