 
/*
Kadane's Algorithm Idea:
The key idea behind Kadane’s Algorithm is to keep track of two things while iterating through the array:

current_sum: The maximum sum of the subarray ending at the current index.

max_sum: The global maximum sum encountered so far.

Steps:
Initialization:

Set max_sum to a very small value (negative infinity) to ensure it can be replaced with any number from the array.

Set current_sum to 0 (since we are calculating sums as we go).

Iterate through the array:

For each element, decide whether to:

Add the element to current_sum (this means continuing with the existing subarray).

Start a new subarray with the current element (this means dropping the previous subarray).

Update current_sum to the maximum of the two choices:

current_sum = max(current_sum + arr[i], arr[i])

Update max_sum:

After each iteration, update max_sum to be the maximum of max_sum and current_sum:

max_sum = max(max_sum, current_sum)

End of iteration: After the loop, max_sum will hold the maximum sum of any contiguous subarray.

Time Complexity:
O(n): Kadane’s algorithm runs in linear time, as it only makes one pass through the array.

*/




#include<bits/stdc++.h>
using namespace std;


 int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxSum = INT_MIN;
        int sum = 0;
        
        for(int i =0; i<arr.size(); i++){
            sum +=arr[i];
            
            if(sum > maxSum){
                maxSum = sum;
            }
            
            if(sum<0){
                sum =0;
            }
        }
        
        return maxSum;
        
    }



vector<int> maxSubarray(vector<int> arr) {
int maxi = INT_MIN;
int sum=0;
int ansStart = -1 ;
int  ansEnd = -1;
int start;
for(int i=0; i<arr.size(); i++){

    if(sum ==0 ){
        start = i;
    }
   
    sum+= arr[i];
    if(sum > maxi){
        maxi = sum;
        ansStart = start;
        ansEnd = i;
        
    }
    
    if(sum <0){
        sum = 0;
    }

}
return {ansStart , ansEnd};

}
    

int main()
{
    vector<int>arr = {2, 3, -8, 7, -1, 2, -3};

    cout<<maxSubarraySum(arr)<<endl;
    vector<int> indices = maxSubarray(arr);
    cout << "Start Index: " << indices[0] << ", End Index: " << indices[1] << endl;
    
    // Print the actual maximum subarray
    cout << "Maximum Subarray: ";
    for (int i = indices[0]; i <= indices[1]; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

return 0;
}


