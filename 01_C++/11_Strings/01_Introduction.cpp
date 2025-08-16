/*
palindrome
*/

#include<bits/stdc++.h>
using namespace std;



// madam -> true 
bool isPalindrome(string s){
    string str = s;
    reverse(s.begin() , s.end());
    if(str== s){
        return true;
    }
    return false;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<isPalindrome(s);

return 0;
}