#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int revnum = 0;
    int copynum = n ;
    while (n > 0)
    {
        int lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }

    if (revnum == copynum)
    {
        cout << "palindrome";
    }

    else
    {
        cout << "Given no. is not a palindrome";
    }

    return 0;
}