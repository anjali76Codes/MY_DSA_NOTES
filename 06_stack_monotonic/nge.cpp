#include <bits/stdc++.h>
using namespace std;


vector<int> nextGreaterEle(vector<int>&arr){
  int n = arr.size();
vector<int>nge(n);
  stack<int>s;

  // 4, 5, 2, 25, 7, 8   n = 4
  for(int i = n-1; i>=0; i--){   // [ 5 ,25,25 ,-1 ,8 ,-1]
    while(!s.empty() && s.top()<=arr[i]){
      s.pop();
    }

    if(s.empty()) {
      nge[i] = -1;
    }
    else{
      nge[i] = s.top();
    }
    s.push(arr[i]);  // 8,7 -x //25 ,5  
   
  }
  
  return nge;
  
}

int main() 
{
  vector<int>arr = {4,5,2,25,7,8};
 vector<int>res = nextGreaterEle(arr);
  
  for(auto it: res){
    cout<<it<<" ";
  }
    return 0;
}