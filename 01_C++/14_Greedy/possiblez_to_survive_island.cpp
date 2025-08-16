#include<bits/stdc++.h>
using namespace std;

int minimum_Days(int s , int n , int m){
    // Edge case: Cannot buy enough food even for one day
    if (m > n)
        return -1;

    int sunday = s / 7;
    int buying_days = s - sunday;
    int totalFood = s * m;
    int ans = 0;

    if (totalFood % n == 0) {
        ans = totalFood / n;
    } else {
        ans = totalFood / n + 1;
    }

    if (ans <= buying_days)
        return ans;
    else
        return -1;
}

int main()
{
    int s = 10;
    int n = 9;
    int m = 8;
    cout << minimum_Days(s, n, m);
    return 0;
}
