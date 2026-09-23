#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> getSubArrays(vector<int>& arr) {
        vector<vector<int>> ans;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                // Create a subarray from arr[i] to arr[j] and push it into ans
                vector<int> subarray(arr.begin() + i, arr.begin() + j + 1);
                ans.push_back(subarray);
            }
        }
        return ans;
    }

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
   
    vector<vector<int>> subarrays = getSubArrays(arr);
    cout << "Subarrays are: \n";
    for (const auto& subarray : subarrays) {
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
