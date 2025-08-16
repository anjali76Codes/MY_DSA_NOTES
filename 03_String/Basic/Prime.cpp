#include <iostream>
using namespace std;

  bool isPrime(int n) {
        for(int i = 2 ; i<n ; i++){
         if(n%i==0)
          return false;
        }
    return true;  
    }

int main() 
{
  
int number = 200;
int res = isPrime(number);
if(res == 1){
  cout<<"True";
}
else{
  cout<<"False";
}
    return 0;
}