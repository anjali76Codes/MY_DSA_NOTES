/* Majority element - ( > n/2 times)

# Brute Approach :
1. pick element and scan across the array and calculate count
2. if count > N/2 times then return it


 time complexity : O(n2)


# Better approach :
1. iterate  over each element
2. and store it into the map with its count(update when repeat)
3. iterate over map and return that element which has max count

time complexity : in case of map -> O(nlogn)+ O(n)
space complexity : O(n) - when each are unique ele



# Optimal Approach :
Moore's Voting algorithm :
Intuition : 
    Initialize: Set first element as the current element(assume majority el) and count = 1.
Traverse:
    If the same element, count++.
    If different, count--.
    If count = 0, update the current element and set count = 1.
Final Check: Traverse again to count occurrences of the current element. If count > n/2, it’s the majority element.


steps : 
1. initialize count  = 0 and el;
2. iterate over the array
3. if count == 0 then
    - count = 1
    - el = arr[i] and
4. else if el == arr[i] then count++
5. else count--
6. again iterate over the array and if arr ele == el then cntl ++ 
7. return el if cntl > N/2


Time complexity : O(n)




*/

#include <bits/stdc++.h>
using namespace std;

int Majority_Element_brute(int arr[], int n)
{
    int count = 0;
    int N = n / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > N)
        {
            return arr[i];
        }
    }
    return -1;
}

int Majority_Element_better(int arr[], int n)
{

   
    int N = n / 2;
  
    /* It is creating a map where the key is an integer value from the array `arr` and
    the value is the count of occurrences of that integer in the array. */
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }


   /* In each iteration, `it` represents a key-value pair where
   `it.first` is the key (integer value from the array `arr`) and `it.second` is the value (count of
   occurrences of that integer in the array). */
    for (auto it : mp)
    {
        if (it.second > N)
        {
            return it.first;
        }
    }

    return -1;
}

int Majority_Element_optimal(int arr[], int n)
{
    int count = 0;
    int el;

//  3 1 2 1 1

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = arr[i];
        }
        else if (el == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            cnt1++;
        }
    }

    if (cnt1 > n / 2)
    {
        return el;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Majority_Element_brute(arr, n);

    cout << endl;
    cout << Majority_Element_better(arr, n);
    cout << endl;
    cout << Majority_Element_optimal(arr, n);

    return 0;
}





