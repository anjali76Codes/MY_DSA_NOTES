/*
// Moving 0s to the end of the array


1. Brute force Approach
- first we will iterate and store all the non-zero numbers into a temp array
- then we will place all these elements into the main array at the front
- and then at the end we will just add zeros
- so here we will need 3 loops for doing
- Time complexity: first the storing into temp arr O(n), then storing back into the main array O(x) where x is the size of temp, and then adding zeros O(n-x)
- Time complexity -> O(n+x+n-x)  -> O(2n)
- Space Complexity -> Extra space used -> O(n)
        --  worst case when the entire array is stored as there are no zeros


2. Optimal Solution
- we can use a two pointer approach
- we can first find the first 0 in the array and assign j to it
- then we can start array from j+1 and if i is a non-zero number then just swap it with j and do j++
- i will go on moving forward in a for loop
- Time complexity will be for first iteration O(x) and the second loop O(n-x)
- Time complexity -> O(x + n-x) -> O(n)
- Space Complexity -O(1)

*/


#include <bits/stdc++.h>
using namespace std;


void moveZeroAtEnd_brute(int arr[] , int n){
    //1. storing non zero elements into the temp array
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    //2. storing non zero elements into the original array
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }



// 3. storing 0 at the end 
for (int i = temp.size(); i < n; i++)
{
    arr[i] = 0;
    }


}


void moveZeroAtEnd_optimal(int arr[] , int n){
   int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }  
}

// move all zeroes to the end of the array
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    moveZeroAtEnd_brute(arr , n);
    moveZeroAtEnd_optimal(arr,n);

    return 0;
}




