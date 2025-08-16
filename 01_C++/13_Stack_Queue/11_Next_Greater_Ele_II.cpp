/*
This algorithm work for circular array.  We can just traverse the array twice. We actually run a loop 2*N times, 

and the method is same if there is any next greater ele take that and if not then -1 

Approach : 
- need a iterate over an array from 0 to n-1 
- need to check the next greater ele 
from i+1 to i+N-1(because we are searching from the next ele)

- in this loop we have to find the index to check in circular way also 
j%N - index 
- if(arr[index] > arr[i])
    - means we have the next ele is greater so simply put this into our ans and break the loop
- return nge(ans)


Optimal Approach : 



#Time complexity : O(N2)
#Space complexity : O(N)
*/



#include<bits/stdc++.h>
using namespace std;

vector<int> NextGreater(vector<int>&arr ){
 
    int N = arr.size();
    vector<int>nge(N,-1);

for(int i = 0 ; i<N; i++){
    for(int j = i+1 ; j<i+N-1 ; j++){
        // give the index (hypothetically the array double to size and % give the index in circular manner )
        int index = j%N;
        if(arr[index] > arr[i]){
            nge[i] = arr[index];
            // since we have to only find one next greater to it that's why we are breaking the loop here and first move to the next ele(ith index) then check for next greater ele(jth index)
            break;
        }
    }
}
return nge;

}



vector < int > Next(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }

int main()
{
    vector<int> arr = {2, 10, 12, 1, 11};
    
    vector<int>ans = NextGreater(arr);
     for (int num : ans)
    {
        cout << num << " ";
    }


return 0;
}