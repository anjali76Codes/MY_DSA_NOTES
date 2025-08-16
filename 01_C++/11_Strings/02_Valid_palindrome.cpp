/*
valid palindrome 
A23?$c32a
by removing the special charactres check start to end 
steps :
1. initialize start and end 
2. while start < end
3. check condition


*/


#include<bits/stdc++.h>
using namespace std;


bool isAlphaNumeric(char ch){
    if(ch>='0' && ch<='9' || tolower(ch >= 'a' && ch<='z')){
        return true;
    }
return false ;
}

bool isPalindrome(string s){

    int start = 0  , end = s.length()-1 ;
    while(start < end){
        // first remove the special characters - by checking if it is alphanumeric or not
        if(!isAlphaNumeric(s[start])){
            start++ ;
            continue ; 
        }

        if(!isAlphaNumeric(s[end])){
            end-- ;
            continue ;
        }


        if(tolower(s[start]) != tolower(s[end])){
            return false ;
        }

        start++;
        end--;
}
return true;
}


int main()
{
    string s;
    getline(cin, s);
    cout<<isPalindrome(s);



return 0;
}