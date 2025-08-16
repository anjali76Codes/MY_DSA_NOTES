#include<bits/stdc++.h>
using namespace std;

bool checkRotations(string &s1 , string &s2){
    if(s1.length() != s2.length()){
        return false; 
    }

    string concatStr = s1 + s1;

    // Check if s2 is a substring of concatStr
    if(concatStr.find(s2) != string::npos){
        return true;
    }

    return false;
}

int main()
{

    string s1  = "ABC";
   string s2 = "BCA";

   cout<<checkRotations(s1, s2)<<endl;


return 0;
}