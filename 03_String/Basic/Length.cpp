#include <iostream>
using namespace std;

 int lengthString(string &s) {
   
   int length = 0 ;
   for(int i = 0 ; i<s.length() ; i++){
     length++ ;
   }
        
  return length;      
    }

int main() 
{
  
  string s = "AnjaliIshika";
  cout<<lengthString(s);
   
    return 0;
}