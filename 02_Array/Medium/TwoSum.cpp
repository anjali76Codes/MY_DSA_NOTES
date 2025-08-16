#include <bits/stdc++.h>

using namespace std;

bool twoSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    // Two pointer approach
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return true;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return false;
}

int main() {
    // Predefined inputs
    vector<int> arr = {1, 3, 5, 7, 9};  // Example array
    int target = 12;  // Example target sum

    // Call the twoSum function and display the result
    if (twoSum(arr, target)) {
        cout << "Yes, there are two numbers that add up to the target sum." << endl;
    } else {
        cout << "No, there are no two numbers that add up to the target sum." << endl;
    }

    return 0;
}
