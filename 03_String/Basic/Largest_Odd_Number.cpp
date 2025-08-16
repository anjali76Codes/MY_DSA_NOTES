#include <bits/stdc++.h>
using namespace std;


// largest Odd Number in string 
 string largestOddNumber(string num) {
        // string ans= "";
        int n = num.length();
  
  
  // 5347
  for(int i = n-1; i>=0 ; i--){
   
    
    if((num[i]-'0') % 2 != 0){
      return num.substr(0 , i+1);
    }
    
  }
     

  return "";      
    }


int main() 
{
   string s = "5347";
  // int num = stoi(s);
   
  cout<< largestOddNumber(s);
  
    return 0;
}