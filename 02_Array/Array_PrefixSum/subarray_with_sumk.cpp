#include <bits/stdc++.h>
using namespace std;


// subarraysum (i+1 , j) = prefixSum(j) - prefixSum(i)

int checkSubarrayWithSumk(vector<int>&arr, int k ){
    int n = arr.size();
    // create an arr to store the prefix sum 
    vector<int>preSum(n , 0);
preSum[0] = arr[0];
int cnt = 0;
for(int i = 1; i<n ; i++){
    preSum[i] = preSum[i-1]+arr[i];
}



// create hashmap to store the freq of the prefixSum elements 
unordered_map<int, int> m;
for(int j =0; j<n ;j++){
    if(preSum[j] ==k){
        cnt++;
    }
    int diff = preSum[j] - k;
    if(m.find(diff) != m.end()){
        cnt += m[diff];
    }


    if(m.find(preSum[j]) == m.end()){
        m[preSum[j]] = 0;
    }

    m[preSum[j]]++;
}

return cnt;
}




int main(){

vector<int> arr = {9 , 4, 0,20, 3, 10, 15};
int k = 33;
cout<<checkSubarrayWithSumk(arr,k);



    return 0;
}