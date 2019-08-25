/********************************************************
** Program Name: Langton's Ant
** Author: Jamie Loebe
** Date: 10-08-2018
** Description: This is the source file for Board. It contains
** the functions from the board header file.
********************************************************/

#include "Board.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

/**********************************************************
** Description: This function displays the board by taking
** a for loop nested within another for loop and displaying
** each square on the board.
**
**********************************************************/

void Board::displayBoard()
{
    for (int i = 0; i < numberOfRows; i++) // for loop for rows
    {
        for (int j = 0; j < numberOfColumns; j++) // for loop for columns
        {
            cout << myBoard[i][j] << " "; // display board
        }
        cout << endl;
    }
}

/*********************************************************
** Description: This constructor randomly assigns colors to
** each square on the board.
**
**
*********************************************************/

Board::Board(int rows, int columns)
{
    srand((unsigned)time(0)); // Sets starting state of random function
    numberOfRows = rows;
    numberOfColumns = columns;

    int number = 0;

    for (int i = 0; i < numberOfRows; i++) // creates blank board
    {
        vector<char> newRow; 
        for (int j = 0; j < numberOfColumns; j++)
        {
            newRow.push_back(' ');
        }
        myBoard.push_back(newRow);
    }

    for (int i = 0; i < numberOfRows; i++) // assigns random color to every square in the board
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            number = rand() % 100;
            if (number < 50)
            {
                myBoard[i][j] = '#';
            }
            else
            {
                myBoard[i][j] = ' ';
            }
        }
    }
}

/*********************************************************
** Description: This function returns the color of the squar
** at 'x' row and 'y' column coordinate on board.
**
**
*********************************************************/

char Board::getColorOfSquareOnBoard(int x, int y)
{
    return myBoard[x][y];
}

/*********************************************************
** Description: This function sets the color of of the square
** at 'x' row and 'y' column coordinate on the board.
**
**
*********************************************************/

void Board::setColorOfSquareOnBoard(int x, int y, char Color)
{
    myBoard[x][y] = Color;
}

/*********************************************************
** Description: This function gets and returns the number
** of rows in the board.
**
**
*********************************************************/

int Board::getRows()
{
    return numberOfRows;
}

/*********************************************************
** Description: This function gets and returns the number
** of columns
**
**
*********************************************************/

int Board::getColumns()
{
    return numberOfColumns;
}

/*********************************************************
** Description: This default constructor sets the board
** to a default size of 8x8 and assigns each square a color.
**
**
*********************************************************/

Board::Board() // default constructor
{
    srand((unsigned)time(0));
    numberOfRows = 8;
    numberOfColumns = 8;
    myBoard = myBoard;
    int number = 0;

    for (int i = 0; i < numberOfRows; i++)
    {
        std::vector<char> temp;
        for(int j=0; j < numberOfColumns; j++)
        {
            temp.push_back(' ');
        }
        myBoard.push_back(temp);
    }

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            number = rand() % 100;
            if (number < 50)
            {
                myBoard[i][j] = '#';
            }
            else
            {
                myBoard[i][j] = ' ';
            }
        }
    }
}

