#include<bits/stdc++.h>
using namespace std;


   string reverseWords(string &s) {
 int n = s.length();
    string ans = ""; 
     // reverse the whole string  - got the correct position 
        reverse(s.begin() , s.end());


for(int i=0; i<n; i++){

   


        // I have to reverse the each word char individually so first indentify word
      
      string word = "";
      while(i< n && s[i] !=' '){
        word += s[i];
        i++ ;
      }

      // reverse the word to get the correct form 
      reverse(word.begin() , word.end());

      // add word to ans
   
      if(word.length() >0){
        ans += " " +word;
      }

}
return ans.substr(1) ;      
        
    }

int main()
{

    string w = "the sky is blue    ";
   string res =  reverseWords(w);
    for(char ch : res){
        cout<<ch<<" ";
    }

return 0;
}