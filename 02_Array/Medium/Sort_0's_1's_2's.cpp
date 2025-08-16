/*   Dutch National Flag Problem
Key Idea:
The algorithm uses three pointers:

low — Marks the boundary between the 0s and 1s.

mid — Traverses the array and checks the current element.

high — Marks the boundary between the 1s and 2s.

Algorithm Steps:
Start with three pointers: low at the start of the array, mid at the beginning, and high at the end.

Traverse the array:

If arr[mid] == 0: Swap arr[low] and arr[mid], then increment both low and mid.

If arr[mid] == 1: Simply increment mid.

If arr[mid] == 2: Swap arr[mid] and arr[high], then decrement high.

Continue until mid > high.

Time Complexity:
O(n) where n is the number of elements in the array, because each element is processed at most once.

Space Complexity:
O(1), since we are using only a few extra variables (low, mid, high).

*/

#include<bits/stdc++.h>
using namespace std;



// National Flag Algorithm - assign 
void sortZOT(vector<int>& arr ){
    // since we don't have the sorted array hence the mid and low will point to first index ele
    int low = 0;
    int mid = 0;
    int high = arr.size()-1 ;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]== 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if(arr[i] == 1){
            mid++;
        }

        else{
            swap(arr[mid] , arr[high]);
                high--;
            }
        }

    }



int main()
{

    vector<int> arr = {2,0,2,1,1,0};
    sortZOT(arr);
    for(int a : arr){
        cout<<a<<" ";
    }

return 0;
}