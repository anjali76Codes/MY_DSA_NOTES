/*
Asteroid collision
we are given an array

Approach :
- traverse the array
    -  if in array +ve ele is found simply put it into the stack
    - when -ve comes check the condition
    - if(st.top<arr[i]) then pop the stack top
    - if stack is not empty but there both are the same ele(without considering its sign ) then simply pop both
    - if stack is empty then push the current arr ele into the stack even if it is -ve
- return the list / stack

Note * : Collision is not occur when stack is empty or -ve ele are only in the stack

time complexity : O(2N)
space complexity : O(N)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroid_collision(vector<int> arr)
{
    list<int> lst;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // when +ve asteroid is coming, push it into the list
        if (arr[i] > 0)
        {
            lst.push_back(arr[i]);
        }
        else
        {
            // If the asteroid is negative, check for collision
            while (!lst.empty() && lst.back() > 0)
            {
                // If the current asteroid is larger than the last element in the list, pop the list
                if (lst.back() < abs(arr[i]))
                {
                    lst.pop_back();
                    continue;
                }
                // If both asteroids are the same size, both destroy each other
                else if (lst.back() == abs(arr[i]))
                {
                    lst.pop_back();
                }
                // If the last asteroid in the list is larger, the current one is destroyed
                else
                {
                    break;
                }
            }

            // If the list is empty or the last element is negative, the current asteroid survives
            if (lst.empty() || lst.back() < 0)
            {
                lst.push_back(arr[i]);
            }
        }
    }

    // Convert the list to a vector to return the result
    vector<int> result(lst.begin(), lst.end());
    return result;
}

int main()
{
    vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> ans = asteroid_collision(arr);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
