#include<bits/stdc++.h>
using namespace std;


// 1,2,3,1,1,1,1
// logic if sum k is given then logic is I have to check presum : if presum = 9 and k = 3 then look for the left side for 6 if present then cal the len 
int longestSubarraySumk(vector<int>&arr, int k){
    int n = arr.size();
    unordered_map<int , int>m;
    int sum = 0;
    int maxLen =0;

    //1. take the prefix sum and take the max len when sum ==k 
    for(int i = 0; i<n ; i++){
        sum += arr[i];
        if(sum ==k){
        maxLen = max(maxLen , i+1);
        }
    
        //2 . if not above then apply reverse engineering 
        // for eg. sum = 9 and k = 3 so rem would be 6 so check in map for the 6 if present then cal len and at the end by updating return maxlen
        int rem = sum -k; 
        if(m.find(rem) != m.end()){
            int len = i-m[rem];
            maxLen = max(maxLen , len);
        }


        // if one sum is added then no need to update the other sum 
        // for eg. 2, 0, 0 , 3 so in this case first sum = 2 and in case of 0 it is 2 so if we take 2, 0 ,0 that means in map it becomes  2 ,2  which is actually not return the longest subarray 
        if(m.find(sum) == m.end()){
            m[sum] = i;
        }

    }


return maxLen;


}




// optimal approach 
int longestSub(vector<int>&arr, int k){
    int n = arr.size();
    // two pointer approach - sliding window 

    int left , right = 0;
    int maxLen = 0;
    int sum = arr[0];

while(right<n){
right++;
sum+= arr[right];

// but what if sum exceed with the k 
while(left<=right && sum>k){
    // when exceed shrink from the left side 
    sum -= arr[left];
    left++;
}

if(sum ==k){
    maxLen = max(maxLen , right-left+1);
}


   }
return maxLen;
}

int main()
{

    vector<int> arr = {1,2,3,1,1,1,1};
    int k = 6;
    cout<<longestSubarraySumk(arr, k)<<endl;
    cout<<longestSub(arr, k);

return 0;
}