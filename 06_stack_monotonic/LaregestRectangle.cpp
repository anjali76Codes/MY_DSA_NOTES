#include<bits/stdc++.h>
using namespace std;

int LargestRectangle(vector<int>&arr){
int n = arr.size();


// right smallest nearest 
 vector<int>rsn(n,0);
  vector<int>lsn(n,0);
    stack<int>s;
    stack<int>s2;
    for(int i = n-1 ; i>=0 ; i--){
        while(!s.empty() && arr[i]<=arr[s.top()]){
            s.pop();
        }

        if (s.empty()){
            rsn[i] = n;
        }
        else{
            rsn[i] = s.top();
        }
        s.push(i);
    }


    // left smallest nearest
    for(int i = 0 ; i<n ; i++){
        while(!s2.empty() && arr[i]<=arr[s2.top()]){
            s2.pop();
        }

        if (s2.empty()){
            lsn[i] = -1;
        }
        else{
            lsn[i] = s2.top();
        }
        s2.push(i);
    }

   
    int ans = 0;
    for(int i = 0; i<n ; i++){
        int width = rsn[i]-lsn[i]-1;
        int calArea = arr[i]*width;
        ans = max(ans , calArea);
    }

    return ans;
}

int main()
{

    vector<int>arr = {2,1,5,6,2,3};
    cout<<LargestRectangle(arr);


return 0;
}