#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high)
{
    int cnt = 0;
    int left = low;
    int right = mid + 1;

    vector<int> temp; // to store the sorted elements

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }

        // right is smaller that means in case of inversions the left side all present ele will add to my cnt
        else
        {
            temp.push_back(nums[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // left ele is remaining
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    // placing ele from temp to original array
    for (int i = low; i<high; i++)
    {
        nums[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    // base case
    if (low >= high)
        return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    // after base case return now we need to merge based on the condition
    cnt += merge(nums, low, mid, high);

    return cnt;
}

int countInversions(vector<int> &nums, int n)
{

    return mergeSort(nums, 0, n - 1);
}

int main()
{
    vector<int> arr = {5, 3, 2, 1, 4};
    int n = arr.size();

    cout << countInversions(arr, n);

    return 0;
}