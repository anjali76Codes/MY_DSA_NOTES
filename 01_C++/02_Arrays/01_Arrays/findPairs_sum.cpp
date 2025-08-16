#include<iostream>
using namespace std;
int main(){
    int n,pair=0;
    int arr[10] = {1,5,7,9,8,5,0,4};
    cout<<"Enter the number:"<<endl;
    cin>>n;
for(int i =0; i<8; i++){
    for(int j = i+1; j<8;j++){
        for(int k= j+1; k<8; k++){
    if(arr[i]+arr[j]+arr[k]==n){
pair++;

    }

}

    }
    
}
    cout<<"Total pair is:"<<pair<<endl;

    return 0;
}