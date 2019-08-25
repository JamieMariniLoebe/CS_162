/***********************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 11/02/2018
 * Description: This is the main file for the
 * Fantasy Combat Game.
***********************************************/

#include <string>
#include <iostream>
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"


using std::cout;
using std::cin;
using std::endl;

void displayCharacterList() {
    cout<<"1.Vampire"<<endl;
    cout<<"2.Barbarian"<<endl;
    cout<<"3.Blue Men"<<endl;
    cout<<"4.Medusa"<<endl;
    cout<<"5.Harry Potter"<<endl;
}

Character* selectCharacter(){
    int input;
    do{
        displayCharacterList();
        cin>>input;
        if(input<1 || input>5){
            cout<<"Invalid choice !!. Please select again."<<endl;
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

void startGame(){
    Character *c1;
    Character *c2;
    cout<<"Please choose first character for the fight:"<<endl;
    c1 = selectCharacter();
    cout<<"Please choose second character for the fight:"<<endl;
    c2 = selectCharacter();
    c1->setInfo();
    c2->setInfo();
    int round = 1;

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

    if(c1->isDead()){
        cout<<c2->getName()<<" Wins !!"<<endl;
    }
    else{
        cout<<c1->getName()<<" Wins !!"<<endl;
    }

}

int main() {

    bool doContinue = true;
    do{
        cout<<"Starting fantasy combat game...."<<endl<<endl;
        startGame();

        int input;
        do{
            cout<<"1.Play Again"<<endl;
            cout<<"2.Exit the Game"<<endl;
            cin>>input;
            if(input<1 || input>2){
                cout<<"Invalid choice. Please enter a valid option."<<endl;
            }
        }while (input<1 || input>2);

        if(input == 2){
            doContinue = false;
        }

    }while(doContinue);

    return 0;
}


