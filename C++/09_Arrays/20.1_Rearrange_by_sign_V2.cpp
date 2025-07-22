/*
 Rearrange elements by sing but in this variety we don't have the equal size for the +v and -ve elements

 two possibility :
 1. pos.size() > neg.size()
 2. neg.size() >pos.size()

 # Brute approach :
 same as variety 1 but since it is not equal in size so for remaining +ve or -ve we have to add some steps
 # Time complexity : O(2n) where n is the size of the array

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Rearrange_Positive_Negative_brute(vector<int> &arr, int n)
{

    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    



    // when pos > neg
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        // without altering store at end remaining +ve elements
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }

    // when neg> pos
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        // without altering store at end remaining +ve elements
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // Rearrange_Positive_Negative_brute(arr, n);
    vector<int> res = Rearrange_Positive_Negative_brute(arr, n);
    for (auto it : res)
    {
        cout << it << endl;
    }

    return 0;
}