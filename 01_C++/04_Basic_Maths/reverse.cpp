#include<bits/stdc++.h>
using namespace std;

int main()
{

    int N  ;
    cin>>N;
    int revnum = 0 ;
    while(N>0){
        int lastdigit = N%10;
        
        revnum  = (revnum*10) +lastdigit;
          N = N/10;
      
       
    }

     cout<<revnum;

return 0;
}