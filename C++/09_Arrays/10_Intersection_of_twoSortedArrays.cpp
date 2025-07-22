/*
 Intersection of two sorted arrays
- elements present in both arrays
- repetition of elements is allowed

1. Brute force approach
- create a visited array and all indexes marked as 0
- keep pointer in the first array and check for that element in the second array
- if we find an element then we will add it into the new array and also the visited array we will mark the index of that taken 2 as '1'
- once the iteration is over then the ans array will be ready, no need to look into the second array

- Time complexity -> O(n1xn2)
- Space Complexity -> O(n2)  // the smaller visited array

2. Optimal Approach
- we can use a two pointer approach
- we will keep two pointers i and j at the starting of the arrays
- compare first with the second
- if not match then two cases will be 
     - A[i]> B[j] -> j++
     - B[j]>A[i] -> i++

- if they match then move both i++, j++ and also add the element into the array
- Time complexity -> O(n1 + n2) - in the worst case
- Space Complexity -> O(1) - we are not using any extra spaces

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection_of_twoSortedArray_brute(int A[], int B[], int m, int n)
{

    vector<int> Intersect_Arr;

    int visitedArr[n] = {0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j] && visitedArr[i] == 0)
            {
                Intersect_Arr.push_back(A[i]);
                visitedArr[i] = 1;
                break;
            }
             if(B[j]>A[i]) break;
        }
       
    }

return Intersect_Arr;

    
}

vector<int> intersection_of_twoSortedArray_optimal(int A[], int B[], int m, int n)
{
vector<int>ans;
int i = 0;
int j = 0;
while(i<m && j<n){
    if(A[i] < B[j]){
        i++;
    }
    else if(A[i]> B[j]){
        j++;
    }
    else{
        ans.push_back(A[i]);
        i++;
        j++;
    }
}

return ans;

}

int main()
{
    int m;
    int n;
    cin >> m;
    cin >> n;
    int A[m];
    int B[n];
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

//    vector<int>res =  intersection_of_twoSortedArray_brute(A, B, m, n);
    vector<int> result = intersection_of_twoSortedArray_optimal(A, B, m, n);

    for (auto num : result)
    {
        cout << num << " ";
    }

    return 0;
}