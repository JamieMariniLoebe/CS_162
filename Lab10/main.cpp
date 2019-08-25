/******************************************
 * Program Name: Lab 10
 * Author: Jamie Loebe
 * Date: 11/27/2018
 * Description: This is the main file for Lab 10.
*******************************************/

#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void markTime();
double getTime();
int fibonacci (int n);
int iter_fibonacci(int n);

int main()
{
    cout << "N--Recursive_time--Iterative_time" << endl;

    for(int i = 10; i < 1000; i = i+1)
    {
        markTime();

        int rec = fibonacci(i); // Recursive

        double recursive_time = getTime(); // Recursive time

        markTime();

        int iter = iter_fibonacci(i); // Iterative

        double iter_time = getTime(); // Iterative time

        cout << i << ", " << recursive_time << ", " << iter_time << endl; // Output time
    }

    return 0;
}

/*****************************
 * Description: This function
 * initializes the int variable
 * start to the clock function,
 * which returns the processor
 * time consumed by the program
 * itself. Citation: http://www.cplusplus.com/reference/ctime/clock/
*****************************/

void markTime()
{
    int start = clock();
}

/*****************************
 * Description: This function
 * returns the time elapsed.
*****************************/

double getTime()
{
    int start;
    return ((clock() - start) / (double) CLOCKS_PER_SEC);
}

/*****************************
 * Description: This function
 * iterates through if statements 
 * and returns accordingly. If 
 * n is greater than 1, it returns 
 * the fibonacci equation.
*****************************/

int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }

    else if (n==1)
    {
        return 1;
    }
    else
    {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

/*****************************
 * Description: Iterate through
 * for fibonacci sequence.
*****************************/

int iter_fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c;

    for (int i=2; i<=n; i++)
    {
        c = a+b;
        a=b;
        b=c;
    }
    return c;
}
