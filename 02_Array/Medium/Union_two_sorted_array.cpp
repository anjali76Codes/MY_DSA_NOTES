#include<bits/stdc++.h>
using namespace std ;



class Solution {
public:
    // a,b : the arrays
    // Function to return a list containing the Union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i = 0;
        int j = 0;

        int n = a.size();
        int m = b.size();

        vector<int> Union;

        while(i < n && j < m) {
            if(a[i] <= b[j]) {
                if(Union.size() == 0 || Union.back() != a[i]) {
                    Union.push_back(a[i]);
                }
                i++;
            }
            else {
                if(Union.size() == 0 || Union.back() != b[j]) {
                    Union.push_back(b[j]);
                }
                j++;
            }
        }

        // If array 'a' still has remaining elements
        while(i < n) {
            if(Union.size() == 0 || Union.back() != a[i]) {
                Union.push_back(a[i]);
            }
            i++;
        }

        // If array 'b' still has remaining elements
        while(j < m) {
            if(Union.size() == 0 || Union.back() != b[j]) {
                Union.push_back(b[j]);
            }
            j++; 
        }

        return Union;
    }
};

int main() {
    Solution solution;
    
    // Predefined arrays
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 6, 7};

    // Find the union of the two arrays
    vector<int> result = solution.findUnion(a, b);

    // Print the result
    cout << "Union of the arrays: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
