#include<bits/stdc++.h>
using namespace std;

 vector<int> mergeTwoSortedArray(vector<int>&arr1 ,int m , int n , vector<int>&arr2){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while(i>=0 && j>=0){
        if(arr1[i]<arr2[j]){
            arr1[k] = arr2[j];
            j--;
            k--;
        }
        else {
         arr1[k] = arr1[i];
         i--;
         k--;
        }
    }

   

    while(j>=0){
        arr1[k] = arr2[j];
        j--;
        k--;
    }
    return arr1;
 }

int main(){
// merge two sorted array
vector<int>arr1 = {1,3,5,7};
vector<int>arr2 = {2, 4,6,8};
int m = arr1.size();
int n = arr2.size();

mergeTwoSortedArray(arr1, m , n, arr2);
for(int i = 0; i<m+n; i++){
    cout<<arr1[i]<<" ";
}


    return 0;
}