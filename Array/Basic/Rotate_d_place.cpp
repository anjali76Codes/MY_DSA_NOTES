#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr , int k) {  
    int n = arr.size();
    k = k%n ;
    if (k == 0) return;
    
   
// first index -> +1  and 2nd index -1 
reverse(arr.begin() , arr.begin()+k);  // 0 to k-1 
reverse(arr.begin()+k , arr.end());   // k to n-1 
reverse(arr.begin() , arr.end());    // 0 to n-1 
    
  
}

int main() {
    int k ;
    cin>>k;
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Rotate the array
    rotate(v, k);
    
    // Print the rotated array
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}
