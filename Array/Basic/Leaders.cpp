#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr) {
   vector<int>leaders ;
        int n = arr.size();


     // last ele is always a leader
       int max = arr[n-1];
     
       leaders.push_back(arr[n-1]);
       
          // as we have compare with right side so start so we start from end 
       for(int i = n-2; i>=0; i--){
           if(arr[i]>=max){
             leaders.push_back(arr[i]);
               max = arr[i];
            
           }
       }
       
       reverse(leaders.begin(), leaders.end());
       return leaders;
}

int main() {
    // Predefined input array
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    // Function call to get the leaders
    vector<int> result = leaders(arr);
    
    // Output the result
    cout << "Leaders in the array: ";
    for (int leader : result) {
        cout << leader << " ";
    }
    cout << endl;
    
    return 0;
}
