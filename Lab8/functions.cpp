/**************************************
 * Program Name: Lab 8
 * Author: Jamie Loebe
 * Date: 11/18/2018
 * Description: This is the source file
 * for functions.
**************************************/


#include "functions.hpp"

#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

bool functions::search(int *arr, int size, int target) {
    for(int i=0;i<size;i++) {
        if(target == arr[i])
            return true;
    }
    return false;
}

void functions::writing_array_to_file(int *arr, int size) {
    std::ofstream file;
    std::string filename;
    cout << "Enter the file name to output the sorted values: ";
    cin >> filename;
    file.open(filename.c_str());
    for(int i=0;i<size;i++) {
        file << arr[i] << " ";
    }
    file.close();
}

void functions::bubble_sort(int *arr, int size) {

    int temp;
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    writing_array_to_file(arr, size);

    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

}

bool functions::binary_search(int *arr, int low, int high, int target) {
    if(low <= high) {
        int mid = (low + high)/2;
        if(target == arr[mid]) {
            return true;
        }
        else if(arr[mid] > target) {
            return binary_search(arr, low, mid-1, target);
        }
        else {
            return binary_search(arr, mid+1, high, target);
        }
    }
    return false;
}

void functions::reading_from_file(std::string filename, int *arr, int &size) {
    ifstream inputFile;
    inputFile.open(filename.c_str());
    int i = 0;
    while(inputFile >> arr[i])
    {
        i++;
    }
    size = i;
    inputFile.close();
}

