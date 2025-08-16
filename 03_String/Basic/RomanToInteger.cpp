#include <iostream>
using namespace std;


int value(char ch ){

    switch(ch){
        case 'I' : return 1 ;
        case 'V' : return 5 ;
        case 'X' : return 10 ;
        case 'L' : return 50 ;
        case 'C' : return 100 ;
        case 'D' : return 500 ;
        case 'M' : return 1000 ;

        default : return 0 ;
    }
        
    }


// ix

    int romanToInt(string s) {

        int n = s.length ();
        int sum = 0 ; 
        for(int i = 0 ; i<n ; i++){
            // fist roman is storing in new vaiable and only one char is in the string 
            char c = s[i] ; 

            // when more than one character in the string so to get its value we are depend on next value as well 
            // i+1<n -> there is next ele exist 
            if(i+1 < n  && value(c)  < value(s[i+1])){
                sum = sum - value(c);
            }

            else{
                sum = sum+ value(c);
            }
            
        }

        return sum ;

        
    }

int main() 
{
  string s = "XLMVII";
  cout<< romanToInt(s);
    return 0;
}