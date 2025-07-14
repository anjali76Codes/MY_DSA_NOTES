#include<bits/stdc++.h>
using namespace std;

int findDuplicateNum(vector<int>& arr){

  int j= arr.size()-1;
  for(int i =0; i<arr.size(); i++){
     if(arr[i] ==arr[j]){
    return arr[i];
    break;
  }
  }
 
  
  return -1;
}


int main (){
  
  vector<int> arr = {1,3,4,3,9};
  cout<<findDuplicateNum(arr)<<"";
  return 0;
}