/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
*/


#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

vector<int> maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    // combine start and end
    vector<pair<int, int>> t;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        t.push_back(p);
    }

    // sort based on the finish time in incresing order
    sort(t.begin(), t.end(), cmp);

    // find  max meetings can be possible
    vector<int> ans;
    // ans[0] = 1;
    int ansEnd = t[0].second; // first as always be possible

    for (int i = 0; i < n; i++)
    {
        if (ans.empty())
        {
            ans.push_back(i + 1);
        }

        if (t[i].first > ansEnd)
        {
            ans.push_back(i + 1);
            ansEnd = t[i].second;
        }
    }

    return ans;
}

int main()
{

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    vector<int> res = maxMeetings(start, end);
    for (auto &it : res)
    {
        cout << it << " ";
    }

    return 0;
}