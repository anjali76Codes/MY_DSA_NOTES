#include<iostream>
using namespace std;
int main(){
    char vowels[5]; 


    // ampersand is used to print reference value 
    // step: first user input in elements block and cause due to use of ampersand ->& it provide same memory location to both the memory elements as well as vowels


    for(char &elements:vowels){
        cin>>elements;
    }
    for(int i =0 ; i<5;i++){
        cout<<vowels[i]; // so here it's give in output whatever is stored in elements memory
    }
    return 0;
}





// 2.To find maximum elements in given Array
int main(){
int arr[]={10,23,56,78,98,12,45,166};

int max = arr[0];
int smax = arr[0];
int tmax = arr[0];
for(int i=1; i<8;i++){
if(arr[i]>max){
    tmax = smax;
    smax = max;
    max = arr[i];
}


else if(arr[i]>tmax && arr[i]!= smax && arr[i]!=max){
    tmax = arr[i];
}
}


cout<<"The maximum elements in given array is:"<<max<<endl;
cout<<"The Second maximum elements in given array is:"<<smax<<endl;
cout<<"The Third maximum elements in given array is:"<<tmax<<endl;
return 0;

}








