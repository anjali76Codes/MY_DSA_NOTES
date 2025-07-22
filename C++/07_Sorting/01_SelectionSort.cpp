#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{

    // till we need  iterate  to swap
    for (int i = 0; i < n - 2; i++)
    {
        int min = i;
        // iterate to find minimum
        for (int j = i; j <=n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        // swap the min element with the first element of the unsorted array
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp; 
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    //  cout << "Enter Arrays elements : "; 
    for (int i = 0; i < n; i++)
    {
       cin >> arr[i];
    }

 selection_sort(arr, n);
 for(int i = 0 ; i<n; i++){
    cout<<arr[i]<<" ";
 }

    return 0;
}