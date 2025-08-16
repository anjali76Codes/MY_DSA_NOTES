/*
We are having the array of child greeds and array of cookies 
and we have to assign the cookies in such a way that one child can get only one cookies and maximum number of child get the cookies 

#optimal approach : 
- sort both array child greed array and cookies array 
- using two pointers  l and r to iterate through the cookieSize and greed arrays. 
- iterating through an array and
    -  checking the condition if the current cookie can satisfy the current child’s greed 
        - i.e. cookieSize[l] <= greed[r].

If the current cookie can satisfy the current child’s greed, we move to the next child.
Always move to the next cookie weather current child  is satisfied or not .

return the r(represents the number of childs)-> max child 


Time complexity : O(NlogN)+O(NlogN)+O(M)
space complexity : O(1)

*/




                            
#include<bits/stdc++.h>
using namespace std;



int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
 
    // size of greed array
    int n = greed.size();

   
    //size of the cookieSize array
    int m = cookieSize.size();

    // Sort the greed factors in ascending order to try and satisfy the least greedy children first
    sort(greed.begin(), greed.end());


    // Sort the cookie sizes in ascending order to use the smallest cookies first
    sort(cookieSize.begin(), cookieSize.end());

    
    //Initializing the pointer from the first cookie for cookie array
    int l = 0;

  // initializing a pointer from the first child for greedy arrays
    int r = 0;



    // Iterate while there are cookies and children
    // left to consider
    while (l < m && r < n) {

        // If the current cookie can satisfy the current child's greed
        if (greed[r] <= cookieSize[l]) {
            // Move to the next child,
            // as the current child is satisfied
            r++;
        }
        // Always move to the next cookie
        // whether the current child was satisfied or not
        l++;
    }

    // The value of r at the end of
    // the loop represents the number
    // of children that were satisfied
    return r;
}


int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
    
    cout << "Array Representing Greed: ";
    for(int i = 0; i < greed.size(); i++){
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for(int i = 0; i < cookieSize.size(); i++){
        cout << cookieSize[i] << " ";
    }
    
    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies "<< ans;
    cout << endl;

    return 0;
}
                            
                        


