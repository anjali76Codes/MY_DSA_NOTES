/*
n a candy store, there are different types of candies available and arr[i] represent the price of  ith types of candies. You are now provided with an attractive offer.
For every candy you buy from the store and get k other candies ( all are different types ) for free. Now you have to answer two questions, what is the minimum and maximum amount of money you have to spend to buy all the  candies.
In both the cases you must utilize the offer i.e. you buy one candy and get k other candies for free.

Examples :

Input: arr[] = [3, 2, 1, 4], k = 2
Output: [3, 7]
Explanation: As according to the offer if you buy one candy you can take at most two more for free. So in the first case, you buy the candy worth 1 and takes candies worth 3 and 4 for free, also you need to buy candy worth 2. So min cost: 1+2 = 3. In the second case, you can buy the candy worth 4 and takes candies worth 1 and 2 for free, also you need to buy candy worth 3. So max cost: 3+4 = 7.
Input: arr[] = [3, 2, 1, 4, 5], k = 4
Output: [1, 5]
Explanation: For minimimum cost buy the candy with the cost 1 and get all the other candies for free. For maximum cost buy the candy with the cost 5 and get all other candies for free.
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> shopCandy(vector<int>&candies, int k , int n){

    // sort the candies
    sort(candies.begin(), candies.end());
   
vector<int>ans;
    // if min : buy less price candy and take at free the high price
    int mini = 0;
    int buy = 0;
    int free = n-1;

    while(buy<=free){
        mini+= candies[buy];
        buy++;
        free -= k ;  // k step ahead  till here msut have to buy 
    }


     // if max : buy max price candy and take at free the less price
    int maxi = 0;
    int buys = n-1;
    int frees = 0;

    while(frees<=buys){
        maxi+= candies[buys];
        buys--;
        frees += k ;  // k step ahead  till here msut have to buy 
    }

ans.push_back(mini);
ans.push_back(maxi);


return ans;
}

int main()
{

 vector<int>candies = {3,1,4,2};
 int k = 2;
 int N = 4;

vector<int>ans = shopCandy(candies , k , N);
for(auto it : ans){
    cout<<it<< " ";
}


return 0;
}