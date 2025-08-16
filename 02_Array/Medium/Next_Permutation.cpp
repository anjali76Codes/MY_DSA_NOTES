/*
Next Permutation Intuition:
Find the pivot (breaking point):

Look for the first number from the right that is smaller than the number next to it. This is the pivot point.

Why? Because this is the place where the sequence stops being in increasing order and will need to change to get the next permutation.

Find the number to swap with:

After finding the pivot, look for the smallest number greater than the pivot but located after the pivot in the array.

Why? We need to make the smallest possible change that results in a greater permutation.

Reverse the sequence after the pivot:

Once you swap, the portion of the sequence after the pivot is in descending order, so we reverse it to make it the smallest possible arrangement.

Why? To ensure the next permutation is the smallest possible number greater than the original one.

Edge case (largest permutation):

If there is no pivot (i.e., the list is in descending order), it means the sequence is already the largest possible permutation. In this case, reverse the entire list to get the smallest permutation.
*/


#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // we will find the pivot -> breaking point from backward and satisfy the (current ele < its next ele)
        for(int i=n-2 ; i>=0 ; i-- ){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }


// if no pivot so return lowest -> just reverse the array
        if(pivot == -1){
            reverse(nums.begin() , nums.end());
            return;
        }



// 2. traverse from backward and when condition is satisfy end el is > pivot then swap 
        for(int i= n-1 ; i>pivot ; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i] , nums[pivot]);
                break;
            }
        }

// break to get the next permuation 
        reverse(nums.begin() +pivot+1 , nums.end());
    }


int main()
{

    vector<int> arr = {1,3,2};
    nextPermutation(arr);
    for(int i : arr){
        cout<<i<<" ";
    }

return 0;
}

