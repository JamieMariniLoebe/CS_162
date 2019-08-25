/*************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/21/2018
** Description: This is the Building
** header file
*************************************/
#ifndef BUILDING_hpp
#define BUILDING_hpp

#include <string>

using std::string;

class Building {
private:
    std::string name; // Name of building
    double size; // Size of building
    std::string address; // Address of building

public:
    Building(); // Default constructor
    Building(std::string n, double s, std::string a); // Parameterized constructor

    void setName(std::string n); // Set name
    std::string getName(); // Get name

    void setSize(double s); // Set size
    double getSize(); // Get size

    void setAddress(std::string a); // Set address
    std::string getAddress(); // Get address
};

#endif

