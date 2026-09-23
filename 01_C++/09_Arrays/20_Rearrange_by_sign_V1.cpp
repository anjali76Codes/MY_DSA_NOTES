/*
Rearrange elements by sign 
# variety 1 : having equal in size
we are given the array with equal in size of positive elements and negative elements 
+ve - n/2 size  and -ve n/2 size 

# Brute Approach :
1. store all positive in one array and all negative in another
2.  all +ve elements occupy even places and all -ve  odd 
3. display it 

time complexity : O(n)+O(n)-> O(2n)
space complexity : O(n)



# optimal approach : 
1. create and ans array declare posindex = 0 (even indexes)
 and negindex = 1 (Odd indexes)
2. One for loop to iterate across array 
3. if arr[i] <0  then -ve ele put into the odd place  like do for all (+ve /-ve)
     ans[negindex ] = arr[i];
      negindex+=2 

and negindex+=2 (next odd place for next -ve ele) 
for +vd even place(index)
for +ve like this :
     ans[posindex] = arr[i];
        posindex+=2 ;
4. return ans array 


time complexity : O(n) 
space complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

void Rearrange_Positive_Negative_brute(vector<int> &arr, int n)
{
    vector<int> pos_arr;
    vector<int> neg_arr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos_arr.push_back(arr[i]);
        }
        else
        {
            neg_arr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = pos_arr[i];
        arr[2 * i + 1] = neg_arr[i];
    }
}


vector<int> Rearrange_Positive_Negative_optimal(vector<int> &arr, int n)
{

vector<int>ans(n) ;
    int posindex = 0 ; 
    int negindex = 1;

for(int i = 0 ; i<n ; i++){
    if(arr[i]<0 ){
      ans[negindex ] = arr[i];
      negindex+=2 ;  
    }

    else{
       /* `ans[posindex] = arr[i]; posindex+=2;` is a part of the optimal approach to rearrange
       positive and negative numbers in an array. */
        ans[posindex] = arr[i];
        posindex+=2 ;
    }
}
return ans; 
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i);
    }

    // Rearrange_Positive_Negative_brute(arr, n);
   vector<int> res =  Rearrange_Positive_Negative_optimal(arr, n);
    for (auto it : res)
    {
        cout<<it<<endl ;
    }


    return 0;
}