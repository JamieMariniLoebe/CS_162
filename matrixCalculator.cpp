/*******************************************************************************
** Program Name: Matrix Calculator
** Author: Jamie Loebe
** Date: 09/30/2018
** Description: This program displays a 2x2 or 3x3 matrix and then calculates
** the determinant of said matrix.
*******************************************************************************/

#include "readMatrix.hpp"
#include "determinant.hpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int rowCount=0;
int myDeterminant;

int main()
{

    int rowCount = 0; // Initialize rowCount to 0
    int myDeterminant; // Declare myDeterminant variable

    cout << "Please choose the  size of the matrix, 2x2 or 3x3: ";
    cin >> rowCount; // Ask user for size of matrix, and store input in rowCount

    int **myMatrix = new int *[rowCount]; // Ptr to a ptr myMatrix, dynamically allocate memory for matrix size.

    for (int i = 0; i < rowCount; ++i) // run for loop for dynamically allocated memory
    {
        myMatrix[i] = new int[rowCount];
    }

    /*******************************************************************
    ** Description: the readMatrix function asks the user to input each
    ** value for every coordinate in the matrix. It is void, and does
    ** not return any value, but stores each user inputted value in the
    ** respective coordinate within the matrix.
    *******************************************************************/
    readMatrix(myMatrix, rowCount); // call readMatrix function, set myMatrix and rowCount as parameters

    /*************************************************************************
    ** Description: The determinant function calculates the determinant
    ** of the matrix and then returns the final answer.
    **************************************************************************/

    myDeterminant = determinant(myMatrix, rowCount); // set the myDeterminant variable equal to the call of determinant function

    for (int i=0; i < rowCount; i++) // Run for loop for rows
    {
        for (int j=0; j < rowCount; j++) // Run for loop for columns
        {
            cout << myMatrix[i][j] << " "; // Output and display the full matrix
        }
        cout << endl;
    }

    cout << "The determinant of this matrix is: " << myDeterminant << endl; // Display the determinant of the matrix

    for(int i = 0; i < rowCount; i++) // Run for loop
    {
        delete myMatrix[i]; // Deallocate memory
    }

    delete [] myMatrix; // Deallocate memory

    return 0;
}
