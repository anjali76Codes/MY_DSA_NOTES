#include <bits/stdc++.h>
using namespace std;


// Function to find the missing number using XOR
int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;  // Total number of elements if no number were missing
        int xor_all = 0;
        int xor_arr = 0;



// The result of XORing all numbers from 1 to 5
// xor_all = 1 ^ 2 ^ 3 ^ 4 ^ 5
// xor_all = 1 ^ 2 = 3
// xor_all = 3 ^ 3 = 0
// xor_all = 0 ^ 4 = 4
// xor_all = 4 ^ 5 = 1
// So, xor_all = 1 (after XORing all numbers from 1 to 5)

// XOR all numbers from 1 to n
for (int i = 1; i <= n; i++) {
            xor_all ^= i;
}





// The result of XORing all numbers in the array
// xor_arr = 1 ^ 2 ^ 4 ^ 5
// xor_arr = 1 ^ 2 = 3
// xor_arr = 3 ^ 4 = 7
// xor_arr = 7 ^ 5 = 2
// So, xor_arr = 2 (after XORing all elements in the array)
        // XOR all elements in the array
        for (int num : arr) {
            xor_arr ^= num;
        }

        // The missing number is the XOR of xor_all and xor_arr
        return xor_all ^ xor_arr;
    }

int main() {
    // Predefined input array (you can modify this as needed)
    vector<int> arr = {1, 2, 4, 5};  // 3 is missing in this array

  
    int missing_number = missingNum(arr);

    // Output the result
    cout << "The missing number is: " << missing_number << endl;

    return 0;
}
