/*
We are given the string and k -digits
we have to remove the ele in such a way so that the remaining digits would be my smallest 

#Steps : 
- creating a stack to store the char 
- iterating over the string
- check the conditions 
return the res 

time complexity : O(3N)+O(K)
space complexity : O(N)+O(N)
*/


#include<bits/stdc++.h>
using namespace std;

string remove_kth_digits(string s, int k){
    stack<char>st ;
    int n = s.size(); 

    if (k >= n) return "0"; // Edge case: If k >= n, remove all digits, return "0"

    for(int i = 0 ; i<n ; i++){
        // 1. when stack is not empty and still we have k and top is > then the current ith value 
        while(!st.empty() && k>0 && (st.top() - '0') > (s[i] - '0')){
            st.pop();
            // when any ele is pooped decrease the k
            k--;
        }

    st.push(s[i]);    

    }

    // 2. when top of the stack is not greater and we still have the k(kth ele will remove from the end )
    while(k>0){
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    // but when we are done with the removing kth ele from the stack we need to store the remaining ele in my res till empty it will insert all the ele in my res
    string res ="";
    while(!st.empty()){
        res = st.top() + res ;
        st.pop();
        }


       /* The code snippet `while(!res.size() != 0 && res.back() == '0'){ res.pop_back(); }` is used to
       remove any trailing zeros from the string `res`. */
        while(!res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }
        
  // Remove leading zeros
  while (!res.empty() && res[0] == '0') {
    res.erase(res.begin());
}


// if res is empty simply return the 0 else return the res
if(res.empty()) return "0";
return res;


}

int main()
{
    string s = "00014322000";
    int k ; 
    cin>>k;
    string ans = remove_kth_digits(s,k);
    cout<<ans<<" ";
    


return 0;
}