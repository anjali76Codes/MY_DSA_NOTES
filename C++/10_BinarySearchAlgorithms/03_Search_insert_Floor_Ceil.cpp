/*
# Search Insert position 
--> need to search for the index of the target value in the array.
--> If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

Time Complexity: O(logN)
Space Complexity: O(1)



# Floor and Ceil
floor -> The floor of x is the largest element in the array which is smaller than or equal to x.
(<= x but in largest number)
Eg. 10 20 30 40 and x = 25 so floor of x -> 20


Ceil(lower bound) -> The ceiling of x is the smallest element in the array greater than or equal to x.
(>=x but in smallest  number) 
Eg. 10 20 30 40 and x = 25 so floor of x -> 30



Time Complexity: O(logN)
Space Complexity: O(1)

*/



#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


int findFloor(vector<int>&arr, int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}

int findCeil(vector<int>&arr, int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}



int main()
{
    int n ;
     cin>>n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
        }
        int x ;
        cin>>x;
   
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";

    cout<<findFloor(arr, n ,x)<<endl;
    cout<<findCeil(arr, n , x)<<endl;
    return 0;
}

