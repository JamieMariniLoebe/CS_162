/**************************************************************
** Program Name: Matrix Calculator
** Author: Jamie Loebe
** Date: 09-28-2018
** Description: This is the source file for the determinant 
** header file. It contains the function for performing the 
** matrix determinant calculation.
**************************************************************/

#include <iostream>
#include "determinant.hpp" // Include the determinant header file

/***************************************************************
** Description: This function calculates the determinant for a
** matrix the 2x2 size or 3x3 size. If the matrix is 2x2, it runs
** the calculation. If it is not, it skips this if statement and
** runs the calculation for a matrix of the 3x3 size.
***************************************************************/

int determinant(int *myArray[3], int matrixSize)
{
    if (matrixSize == 2) // If matrix is size of 2x2, it runs the calculation and returns the answer.
    {
        return (myArray[0][0] * myArray[1][1]) - (myArray[0][1] * myArray[1][0]);
    }
    else // If matrix is not 2x2, it runs three separate calculations, and returns the answer of a 
    // fourth calculation. 
    {
        double firstEq = myArray[0][0] * ((myArray[1][1] * myArray[2][2]) - (myArray[1][2] * myArray[2][1]));
        double secondEq = myArray[0][1] * ((myArray[1][0] * myArray[2][2]) - (myArray[1][2] * myArray[2][0]));
        double thirdEq = myArray[0][2] * ((myArray[1][0] * myArray[2][1]) - (myArray[1][1] * myArray[2][0]));
        return firstEq - secondEq + thirdEq;
    }
}



