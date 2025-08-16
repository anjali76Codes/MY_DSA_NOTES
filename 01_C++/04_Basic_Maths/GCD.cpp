#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a, b;
    cin >> a ;
    cin>>b;
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        if (b > a)
        {
            b = b % a;
        }
        if (a == 0)
        {
            cout << "GCD :" << b;
        }
        if (b == 0)
        {
            cout << "GCD :" << a;
        }
    }

    return 0;

}