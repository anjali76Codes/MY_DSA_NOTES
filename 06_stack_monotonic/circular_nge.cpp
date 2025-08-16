#include<bits/stdc++.h>
using namespace std;

vector<int> circularNge(vector<int> &arr){
    int n = arr.size();
    vector<int>nge(n);
    stack<int>st;

  // hypothetically double the array which covers all the ele i.e circular array 
    for(int i = 2*n-1 ; i>=0 ; i--){
        while(!st.empty() && arr[i%n]>=st.top()){
            st.pop();
        }

        if(i<n){
            nge[i] = st.empty()? -1 : st.top();
        }

        st.push(arr[i%n]);
    }
    return nge;
}

int main()
{

    vector<int>arr = {2,10,12,1,11};
    vector<int>res = circularNge(arr);
    for(auto it:res){
        cout<<it<<" ";
    }

return 0;
}