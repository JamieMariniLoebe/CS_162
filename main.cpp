/****************************************************
** Program Name: Langton's Ant
** Author: Jamie Loebe
** Date: 10-08-2018
** Description: This is the main file for the program
** Langton's Ant. It creates a board on which an Ant (*)
** moves. Each 'square' on the board is either a '#' color
** or a ' ' color.
****************************************************/

#include "Board.hpp"
#include "Ant.hpp"

#include <iostream>
#include <climits>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*************************************************
** Description: This function sets input validation.
** It tells the program to return true if the input
** is valid and false if not.
*************************************************/

bool validateRange(int minimum, int maximum,int num)
{
    if(minimum<= num && num <=maximum){
        return true;
    }
    return false;
}

/***************************************************
** Description: This function sets input validation.
** It tells the program to return true if the input
** belongs to set of possible values, and false if not.
***************************************************/

bool validateRange(char c,char validChar[],int arrSize)
{
    for(int i=0; i<arrSize; i++)
        {
            if(c==validChar[i])
            {   
                return true;
            }
    }
    return false;
}


/*****************************************************
** Description: This function takes integer input from
** the user. If user inputs anything exept integer, it reprompts
** the user for new input and discards previous input.
** It validates new user  input if valid, and reprompts 
** again if not.
******************************************************/

int takeIntInput(string message,int minimum, int maximum) {
    bool cond;
    int n;
    do
    {
        cout << message << endl;
        cin >> n;
        cond = cin.fail();
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(!cond && !validateRange(minimum,maximum,n))
        {
            cond = true;
        }
    }
    while(cond );
    return n;
}


/***********************************************************
** Description: This function takes character input from the
** user. If user inputs anything excep char, it will reprompt
** the user for new input and discard previous input. Also, it
** validates if the char input is valid per options,
** and if not, reprompts again.
***********************************************************/


char takeCharInput(string message, char validChar[],int arrSize) 
{
    bool cond;
    char c;
    do
    {
        cout << message << endl;
        cin >> c;
        cond = cin.fail();
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(!cond && !validateRange(c,validChar,arrSize))
        {
            cond = true;
        }

    }
    while(cond);
    return c;
}


int main()
{

    char validChar[] = {'N','E','W','S'};

    int startGame;
    char startPos;
    char direction;
    int numOfRows, numOfColumns, numOfSteps, startRow, startColumn;
    
    // Beginning of program and Menu.
    cout << "Welcome to Jamie's Langton's Ant simulator. Please follow the below prompts" << endl;

    cout << endl;
    cout << endl;

    cout << "1. Start Langton's Ant Simulation \n";
    cout << "2. Quit" << endl;

    startGame = takeIntInput("Please enter your choice",1,2);
    while (startGame == 1)
    {
        cout << "Perfect! Please type 'C' to begin" << endl;  // to confirm that user wants to play
        cin >> startPos;

        if (startPos == 'C')
        {
            cout << "Ok! Let's get started. Please input the following parameters " << endl;
            cout << "as you wish the board to be designed: " << endl;

            // Prompt user for input, prompt again if input invalid.
            numOfRows = takeIntInput("Please input the number of rows for the board: ",1,INT_MAX);

            numOfColumns = takeIntInput("Please input the number of columns for the board: ",1,INT_MAX);

            numOfSteps = takeIntInput("Please input the number of steps for the simulation: ",1,INT_MAX);

            startRow = takeIntInput("Please input the starting row of the ant: ",0,numOfRows-1);

            startColumn= takeIntInput("Please input the starting column of the ant: ",0,numOfColumns-1);

            direction=takeCharInput("Please input the starting direction of the ant (N, W, S, or E): ",validChar,4);

            // If user wants to quit.
            while (startGame == 2)
            {
                cout << "Program terminated" << endl;
                return 1;
            }

            int numberOfRows = numOfRows;
            int numberOfColumns = numOfColumns;
            Board newBoard(numberOfRows, numberOfColumns);  // make a board of the size numberOfRows X numberOfColumns

            // display the board after the ant has moved according to the rules the
            Ant ant(direction,startRow,startColumn,numOfSteps,numberOfRows,numberOfColumns,newBoard);
            cout<<"Board state before simulation :"<<endl;

            newBoard.displayBoard(); // Display board before move
            cout<<"--------------------"<<endl<<endl;
            int i = 1;
            cout<<"Board state After simulation : "<<endl; 
            // Display board after move.
            while (ant.makeMove(newBoard))
            {
                cout<<"State after move : "<<i<<endl;
                newBoard.displayBoard();
                i++;
                cout<<"------------"<<endl;
            }
        }

        cout << "1. Play Again \n";
        cout << "2. Quit" << endl;

        cin >> startGame;
    }
    return 0;
}
