#include <bits/stdc++.h>
using namespace std;

int main()
{

// easiest method 
 int N;
    cout << "Enter the number to count the digits: ";
    cin >> N;
int count = int(log10(N)+1);

    // int count = 0;
    // int N;
    // cout << "Enter the number to count the digits: ";
    // cin >> N;
    // while (N > 0)
    // {
    //     count++;
    //     N = N / 10;
    // }

    cout << "The Count of digits is : " << endl
         << count;







    return 0;
}