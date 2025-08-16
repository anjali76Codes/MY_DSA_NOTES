/*
Find minimum  no. of days to make M bouquets
wea re given the three things
1. the number of flowers -> K (eg. adjacent flowers are required)
2. the number of bouquets -> M
3. the number of days to bloom the flower -> array[]


# Brute approach :
1. find min and max of the array
2. iterate from min to max and call the function possible(if it is true then return minimum day is required to make the M bouquets)

3. possible function runs from min day to max day
4. for each day it checks if it is possible to make M bouquets with K flowers

5. if arr[i] <= day increase the count 
    else calculate the no of bouquets -> cnt/k
    and cnt = 0 (reset and start again)


    time complexity : 
    O(mini - maxi +1) * n




*/

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int n, int day, int M, int k)
{
    int cnt = 0;
    int no_of_bouquet = 0;

    // it check if it is bloomed or not on the ith day
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }

        // when it is not bloomed then calculate the no of bouquet and initialize cnt = 0
        else
        {
            no_of_bouquet += (cnt / k);
            cnt = 0;
        }
    }


    //  at end need to check the no of bouquets are formed
    no_of_bouquet += (cnt / k);
    return no_of_bouquet>=M ;
}

// brute approach
int Minimum_days_M_bouquets(vector<int> &arr, int n, int M, int k)
{
     // Get the minimum blooming day
    int mini = *min_element(arr.begin(), arr.end());

    // Get the maximum blooming day
    int maxi = *max_element(arr.begin(), arr.end()); 


    for (int i = mini; i <= maxi; i++)
    {
        if (possible(arr, n, i, M, k) == true)
        {
            return i;
        }
    }

    return -1;
}



// optimal approach  - O(n* log(mini-maxi +1))

int Minimum_days_M_bouquets_optimal(vector<int> &arr, int n, int M, int k)
{
    


// when exceed the limit 
if(n<M*k) return -1 ;

int low = *min_element(arr.begin(), arr.end());  // minimum day value
int high = *max_element(arr.begin(), arr.end()); // maximum day value

int ans = high;

while(low<=high){
    int mid = (low+high)/2 ;

    if(possible(arr, n, mid , M , k ) == true){
        ans = mid ; 
        high = mid - 1 ;
    }
    else{
        low = mid + 1 ;
        }

}
return ans ;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int M, k;
    cin >> M >> k;
    int res = Minimum_days_M_bouquets(arr, n, M, k);
    int res1 = Minimum_days_M_bouquets_optimal(arr, n, M, k);

    cout << "Minimum days to make the bouquets is :" << res << endl;
    cout << "Minimum days to make the bouquets is :" << res1 << endl;

    return 0;
}