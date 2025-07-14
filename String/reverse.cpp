#include<bits/stdc++.h>
using namespace std;

void reverse(string &s1){
 int i = 0;
 int j = s1.length()-1;

 while(i<=j){
    swap(s1[i] , s1[j]);
    i++;
    j--;
 }
}




int main()
{

    string s1 = "Hello";
    // reverse(s1);


    reverse(s1.begin() , s1.end());
    for( char c: s1){
        cout<<c<<"";
    }

return 0;
}