// Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include<bits/stdc++.h>
using namespace std;

   int singleNumber(vector<int>& nums){
    int xorr = 0;
 
  for(int i =0; i<nums.size(); i++){
 xorr = xorr^nums[i];

  }

  return xorr;
 

       
    }

int main()
{
    vector<int> arr = {2, 2 ,1};




cout<<singleNumber(arr)<<" ";

return 0;
}