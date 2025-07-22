#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int armstrong_sum = n;
    int sum = 0;

    while (n > 0)
    {
        int lastdigit = n % 10;

        sum += (lastdigit * lastdigit * lastdigit);
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