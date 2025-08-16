#include<bits/stdc++.h>
using namespace std;


// brute approach 
    string longestCommonPrefix(vector<string> arr) {
     string ans = "";

     for(int i =0 ; i<arr[0].length(); i++){
        for(int j = 0 ; j<arr.size()-1 ; j++){
            if(arr[j][i] != arr[j+1][i])
                return ans;
        }
        ans += arr[0][i];
     }
      return ans;
        
    }



// optimal 
string largestCommonPrefix_Optimal(vector<string> arr){
    string ans = "";
    sort(arr.begin() , arr.end());

    int i =0 ;
    while(i<arr[0].length() && arr[0][i] == arr[arr.size()-1][i]){
        ans += arr[0][i];
        i++;
    }

    return ans;



    
}

int main()
{
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};

   string res =  longestCommonPrefix(arr);
    string res1 = largestCommonPrefix_Optimal(arr);
   for(char ch : res1){
    cout<<ch<<"";
   }


return 0;
}