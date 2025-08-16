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





// part II
string reverseWords(string &s) {
    // Step 1: Split the string by dots, ignoring empty splits
    vector<string> words;
    string word = "";
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '.') {
            // If we reach a dot and have a word accumulated, add it to the list
            if(!word.empty()) {
                words.push_back(word);
                word = "";
            }
        } else {
            // Accumulate the characters of the word
            word += s[i];
        }
    }

    // Don't forget to add the last word if there's any remaining
    if(!word.empty()) {
        words.push_back(word);
    }

    // Step 2: Reverse the words vector
    reverse(words.begin(), words.end());

    // Step 3: Join words with a single dot
    string ans = "";
    for(int i = 0; i < words.size(); i++) {
        ans += words[i];
        if(i != words.size() - 1) {
            ans += "."; // Add dot only between words
        }
    }

    return ans;
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