#include<bits/stdc++.h>
using namespace std;

char firstUniqueChar(string & s){
    int n = s.length();
    string ans = "";

    unordered_map<char, int>mp;
    queue<int>q;

    for(int i = 0 ;i<n ; i++){
        if(mp.find(s[i]) == mp.end()){
          q.push(s[i]);
        }

        mp[s[i]]++;


        while(q.size()>0 && mp[s[q.front()]]>1){
            q.pop();
        }
    }

    return q.empty()? -1 : q.front();
}

int main()
{

    string s = "leetcode";
 char res =  firstUniqueChar(s);
 cout<<res<<" ";
    

return 0;
}