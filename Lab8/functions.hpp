/****************************
 * Program Name: Lab 8
 * Author: Jamie Loebe
 * Date: 11/18/2018
 * Description: This is the 
 * header file for functions.
*****************************/

#ifndef FUNCTIONS_hpp
#define FUNCTIONS_hpp

#include <string>

class functions{

public:
    bool search(int *arr, int size, int target);
    void writing_array_to_file(int *arr, int size);
    void bubble_sort(int *arr, int size);
    bool binary_search(int *arr, int low, int high, int target);
    void reading_from_file(std::string filename, int *arr, int &size);

};

#endif
