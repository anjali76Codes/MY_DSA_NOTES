/*  Union of two sorted array
combine two array without involving its duplicates

Brute approach
1. iterate for arr1
2. iterate for arr2
3. check if element is not present in arr1 - use Set ds
4. add it to result array

time complexity :
in worst case where all elements are unique in both arrays
- O(n1logn +n2logn +O(n1+n2)
space complexity :
O(n1+n2)+O(n1+n2) - it is an extra spaces used in set and returning the union of two array as a result


Optimal approach
1. using two pointer
2. one point to first array and second to second array 
3. check condition if element of first array is <= second then check it shouldn't be match to unionArr of back element and now insert the arr1 elements into the unionArr 
4. increment i 
5. else increment j 
6. if arr1 exhausted increment j and stored arr2 remaining values into the unioArr and vice versa 
7. return union array

time complexity : in worst case 
- O(n1+n2)
space complexity : O(n1+n2) - it is an extra space used in union array to store the union of two array as a result
*/

#include <bits/stdc++.h>
using namespace std;

void Union_of_twoSortedArray(int arr1[], int arr2[], int m, int n)
{
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(arr2[i]);
    }

    // for(auto it:s){
    //     cout<<it<<" ";
    // }

    // union of two array
    int Union[s.size()];
    int i = 0;
    for (auto it : s)
    {
        Union[i++] = it;
        cout << it << " ";
    }
}



vector<int> Union_of_twoSortedArray_optimal(int arr1[], int arr2[] , int m, int n){
    vector<int>unionArr;
    int i = 0;
    int j = 0;
    while(i<m && j<n){
        if(arr1[i]<=arr2[j]){
            if( unionArr.size() == 0 || unionArr.back() != arr1[i]){
               unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if( unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
                }
                j++;
        }
        
    }


    while(j<n){
        if( unionArr.size() == 0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
                }
                j++;
        }


      while(i<m){
        if( unionArr.size() == 0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
                }
                i++;
        }
        

    

    return unionArr;
}

int main()
{
    int m;
    int n;
    cin >> m;
    cin >> n;
    int arr1[m];
    int arr2[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    // Union_of_twoSortedArray_brute(arr1, arr2, m, n);
vector<int>result = Union_of_twoSortedArray_optimal(arr1, arr2, m, n);

for(auto num:result){
    cout<<num<<" ";
}

    return 0;
}