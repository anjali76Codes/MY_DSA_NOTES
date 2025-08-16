#include <bits/stdc++.h>
using namespace std;


bool checkEqualArrays(vector<int>&arr1 , vector<int>&arr2){
 
 
 if(arr1.size() == arr2.size());
  unordered_map<int, int> m1 , m2;
  
  for(int x: arr1){   // O(n)
    m1[x]++;
  }
  
  
   for(int x: arr2){   // O(n)
    m2[x]++;
  }
  
  
  if(m1 == m2){   // O(n)
    return true;
  }
 
 
 // overall tc: O(n) and sc: O(n)
  return false;
}

int main() 
{
  
  vector<int>arr1 = {1,3,2,1,2};
  vector<int>arr2 = {3,2, 1, 3, 1};
  
  cout<<checkEqualArrays(arr1, arr2);
  
  
    return 0;
}