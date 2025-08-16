#include <bits/stdc++.h>
using namespace std;


// remove outermost parentheses

string removeOutermostParentheses(string &s){
  int n = s.length();
  vector<char> p;
string ans = "";
  for(int i =0 ; i<n ; i++){
    if(s[i] == '('){
   // s[i] -> is my outer parentheses or not
   if(!p.empty()){  // p is only empty when first or outer parentheses is there
     ans+= s[i];
   }
     p.push_back(s[i]);
      
    }
    
    else if (s[i] ==')'){
      p.pop_back();   
      
      // after pop check weather the popped ele is your outer or not if not then add in the ans 
      if(!p.empty()){
        ans+= s[i];
      }
      
    } 
    
    
   
  
    
  }
  
 return ans;
}

int main() 
{
   string s = "(()())";
   
   string res = removeOutermostParentheses(s);
   for(char ch: res){
     cout<<ch<<"";
   }
    return 0;
}