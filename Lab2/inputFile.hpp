/*****************************************************
** Name: Jamie Loebe
** Date: 10-07-2018
** Description: This is the header for for inputFile.
**
*****************************************************/

#ifndef INPUTFILE_hpp
#define INPUTFILE_hpp

#include <stdio.h>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

void count_letters(ifstream &inputFile, int* count);

#endif
