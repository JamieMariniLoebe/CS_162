/***********************************
 * Program Name: Lab 8
 * Author: Jamie Loebe
 * Date: 11/18/2018
 * Description: This is the main
 * file for Lab 8.
 *
***********************************/

#include <iostream>
#include <fstream>
#include "functions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;

/**********************************
* Description: This function searches
* for the target value.
**********************************/
bool search(int *arr, int size, int target);

/*********************************
* the user for the filename and 
* then proceeds to write the array
* to the file.
**********************************/
void writing_array_to_file(int *arr, int size);

/***********************************
* Description: This function performs
* a bubble sort on the array.
***********************************/
void bubble_sort(int *arr, int size);

/************************************
* Description: This function performs
* a binary search of the array.
************************************/
bool binary_search(int *arr, int low, int high, int target);

/***********************************
* Description: This function reads
* in from the file.
***********************************/
void reading_from_file(string filename, int *arr, int &size);


int main() {

    std::string file_n1 = "realFile.txt";
    std::string file_n2 = "begin.txt";
    std::string file_n3 = "middle.txt";
    std::string file_n4 = "end.txt";

    std::ofstream file1; // Open file stream
    file1.open("realFile.txt"); // Open file 1
    file1 << "11 12 13 14 15 16 17 18 19" << endl; // Write to File 1
    file1.close();

    ofstream file2;
    file2.open("begin.txt");
    file2 << "0 11 12 13 14 15 16 17 18 19" << endl;
    file2.close();

    ofstream file3;
    file3.open("middle.txt");
    file3 << "11 12 13 14 15 0 16 17 18 19" << endl;
    file3.close();

    ofstream file4;
    file4.open("end.txt");
    file4 << "11 12 13 14 15 16 17 18 19 0" << endl;
    file4.close();

    std::ifstream inputFile; // Input file stream object
    int SIZE = 11;
    int nums1[SIZE], nums2[SIZE], nums3[SIZE], nums4[SIZE];
    int size1, size2, size3, size4;

    reading_from_file(file_n1, nums1, size1);
    reading_from_file(file_n2, nums2, size2);
    reading_from_file(file_n3, nums3, size3);
    reading_from_file(file_n4, nums4, size4);

    cout << "Simple Search Results: " << endl;

    int target;
    cout << "What is the target value? ";
    cin >>  target;

    cout << file_n1 << ": ";
    if(search(nums1, size1, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    cout << file_n2 << ": ";
    if(search(nums2, size2, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    cout << file_n3 << ": ";
    if(search(nums3, size3, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    cout << file_n4 << ": ";
    if(search(nums4, size4, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    cout << endl;

    bubble_sort(nums1, size1);

    bubble_sort(nums2, size2);

    bubble_sort(nums3, size3);

    bubble_sort(nums4, size4);

    cout << "Binary Search Results: " << endl;

    //Using binary search
    cout << "What is the target value? ";
    cin >>  target;

    cout << file_n1 << ": ";
    if(binary_search(nums1, 0, size1-1, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }


    cout << file_n2 << ": ";
    if(binary_search(nums2, 0, size2-1, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    cout << file_n3 << ": ";
    if(binary_search(nums3, 0, size3-1, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    cout << file_n4 << ": ";
    if(binary_search(nums4, 0, size4-1, target)) {
        cout << "Target value found" << endl;
    }
    else {
        cout << "Target value not found" << endl;
    }

    return 0;
}



bool search(int *arr, int size, int target) {
    for(int i=0;i<size;i++) {
        if(target == arr[i])
            return true;
    }
    return false;
}

void writing_array_to_file(int *arr, int size) {
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

void bubble_sort(int *arr, int size) {

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

bool binary_search(int *arr, int low, int high, int target) {
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

void reading_from_file(string filename, int *arr, int &size) {
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

