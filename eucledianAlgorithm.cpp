// Eucledian Algorithm

// when for loop -> Complexity will be O(max(a,b))
// when division -> Complexity will be log(min(a,b))
/*
Eucledian Algorithm -

            gcd(a , b){
                if(b==0){
                    return a;
                }
                gcd(b , a % b);
            }

*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    int num1, num2;
    cout << " Enter the 2 number of which you want to find the Greatest Common Divisor " << endl;
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << " G.C.D of " << num1 << " and " << num2 << " is " << result;
    return 0;
}