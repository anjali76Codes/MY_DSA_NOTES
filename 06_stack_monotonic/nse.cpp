// nearest smallest elements

#include<bits/stdc++.h>
using namespace std;

vector<int> nearestSmallestEle(vector<int>&arr){
    int n = arr.size();
    vector<int>nse(n);
    stack<int>s;

    for(int i  = 0 ; i<n ; i++){
        while(!s.empty() && arr[i]<=s.top()){
            s.pop();
        }

        if(s.empty()){
            nse[i] = -1;
        }
        else{
            nse[i] = s.top();
        }
        s.push(arr[i]);
    }
return nse;
}

int main()
{

    vector<int>arr = {4,5,2,10,8};
    vector<int>res = nearestSmallestEle(arr);
    for(auto it : res){
        cout<<it<<" ";
    }

return 0;
}