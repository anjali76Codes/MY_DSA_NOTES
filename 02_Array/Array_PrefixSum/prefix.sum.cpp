//prefix sum   
// PS: store prefix sum without using extra array to store 

#include <bits/stdc++.h>
using namespace std;


vector<int> prefixSum(vector<int> &arr){
    // 5 7 11 18 27
    for(int i = 1; i<arr.size() ; i++){
        arr[i] = arr[i-1]+arr[i];

    }

return arr;
}


int main(){

vector<int> arr = {5, 2, 4, 7, 9};
vector<int>res = prefixSum(arr);
for(auto &it: res){
    cout<<it<<" ";
}



    return 0 ;
}