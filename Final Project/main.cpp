/*****************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 11/29/2018
 * Description: This is the main file for
 * Final Project.
*****************************************/

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
#include "Space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void displayMenu();
int getInput();

int main() {

    cout << "Welcome to The Monster Game" << endl << endl;
    cout << "---------------Goal of the Game---------------" << endl << endl;
    cout << "1.Goal of this game will be to go from the top-left corner to bottom right-corner of the house." << endl;
    cout << "2.Each location may or may not have an item like a sword or shield, or key, etc" << endl;
    cout << "3.Player needs to collect at least 10 items before reaching final location" << endl;
    cout << "4.Maximum capacity of the container which can store the items is 15" << endl;
    cout << "5.Player will initially get 25 health points. At any location, total health should not go less than or equal to 0." << endl;
    cout << "6.Player will loose some health if player encounters a monster at a location" << endl;
    cout << "7.Player might also get some health points at a location which will add up to total health." << endl;
    cout << "8.Current location is marked by * at the end" << endl;
    cout << "9.Certain location might require key to enter." << endl;
    cout << endl;

    Player *p;
    p = new Player("Jamie");
    Game game(p);

    do{
        game.displayHealth();
        game.displayItems();
        game.printMap();
        cout << endl;
        displayMenu();
        int c = getInput();
        game.makeMove(c);

    }while (!game.isWon() && !game.isLost());

    if(game.isLost()){
        cout<<"!!! You have lost!!!"<<endl;
    }
    if(game.isWon()){
        cout<<"!!! You win !!!"<<endl;
    }
    return 0;
}

/*************************************
 * Description: This function displays
 * menu for the user.
*************************************/

void displayMenu(){
    cout << "Select the direction of movement :" << endl;
    cout << "1.Up" << endl;
    cout << "2.Down" << endl;
    cout << "3.Left" << endl;
    cout << "4.Right" << endl;
}

/*************************************
 * Description: This function takes in
 * the users input.
*************************************/

int getInput(){
    int n;
    do{
        cout << "Enter your choice :";
        cin >> n;
    }while (n<1 | n>4);
    return n;
};
