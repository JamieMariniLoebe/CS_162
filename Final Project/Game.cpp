/****************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 12/01/2018
 * Description: This is the source file
 * for Game.
****************************************/

#include "Game.hpp"

Game::Game(Player *player) : player(player) {
    srand(time(NULL));

    Space *hprev;
    Space *hcurr;
    hcurr = hprev = NULL;
    for (int j = 0; j < SIZE ; ++j) {
        Space* n1 = new Space;
        if(hcurr == NULL){
            start = hcurr = n1;
        }
        else{
            hcurr = n1;
            hcurr->setTop(hprev);
            hprev->setBottom(hcurr);
        }
        Space* hprevTr = hprev;
        for (int i = 1; i < SIZE ; ++i) {
            Space* n = new Space;
            hcurr->setRight(n);
            n->setLeft(hcurr);
            hcurr = hcurr->getRight();
            if(hprevTr != NULL ){
                hprevTr = hprevTr->getRight();
                hcurr->setTop(hprevTr);
                hprevTr->setBottom(hcurr);
            }
        }
        hprev = n1;
    }
    end = hcurr;
    current = start;

}

/*****************************************
 * Description: This function displays
 * the map of the house and the players location.
*****************************************/

void Game::printMap(){
    Space* tr = start;
    Space* trv = start;
    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j < SIZE ; ++j) {
            cout<<tr->getLocation()->getName().substr(0,4);
            if(tr==current){
                cout<<"*";
            }
            cout<<"\t";
            tr = tr->getRight();
        }
        tr = trv->getBottom();
        trv = trv->getBottom();
        cout<<endl;
    }
}

/*****************************************
 * Description: This function checks if
 * the game has been won.
*****************************************/

bool Game::isWon() {
    return current == end && player->getNoOfItems() == 10;
}

/*****************************************
 * Description: This function checks
 * if the player has lost.
*****************************************/

bool Game::isLost() {
    return player->getHealth() == 0;
}

/*****************************************
 * Description: This function displays the
 * players health.
*****************************************/

void Game::displayHealth() {
    cout<<"Current Health : "<<player->getHealth()<<endl;
}

/*****************************************
 * Description: This function displays
 * what items the player has in their
 * container.
*****************************************/

void Game::displayItems() {
    cout<<"You have these items :";
    for (int i = 0; i < player->getNoOfItems() ; ++i) {
        cout<<player->getContainer()[i]<<",";
    }
    cout<<endl;
}

/*****************************************
 * Description: This function moves the 
 * players location in the house, and interacts
 * with items and monsters.
*****************************************/

void Game::makeMove(int c) {
    Space* prev= current;
    bool move = false;
    if(c==1){
        if(current->getTop() != NULL){
            current = current->getTop();
            move = true;
        }
        else{
            cout<<"Invalid Move"<<endl;
        }
    }
    else if(c==2){
        if(current->getBottom() != NULL){
            current = current->getBottom();
            move = true;
        }
        else{
            cout<<"Invalid Move"<<endl;
        }
    }
    else if(c==3){
        if(current->getLeft() != NULL){
            current = current->getLeft();
            move = true;
        }
        else{
            cout<<"Invalid Move"<<endl;
        }
    }
    else if(c==4){
        if(current->getRight() != NULL){
            current = current->getRight();
            move = true;
        }
        else{
            cout<<"Invalid Move"<<endl;
        }
    }

    if(current->getLocation()->isKey_required()){
        if(!player->isKeyAvailable(current->getLocation()->getKey())){
            move = false;
            current = prev;
            cout<<"Key not available, please choose a different move."<<endl;
        }
    }

    if(move){
        if(current->getLocation()->isHealthDrink()){
            cout<<"Got Health Drink :"<<current->getLocation()->getHealthGain()<<endl;
            int h = player->getHealth() + current->getLocation()->getHealthGain();
            current->getLocation()->setHealthDrink(false);
            player->setHealth(h);
        }
        if(current->getLocation()->isMonster()){
            cout<<"Hit by a monster with power :"<<current->getLocation()->getMonster_power()<<endl;
            int h = player->getHealth() - current->getLocation()->getMonster_power();
            current->getLocation()->setMonster(false);
            player->setHealth(h);
        }
        if(current->getLocation()->isIsItem()){
            cout<<"Found a item :"<<current->getLocation()->getItemAtLocation()<<endl;
            string item = current->getLocation()->getItemAtLocation();
            current->getLocation()->setIsItem(false);
            player->addItem(item);
        }
    }
}


