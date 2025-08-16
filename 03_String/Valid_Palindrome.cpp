/*
Problem  125 : here you have to convert all uppercase into lowercase and and then remove non alpha numerice and check wheather the given string is a valid palindrome or not 

*/




#include <bits/stdc++.h>
using namespace std;

bool isAlphaNum(char ch){
    if(ch >='0' && ch<='9' || tolower(ch) >='a' && tolower(ch)<='z'){
        return true ;
    }

    return false;
}


    bool isPalindrome(string s) {
        int st = 0 ;
        int end = s.length()-1;

        while(st<end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;
            }

            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }

if(tolower(s[st]) != tolower(s[end])){
    return false ;
}

st++;
end--;

        }

        return true ;
        
    }

int main()
{

    string s;
    cout << "Enter the string : ";
    getline(cin, s);

    cout << isPalindrome(s) << " ";

    return 0;
}