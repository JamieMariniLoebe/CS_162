/*************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/17/2018
 * Description: This is the main file 
 * for Project 4.
*************************************/

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "LinkedList.hpp"


using std::cout;
using std::cin;
using std::endl;

/******************************
* Description: This function
* displays the characters.
******************************/

void displayCharacterList() {
    cout<<"1.Vampire"<<endl;
    cout<<"2.Barbarian"<<endl;
    cout<<"3.Blue Men"<<endl;
    cout<<"4.Medusa"<<endl;
    cout<<"5.Harry Potter"<<endl;
}

/******************************
* Description: This function 
* allows user to select their
* character.
******************************/

Character* selectCharacter(){
    int input;
    do{
        displayCharacterList();
        cin>>input;
        if(input<1 || input>5){
            cout<<"Invalid option, please select again."<<endl;
        }
    }while (input<1 || input>5);

    switch (input){
        case 1:
            return new Vampire();
        case 2:
            return new Barbarian();
        case 3:
            return new BlueMen();
        case 4:
            return new Medusa();
        case 5:
            return new HarryPotter();
    }
}

/******************************
* Description: This function 
* runs the main game for the user.
******************************/

void play_game(LinkedList *team1, LinkedList *team2) {
    LinkedList *loser = new LinkedList(); // Loser container
    Character *c1, *c2; // pointers for chars
    int score1 = 0, score2 = 0; // initialize scores and rounds
    int rounds = 1;

    while(true) {

        int round = 1;

        if(team1 == NULL || team2 == NULL) {
            break;
        }

        c1 = team1->getHead();
        c2 = team2->getHead();

        if(c1 == NULL || c2 == NULL) {
            break;
        }

        while( !c1->isDead() && !c2->isDead()){
            cout<<" ---------- Round "<<round<<" ------------"<<endl;

            cout<<"Attacker type :"<<c1->getName()<<endl;
            cout<<"Defender type :"<<c2->getName()<<endl;
            cout<<"Defender armor :"<<c2->getArmor()<<endl;
            cout<<"Defender strength :"<<c2->getStrength()<<endl;
            int att_roll1=c1->attack();
            c2->defend(att_roll1);
            if(c2->isDead()){
                break;
            }
            cout<<endl;
            cout<<"Attacker type :"<<c2->getName()<<endl;
            cout<<"Defender type :"<<c1->getName()<<endl;
            cout<<"Defender armor :"<<c1->getArmor()<<endl;
            cout<<"Defender strength :"<<c1->getStrength()<<endl;
            int att_roll2=c2->attack();
            c1->defend(att_roll2);

            round++;
            cout<<endl;
        }

        cout << "\nRound " << rounds << " Team A " << c1->getName() << " vs Team B" << c2->getName() << ", ";

        if(c1->isDead()){
            if(c2 != NULL) {
                cout<<c2->getName()<<" Won !!"<<endl;
                loser->insertAtHead(c1);
                c2->recovery();
                team2->insertAtTail(c2);
            }
            score2 += 1;
            score1 -= 2;
        }
        else if(c2->isDead()){
            if(c1 != NULL) {
                cout<<c1->getName()<<" Won !!"<<endl;
                loser->insertAtHead(c2);
                c1->recovery();
                team1->insertAtTail(c1);
            }
            score1 += 1;
            score2 -= 2;
        }
        else {
            break;
        }
        cout << endl;
        rounds++;
    }

    cout << endl;
    cout << "Team A score: " << score1 << endl;
    cout << "team B score: " << score2 << endl;

    if(score1 > score2) {
        cout << "Team A wins the Game!" << endl;
    }
    else if(score2 > score1) {
        cout << "Team B wins the Game!" << endl;
    }
    else {
        cout << "There is tie between the teams!" << endl;
    }

    cout << endl;

    char y;
    cout << "Enter y to show contents of loser pile otherwise enter n: ";
    cin >> y;
    y = tolower(y);
    if(y == 'y') {
        cout << "The loser pile is: ";
        loser->printList();
    }
    cout << endl;
}

/***************************************
* Description: This function begins the
* game and prompts user for their choices.
* It also creates the containers.
***************************************/

void startGame(){

    Character *c1;
    Character *c2;

    int f1, f2;
    cout << "Enter the number of fighters for Team 1: ";
    cin >> f1;
    cout << "Enter the number of fighters for Team 2: ";
    cin >> f2;

    LinkedList *team1 = new LinkedList();
    LinkedList *team2 = new LinkedList();
    string character, name;

    for(int i=0;i<f1;i++) {
        cout << "Please choose type of character for Team A: " << endl;
        c1 = selectCharacter();
        cout << "Please enter the name of character for Team A: ";
        cin >> name;
        c1->setInfo();
        c1->setName(name);
        team1->insertAtTail(c1);
    }

    for(int i=0;i<f2;i++) {
        cout << "Please choose type of character for Team B: " << endl;
        c2 = selectCharacter();
        cout << "Please enter the name of character for Team B: ";
        cin >> name;
        c2->setInfo();
        c2->setName(name);
        team2->insertAtTail(c2);
    }

    cout << "The tournament has begun!" << endl << endl;
    play_game(team1, team2);
    cout << "The tournament has ended!" << endl << endl;
}

int main() {

    bool doContinue = true;
    do{
        cout<<"Let's begin the fantasy combat game!"<<endl<<endl;
        startGame();

        int input;
        do{
            cout<<"1.Play Again"<<endl;
            cout<<"2.Exit the Game"<<endl;
            cin>>input;
            if(input<1 || input>2){
                cout<<"Invalid option, please select again."<<endl;
            }
        }while (input<1 || input>2);

        if(input == 2){
            doContinue = false;
        }

    }while(doContinue);

    return 0;
}

