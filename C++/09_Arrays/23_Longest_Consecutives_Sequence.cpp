/*
# Longest consecutive sequence

# Brute Approach :
1. for loop (pick up the element )
    - assign arr[i] i new variable i.e x = arr[i]
    - initialize count = 1

2. while loop for searching the next element of x i.e x+1 is present or not in entire array using linear search 
    - if ls(arr, x+1) == true then increase 
        -> x+=1 and count += 1

3. updata longest -> longest = max(longest , count)
4. return longest 

time complexity : O(n^2)
space complexity : O(1)


Better Approach : 
1. declaration 
    - lastsmaller = INT_MIN , count = 0 , longest = 1

2. sort the array -> sort(arr.begin() ,arr.end())
3. for loop to iterate across array 
 #condition check 
    - if(arr[i] - 1 == lastsmaller)
        - count +=1 
        - lastsmaller = arr[i]
    
    - else if (arr[i]  != lastsmaller)
        - count = 1 (reset count)
        - lastsmaller = arr[i]

4. update longest -> longest = max(longest , count)
5. return longest

time complexity :  O(nlogn)+O(n)
space complexity : O(1)



# Optimal Approach : 
1. declaration
    - int longest = 1 
    - unordered_set<int> st 
2. if no element is present return 0 -> if (n==0)
3. first  Insert all array elements into the unordered set 
4. iterate on set 
    - first pick up the element
 # check condition 
    -  if previous ele is present or not 
    when not present : st.find(it-1) == st.end()
        - then initialize count = 1 and current ele(x) = it 
        - while loop to search next element of x i.e x+1 is present or not in
5. update longest 
6. return longest 



time complexity : O(n) - for inserting in ds 
for loop - O(n)
  // while loop it is not iterating throughout the entire array it just iterating from the starting (it can be )
  takes time only O(n)  
   ==> O(3n)
   space complexity : O(n)

        



*/

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int num)
{
    // search for the element
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int longest_consecutive_sequence_brute(vector<int> &arr, int n)
{
 
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
       int  count = 1;

        while (linearSearch(arr, x + 1) == true)
        {
            x += 1;
            count+=1 ;
        }

        longest = max(longest, count);
    }
    return longest;
}

int longest_consecutive_sequence_better(vector<int> &arr, int n)
{

    // declaration
    int lastsmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    sort(arr.begin(), arr.end());

    // loop for each element in array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastsmaller)
        {
            count++;
            lastsmaller = arr[i];
        }
        /*
         If this condition is true, it means that the current element is not consecutive to the previous
         element, so we need to reset the count of consecutive elements to 1 and update the `lastsmaller`
         variable to the current element `arr[i]`.*/
        else if (arr[i] != lastsmaller)
        {
            count = 1;
            lastsmaller = arr[i];
        }

        // update longest sequence
        longest = max(longest, count);
    }
    return longest;
}



int longest_consecutive_sequence_optimal(vector<int> &arr, int n)
{

if(n==0){
    return 0 ;
}

// declaration
int longest = 1 ;
unordered_set<int> st ;

// inserting into the unordered set ds - O(n)
for (int i = 0; i < n; i++){
st.insert(arr[i]);
}


// iterate on unordered set - O(n)
for(auto it : st){
    // when previous ele(x-1)  is not present 
    if(st.find(it-1) == st.end()){
        int count = 1 ;
        int x = it ;

        // then check for the next one considering this as a starting point because it's previous is not present 
            // this is not iterating throughout the entire array it just iterating from the starting (it can be ) 
        while(st.find(x+1) !=st.end()){
            x = x+1 ;
            count++ ;
        }

    // update longest 
    longest = max(longest , count);
    }
   
}

return longest ;
}








int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longest_consecutive_sequence_brute(arr, n)<<endl;

    cout << longest_consecutive_sequence_better(arr, n)<<endl;
    cout << longest_consecutive_sequence_optimal(arr, n);

    // for(auto it : res){
    //     cout<<it<<endl;
    // }

    return 0;
}