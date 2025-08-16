#include <iostream>
using namespace std;


   string intToRoman(int num){
// 58
    int arr[13] = {1000, 900, 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9,5, 4, 1};
    string romansVal[13] = {"M" , "CM", "D", "CD", "C" , "XC", "L", "XL", "X","IX", "V", "IV","I"};


    // 58 - 50 = 8  ans = L
    // 8-5 = 3  ans = LV
    // 3-1 = 2  ans LVI
    // 2-1 = 1 ans LVII
    // 1- 1 = 0 ans LVIII

    string ans= "";
    while(num>0){
       for (int i=0 ; i<13; i++){
        if(num >=arr[i]){
 num -= arr[i];
 ans +=romansVal[i];
break;
        }
       }
    }

    return ans;

   }

      

int main() 
{
 int num = 58;
  cout<< intToRoman(num);
    return 0;
}