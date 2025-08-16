/*
we are given the nth root and M-> integer number
we need to find the nth root of M
n = 3  M = 27
so the ans will be -> 3
in this we have to give the exact ans not floor value


*/

#include <bits/stdc++.h>
using namespace std;

int func(int mid , int n){
    long long ans = 1 ; 

    while(n>0){
        // when nth number is odd
        if(n%2 == 1){
            ans = ans * mid ;
            n = n-1 ;
            }
            else{
                mid = mid * mid ;
                n = n/2 ;
                }

    }
    return ans ;
}
  
// binary search
int Nth_Root(int M, int n)
{

    int low = 1, high = M;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n);
        if (midN == M)
        {
            return mid;
        }
        else if (midN < M)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int M;
    cin >> M;
    int n;
    cin >> n;
    cout << Nth_Root(M, n);

    return 0;
}