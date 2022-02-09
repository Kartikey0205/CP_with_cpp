
/*
Fermad Litle's Theorem

choose
    a < number , a !=0 , a!= 1;
    then,

        -----------------------------------------
        |                                       |
        |    a^(number - 1) mod number = 1      |
        |                                       |
        -----------------------------------------

        then number is a prime number

But in some cases like when number = 511 for specific value of a = 123 it gives false positive menas it is  not a prime number but it still saying that it is a prime number , So solve this problem we are supposed to generate random value of a so that for many cases it repeat itself




GENERATING RANDOM NUMBER
Math.random()   ------> its value ranges from 0 to 1

Math.random() * (Number - 3) ----> it become 0 if number is 3 so we want our a to greater than 0 and 1 also so


a = Math.random()*(Number - 3) + 2     -----> minimum value of a is equals to 2
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int generateRandomNumber(int num)
{
    srand(time(0)); // for non repeating genreate number
    int a;
    // a = rand() * (num - 3) + 2;
    a = ((rand() / RAND_MAX) * (num - 3)) + 2; // divide by RAND_MAX bcoz want in range between 0 -1
    return a;
}
int isPrimeVia_Fermad_Little_Theorem(int number, int steps)
{
    while (steps > 0)
    {
        int a = generateRandomNumber(number);
        if ((int(pow(a, (number - 1))) % number) == 1)
        {
            steps--;
            return 1;
        }
        else
        {
            steps--;
            return 0;
        }
    }
    return -1;
}
int main()
{
    int num, steps;
    cout << "Enter the number" << endl;
    cin >> num;
    cout << "Enter the number of steps you want to check your result " << endl;
    cin >> steps;
    int prime = isPrimeVia_Fermad_Little_Theorem(num, steps);
    if (prime == 0)
    {
        cout << "Not a PRIME NUMBER " << endl;
    }
    else if (prime == 1)
    {
        cout << "PRIME NUMBER" << endl;
    }
    else
    {
        cout << "Can't say" << endl;
    }

    return 0;
}
