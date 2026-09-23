#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;  // n = 1634
    int armstrong_sum = n;
    int sum = 0;
    int digits = 0;

    int temp = n;
    while(temp>0){  // 1634 -  in total 4 digits
        digits++;
        temp /= 10;

    }

    while (n > 0)
    {
        int lastdigit = n % 10;  // 4 

        sum += pow(lastdigit, digits);
        n = n / 10;
    }

    if (sum == armstrong_sum)
    {
        cout << "Armstrong sumber";
    }
    else
    {
        cout << "Not an armstrong sumber";
    }

    return 0;
}