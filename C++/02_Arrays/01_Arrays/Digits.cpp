#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count;
    while(n>0){
count++;
n = n/10;
cout<<"The separated digits is "<<n<<endl;
    }
    cout<<count;
    return 0;
}





// Sum of digits and separation of last digits
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    while(n>0){
int lastdigit = n%10;
sum+=lastdigit;
n = n/10;

cout<<"The separated digits is: "<<lastdigit<<endl;
    }
cout<<"The sum of digits is:"<<sum<<endl;
    return 0;
}





// To reverse the number
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<n<<endl;
   int reverse = 0;
    while(n>0){
int lastdigit = n%10;
 reverse = reverse*10+lastdigit;
n = n/10;
    }
cout<<"The given number in reverse is :"<<reverse<<endl;
    return 0;
}





//  To find sum of this 1-2+3-4...n
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum =0 ;
    for(int i =1; i<=n; i++){
        if(i%2==0){
            sum+=i;
        }
        else{

            sum-=i;
        }
    }


     cout<<"The sum is :"<<sum<<endl;
    return 0;

}















