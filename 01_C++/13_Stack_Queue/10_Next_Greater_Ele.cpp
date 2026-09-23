/*
1st approach :
-  iterate over the array and compare which one is next greater
- next greater get added into the new array and if there is no any  next greater by default it is -1

time complexity : O(N2)
space complexity : O(N)


# Optimal approach :
time complexity : O(2N)
space complexity : O(N)+O(N) -> O(2N)

Note* :
A monotonic stack is a stack that keeps elements in a specific order, either increasing or decreasing. For finding the next greater element, we use a decreasing stack. As we go through the array, we pop elements from the stack when we find a bigger element, and that becomes the next greater element.  


*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findNextGreater(vector<int> &arr)
{
    int n = arr.size();

    // Initialize with -1 (default for no greater element)
    vector<int> nqe(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                nqe[i] = arr[j];
                break;
            }
        }
    }
    return nqe;
}

vector<int> NextGreater_optimal(vector<int> arr)
{
    int n = arr.size();
    vector<int> nqe(n, -1);
    stack<int> s;

    // instead of traversing form start reverse the traverse to get next greater
    for (int i = n; i >= 0; i--)
    {

        // loop which check the stack will not be empty and check for the stack of the top to get the next greater
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        // when there is no any greater ele is present
        if (s.empty())
            nqe[i] = -1;

        else
            nqe[i] = s.top();

     // at the end push the arr[i]  
        s.push(arr[i]);
    }
    return nqe;
}

int main()
{
    vector<int> arr = {2, 0, 5, 1, 7};
    vector<int> res = findNextGreater(arr);

    for (int num : res)
    {
        cout << num << " ";
    }
    cout<<endl;
    vector<int>ans = NextGreater_optimal(arr);
     for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}