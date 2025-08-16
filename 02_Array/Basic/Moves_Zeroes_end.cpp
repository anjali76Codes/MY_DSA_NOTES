#include<bits/stdc++.h>
using namespace std;

void moveZerosAtEnd(vector<int>& arr) {
    int j = 0; // Pointer to track the position of the next non-zero element

    // Loop through the array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            // Swap only if the non-zero element is not already in its correct place
            swap(arr[i], arr[j]);
            j++; // Increment the position of next non-zero element
        }
    }
}

int main() {
    vector<int> v = {1, 3, 0, 2, 0, 1, 2, 0};
    moveZerosAtEnd(v);
    for (int a : v) {
        cout << a << " ";
    }
    return 0;
}
