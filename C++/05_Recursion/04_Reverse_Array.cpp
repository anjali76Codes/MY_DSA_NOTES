// // using two variable
// #include<bits/stdc++.h>
// using namespace std;

// void ReverseArray(int l , int r , int arr[]){
// if(l>=r){
//     return ;
// }
// swap(arr[l], arr[r]);
//   ReverseArray(l+1 , r-1 ,arr);

// }

// int main()
// {
// int n ;
// cin>>n;
// int arr[n];
// for(int i = 0 ; i<n; i++){
//  cin>>arr[i];
// }
//  ReverseArray(0 , n-1 ,arr);
//  for(int i = 0 ; i<n; i++){
//     cout<<arr[i]<<" ";
//  }

// return 0;
// }

// // using single variable

#include <bits/stdc++.h>
using namespace std;

void RevArr(int i, int n , int arr[])
{
    if (i >=n / 2)
    {
        return;
    }

  swap(arr[i] , arr[n-i-1]);
  RevArr(i+1 , n , arr);
}

int main()
{

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    RevArr(0,n ,arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}