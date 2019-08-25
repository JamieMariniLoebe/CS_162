/******************************************
 * Program Name: Lab 9
 * Author: Jamie Loebe
 * Date: 11/24/2018
 * Description: This is the main file.
*****************************************/

#include <iostream>
#include <queue>
#include <list>
#include <cstdlib>
#include <stack>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::queue;
using std::list;
using std::stack;
using std::string;

string palindrome(string str);
void create_palindrome();
void test_buffer();

int main(){

    cout << "Welcome. Please choose an option : "<<endl;
    cout<<"1.Create a palindrome"<<endl;
    cout<<"1.Test a buffer"<<endl;

    int option;
 
    while(!(cin >> option) || !(option==1 || option==2))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Please enter valid input: ";
    }

    if(option==1){
        create_palindrome();
    }
    else if(option==2){
        test_buffer();
    }
    return 0;
}

/*************************************
* Description: This function creates 
* the stack and stores the char. Then
* it removes it in reverse order. 
*************************************/

string palindrome(string str){
    stack<char> stk;
    for (int i = 0; i < str.length() ; ++i) {
        stk.push(str[i]);
    }

    string res = str;
    while (!stk.empty()){
        res=res+stk.top();
        stk.pop();
    }
    return res;
}

/*************************************
* Description: This function takes in
* user input and creates a palindrome.
*************************************/

void create_palindrome(){
    string input;
    cout << "Enter the string for palindrome: ";
    cin >> input;
    cout << palindrome("hello") << endl;
}

/*************************************
* Description: This function prompts
* user for input and runs the buffer
* simulation.
*************************************/

void test_buffer(){
    int rounds, percentPush, percentPop, num, percent, status_push, status_pop;
    double avg=0, a_prev;
    queue<int,list<int> > que, temp;
    srand (time(NULL));

    cout << "Please input the number of rounds for simulation: ";
    while(!(cin >> rounds))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Please enter valid input: ";
    }
    cout<<"Please input the percentage chance to put a random number at the end of buffer: ";
    while(!(cin >> percentPush))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nPlease enter valid input: ";
    }
    cout<<"Please input the percentage chance to take out number from the front of buffer: ";
    while(!(cin >> percentPop))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Please enter valid input: ";
    }
    for(int i=1;i<=rounds;i++)
    {
        status_push=0;
        status_pop=0;
        a_prev=avg;
        num=rand()%1000+1;
        percent=rand()%100+1;
        if(percent<=percentPush)
        {
            que.push(num);
            status_push++;
        }
        percent=rand()%100+1;
        if(percent<=percentPop && !que.empty())
        {
            que.pop();
            status_pop++;
        }
        temp=que;
        cout<<"\nRound "<<i<<endl;
        if(status_push && status_pop)
            cout<<"Both push & pop triggered.\n";
        else if(status_push)
            cout<<"Only push triggered.\n";
        else if(status_pop)
            cout<<"Only pop triggered.\n";
        else
            cout<<"Neither push nor pop triggered.\n";
        cout<<"Elements of the queue from front are: ";
        while(!temp.empty())
        {
            cout<<temp.front()<<".";
            temp.pop();
        }

        cout << endl;
        cout << "The length of the buffer after round "<< i <<" is: "<< que.size() << endl;;
        avg=(a_prev*(i-1)+que.size())/i;
        cout <<"Average length of the queue afer round "<< i <<" is: " << avg << endl << endl;
    }
}
