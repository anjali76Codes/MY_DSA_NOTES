#include <bits/stdc++.h>
using namespace std;

int findDuplicateNum(vector<int> &arr)
{
    // Set for keeping track of visited elements
    unordered_set<int> visited;

    for (int i = 0; i < arr.size(); i++)
    {
        // If the element has already been visited, it's a duplicate
        if (visited.find(arr[i]) != visited.end())
        {
            return arr[i];
        }
        // Otherwise, mark the element as visited
        visited.insert(arr[i]);
    }

    return -1; // No duplicate found
}

int main()
{
    vector<int> arr = {1, 3, 9, 4, 9 , 9}; // Sample input array
    cout << findDuplicateNum(arr) << endl;
    return 0;
}
