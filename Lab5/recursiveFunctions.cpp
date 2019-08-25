/********************************************
 * Program Name: Lab 5
 * Author: Jamie Loebe
 * Date: 10/24/2018
 * Description: This is the source file for 
 * each of the three recursive functions: 
 * reverse, sumArray and triNum.
********************************************/

#include "reverse.hpp"
#include "sumArray.hpp"
#include "triNum.hpp"

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


/***********************************************
 * Description: This function returns the string
 * if its length is only 1. Else, it returns
 * the reverse of the string itself.
************************************************/

std::string reverseStr(std::string str)
{
    std::string str2; // Declare string str2

    if(str.length() == 1) // If string length is 1
    {
        return str; // Return string
    }

    str2 = str.at(str.length()-1) + reverseStr(str.substr(0,str.length()-1)); // set str2 to the reverse of string
    return str2; // return reverse of original string, now in variable str2
}


/***************************************************
 * Description: This function returns the element
 * of the array if its size is 1. Else, it calculates
 * the sum of the array.
****************************************************/


int sumArray(int *arr, int size)
{
    if (size == 1) // If array size is 1
    {
        return arr[0]; // return array element 0
    }

    return arr[0] + sumArray(arr + 1, size - 1); // Else, return sum of array
}


/*****************************************************
 * Description: This function returns 0 if the integer
 * taken as a parameter is 0, else it returns the 
 * triangular number of the integer that was taken
 * as the parameter.
*****************************************************/

int triNum(int n)
{
    if (n == 0) // If n is 0
    {
        return 0; // return 0
    }

    return n + triNum(n - 1); // Else, return triangular number of n

}


