/********************************************
** Program name: Langton's Ant
** Author: Jamie Loebe
** Date: 10-08-2018
** Description: This is the header file for 
the Board source file.
********************************************/

#ifndef BOARD_h
#define BOARD_h
#include <iostream>
#include <vector>

using std::vector;

class Board {

public:
    vector<vector<char> > myBoard;
    int numberOfRows, numberOfColumns; // Declare variables for rows and columns of 2d array
    void displayBoard();
    Board();
    Board(int, int); // --> Use constructor to initialize
    char getColorOfSquareOnBoard(int x, int y); // returns board
    void setColorOfSquareOnBoard(int x, int y, char Color); // returns board
    int getRows();
    int getColumns();
};

#endif

