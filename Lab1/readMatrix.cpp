/***********************************************************************
** Program Name: Matrix Calculator
** Author: Jamie Loebe
** Date: 09-27-2018
** Description: This is the source file for readMatrix. This file
** allows for the user to input the values for the matrix in each coordinate
************************************************************************/

#include "readMatrix.hpp" // Include header file

#include <iostream> // Include this since we are inputting and outputting data.

using std::cout;
using std::cin;
using std::endl;

/***********************************************************************
** Description: This function loops through the rows and columns and asks
** the user to input the value for each coordinate. Stops looop when 
** matrixSize exceeds 2 or 3, depending on size of Matrix. This function
** is void and thus does not return any data.
***********************************************************************/

void readMatrix(int *myArray[3], int matrixSize)
{
    for (int i=0; i < matrixSize; i++) // for loop through the rows
    {
        for (int j=0; j < matrixSize; j++) //for loop through the columns
        {
            cout << "What is the value of row " <<  i + 1 << " and column " << j + 1 << endl;
            cin >> myArray[i][j]; // Ask user for values of matrix.
        } // Since computer starts from 0, we add 1 to the matrix row/column
    }
}
