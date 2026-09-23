#include<bits/stdc++.h>
using namespace std;

string ReverseWords(string &s){
    int n = s.length();
    string ans ="";
    string temp="";

    // The man
    for(int i = n-1 ; i>=0 ; i--){
        if(s[i]==' '){
            reverse(temp.begin(), temp.end());   // eht
            ans = ans+temp;
            ans.push_back(' ');
            temp = "";
        }

        else{
            temp.push_back(s[i]);
        }
    }
        // for the first word there is no any . so in this case we have to reverse it directly and need to add in the ans
        reverse(temp.begin() , temp.end());
        ans = ans+temp;
        return ans;
}   

int main()
{

    string s = "The name of person is anjali";
    string res =ReverseWords(s);

    for(auto it: res){
        cout<<it<<"";
    }


return 0;
}