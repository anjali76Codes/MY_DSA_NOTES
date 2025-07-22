/*
find square root of n
n is given we have to find the square root value(floor value) of the n

*/

#include <bits/stdc++.h>
using namespace std;


// linear search 

int sqrt(int n){
    int ans = 1;
    for(int i = 0 ; i<n ; i++){
        if(i*i <= n){
            ans  = i ;
    }
    else{
        break;
    }
    } 
    return ans ;
}

int floor_sqrt(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = (mid * mid);

        if (val<= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

      
    }

      return high;
}

    int main()
    {

        int n;
        cin >> n;
        cout << sqrt(n);
        cout << floor_sqrt(n);

        return 0;
    }