#include<bits/stdc++.h>
using namespace std ;

// Problem Description:
// Given an integer array `nums`, remove the duplicates in-place such that each element appears only once.
// Return the new length of the array after removal of duplicates. 
// The order of elements may be changed,  but the relative order of the unique elements should be preserved. Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.



// sorted array 
int removeDuplic(vector<int> &nums){
    int i = 0;  
    for(int j = 1; j<nums.size(); j++){
        if(nums[j] != nums[i]){
             i++;
             // shifiting the elements to one place left 
            nums[i] = nums[j];
           
        }
    }

    return i+1 ; 

}






// not in sorted 
int removeDuplicates(vector<int>& nums) {
    unordered_set<int> s ;  
    int idx = 0 ;  

    for(int i = 0; i < nums.size(); i++) {

        if(s.find(nums[i]) == s.end()) {
            s.insert(nums[i]);  
          
            nums[idx++] = nums[i];
        }
    }

    return idx;  
}

int main(){
    // Input array with duplicates 
    vector<int> v = {7,3,7,1,2};
    vector<int> v1 = {1,1,2,2,3,4,5,6,};
  
    // Call the function to remove duplicates
    // int res = removeDuplicates(v);
    int res1 = removeDuplic(v1);
    
    // Output the new length of the array with unique elements
    cout << res1 << endl;
  
    return 0;
}

/*
Input:
[1, 1, 4, 2, 5, 3, 1, 3, 3]

Output:
5

Explanation:
The array after removing duplicates could look like [1, 4, 2, 5, 3] (order can vary), and the new length is 5.
*/

