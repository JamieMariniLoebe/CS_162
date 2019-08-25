#include <iostream>

#include "Zoo.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {


    Zoo *z = new Zoo();

    cout << "Welcome to the Game!" << endl;

    int n;
    cout << "Please enter how many tigers you want: ";
    cin >> n;
    for(int i=0;i<n;i++) {
        z->addTiger(new Tiger(1, 10000, 0, 2000, 50));
    }

    cout << "Please enter how many penguins you want: ";
    cin >> n;
    for(int i=0;i<n;i++) {
        z->addPenguin(new Penguin(1, 1000, 0, 1000, 10));
    }

    cout << "Please enter how many turtules you want: ";
    cin >> n;
    for(int i=0;i<n;i++) {
        z->addTurtle(new Turtle(1, 10000, 0, 5, 5));
    }

    //Game starts for the user
    z->playGame();

    return 0;
}
