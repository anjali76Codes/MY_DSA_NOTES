#include<bits/stdc++.h>
using namespace std;


int LinearSearch(int arr[] , int n , int target){
    for(int i = 0 ; i<n; i++){
        if(arr[i] == target){
            return i;
            break;
        }
    }
    return -1;

   
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target ;
    cin>>target;

   cout<< LinearSearch(arr , n,target);

return 0;
}
