/*

Intuition:
The goal of this algorithm is to find the majority element in an array, which is defined as the element that appears more than n / 2 times, where n is the size of the array.

Key Idea:
The algorithm works in two phases:

Candidate Selection:

Start with no candidate and a counter initialized to 0.

Traverse the array:

If the counter is 0, pick the current element as the candidate and set the counter to 1.

If the current element matches the candidate, increment the counter.

If the current element doesn't match the candidate, decrement the counter.

The element at the end of this pass is the candidate for majority (but we can't be sure yet).

Verification:

After determining a candidate, count its occurrences in the array.

If the count is greater than n / 2, then it's the majority element.

Otherwise, there is no majority element.

Why It Works:
The key observation is that the counter behaves like a balance. Every time a new element different from the current candidate is encountered, the counter is decreased. When a majority element exists, its count will always outweigh the counter resets, leading to it being the candidate at the end of the first phase.

Time Complexity:
O(n): We only make two passes over the array (one for selection, one for counting).

Space Complexity: O(1): Only a couple of variables are used, regardless of the input size.

*/





#include<bits/stdc++.h>
using namespace std;

int MajorityEle(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    int cnt = 1;
    // int majorityElement = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            cnt++;
        } else {
            if(cnt > n / 2) {
                return arr[i - 1];
            }
            cnt = 1; // Reset counter for the new element
        }
    }

    // Final check for the last element in case it's the majority element
    if(cnt > n / 2) {
        return arr[n - 1];
    }

    return -1; // No majority element found
}



// optimal approach 
int MajorityElement(vector<int>& arr){
  // moore's voting algorithm 
  // intuition 
  int cnt = 0;
  int ele ; 
  for(int i =0; i<arr.size() ;i++){
    // no ele is selected (i.e ele is null)
    if(cnt==0){
      cnt =1;
      ele = arr[i];
      
    }
    
    else if(arr[i] == ele){
      cnt++;
    }
    else{
      cnt--;
    }
  }
  
  int cnt1 =0;
  for(int i =0; i<arr.size(); i++){
    if(arr[i] == ele) cnt1++;
  }
  
  if(cnt1> (arr.size()/2)){
    return ele ;
  }
    
    return -1; // No majority element found
}





int main (){
    vector<int> arr = {2, 2, 1, 1, 1, 1, 2};
    cout << MajorityEle(arr) << endl; // Should return 1 as it appears more than n/2 times
    return 0;
}
