/*******************************************************
 * Program Name: Lab 5
 * Author: Jamie Loebe
 * Date: 10/24/2018
 * Description: This is the main.cpp file for the 
 * Lab 5 program
*******************************************************/

#include "triNum.hpp"
#include "sumArray.hpp"
#include "reverse.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    int choice;
    int size = 0;
    int n = 0;
    int array[] = {};

    cout << "Welcome to the recursive program. Please follow the prompts below." << endl;
    
    cout << "1. Print a string in reverse." << endl;
    cout << "2. Sum an array of integers." << endl;
    cout << "3. Get triangular number of an integer." << endl;
    cout << "4. Quit." << endl;

    cin >> choice; // Prompt user for choice

    //Run through if statements depending on choice.
    if (choice == 1)
    {
        std::string str;
        cout << "Input string to reverse: " << endl;
        cin.ignore();
        getline(std::cin, str);
        cout << reverseStr(str) << endl << endl;
    	cout << " Press 1 to print string" << endl;
	cin >> choice;
    }

    else if (choice == 2)
    {
        cout << "Please enter the size of the array: " << endl;
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            cout << "Please input the elements of the array: " << endl;
            cin >> array[i];
        }
        cout << sumArray(array, size);
        cout << endl;
	return 0;
    }

    else if (choice == 3)
    {
        cout << "Please enter an integers for which you want its triangular number: " << endl;
        cin >> n;

        cout << "The triangular number of " << n << " is " << triNum(n) << endl;
        cout << endl;
    }

    else if (choice == 4)
    {
        cout << "Program terminating...";
        cout << endl;
	return 0;
    }

}

