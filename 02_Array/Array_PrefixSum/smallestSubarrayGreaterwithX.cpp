#include <bits/stdc++.h>
using namespace std;

int smallestSubarrayWithX(vector<int> arr, int x) {
   // two pointer approach move -shrink logic 

int n = arr.size();
int left = 0 ;
int right =0;
int minLen = INT_MAX;
int sum = arr[0];

for (int right = 0; right < n; right++) {
        sum += arr[right];

        // Shrink the window as small as possible while the sum is still >= x
        while (sum > x) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }
return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
 vector<int> arr = {1, 10, 5, 2, 7};
int x = 9;
    cout << smallestSubarrayWithX(arr, x);
    return 0;
}
