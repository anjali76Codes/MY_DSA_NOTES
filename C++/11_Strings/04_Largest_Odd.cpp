/*
Largest Odd in a string
string s = '3542786'
odd identity is : in last it contains this : 1/3/5/7/9

so start from end id that num is odd or not that first odd to till oth index is the largest odd in a string 
we we are calculate num is odd or not we need integer but in string we have character so convert it into the integer 
'7' - '0' -> 7 

time compelxity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

string Find_Largest_Odd(string s){
    int n = s.length();
    for(int i  = n-1 ; i>=0 ; i--){
        if((s[i] - '0') %2 != 0){
            return s.substr(0, i+1);
        }
    }
    return "";
}

int main()
{

    string s ;
    getline(cin, s);
    cout<<Find_Largest_Odd(s);

return 0;
}