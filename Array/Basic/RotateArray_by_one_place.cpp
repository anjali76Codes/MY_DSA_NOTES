#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr) {  
    int n = arr.size();
    if (n <= 1) return;
    
    int temp = arr[n - 1];
    
    // Shift all elements to the right by one position
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[0] = temp;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Rotate the array
    rotate(v);
    
    // Print the rotated array
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}
