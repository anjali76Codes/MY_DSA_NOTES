/*prefix sum   Check if we can partition the array into two subarrays with equal sum. More formally, check that the prefix sum of a part of the array is equal to the suffix sum of rest of the array.

*/
#include <bits/stdc++.h>
using namespace std;


bool partition(vector<int> &arr){
    int t_sum = 0;
    int pre_sum = 0;
    int suff_sum;
    for(int i = 0; i<arr.size() ; i++){
        t_sum+= arr[i];
    }


    for(int i = 0; i<arr.size() ; i++){
       pre_sum+= arr[i]; 
       suff_sum = t_sum-pre_sum;
       if(suff_sum == pre_sum){
        return true;
       }       
    }

return false;
}


int main(){

vector<int> arr = {6,2,4,3,1};
cout<< partition(arr);




    return 0 ;
}