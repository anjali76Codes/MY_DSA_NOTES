#include<bits/stdc++.h>
using namespace std;


string removeOccurrences(string &s, string part) {

      while(s.length ()> 0 && s.find(part) <s.length()){
        s.erase(s.find(part) , part.length());
      }

      return s;
    }

int main()
{

    string s;
    cout<<"Enter the string: ";
    getline(cin, s);

    string part;
    cout<<"Enter the part: ";
    getline(cin, part);
    removeOccurrences(s,part);
    for(char ch: s){
        cout<<ch<<"";
    }

return 0;
}