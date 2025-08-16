// Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

#include<bits/stdc++.h>
using namespace std;

   int singleNumber(vector<int>& nums){
    int xorr = 0;

    // For example, if nums = [2, 1, 2], the process would look like:
        // Step 1: xorr = 0 ^ 2 -> xorr = 2
        // Step 2: xorr = 2 ^ 1 -> xorr = 3
        // Step 3: xorr = 3 ^ 2 -> xorr = 1 (final result)
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