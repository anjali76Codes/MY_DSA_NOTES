/*
# Best time to buy and sell 
imp :
1.we have to avoid loss so for this we have to buy first in minimum cost and sell it profitable or without any loss 


steps:

1. initialize minimal = arr[0] and profit = 0
2. for loop - iterate on array ele
    - cost = arr[i] -minimal 
    - profit = max(profit , cost)
    - minimal = min(minimal , arr[i]) -> it track minimal
3. return profit 
 
*/


#include<bits/stdc++.h>
using namespace std;

int BestTime_to_buy_and_sell(vector<int>&arr ,int n){
    int minimal = arr[0];
    int profit = 0 ;
    for(int i = 0 ; i < n ; i++){

        //calculate cost 
        int cost = arr[i] - minimal ;

        //update profit
        profit = max(profit , cost);

        //update minimal - track the minimal 
        minimal = min(minimal , arr[i]);
}
return profit ; 
}

int main()
{

    int n ;
    cin >> n ;
    vector<int>arr;
    for(int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x ;
        arr.push_back(x);
        }


cout<<BestTime_to_buy_and_sell(arr ,n);

return 0;
}