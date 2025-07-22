#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    
    int maxi = arr[0];
    
    for(int i=0; i<arr.size(); ++i) {
        if(arr[i] > maxi) maxi = arr[i];
    }
    
    return maxi;
    
}



int secondLargestElement(vector<int> arr) {
    
    int largest = arr[0];
    int secondLargest = -1;
    
    for(int i=0; i<arr.size(); ++i) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
    }
    
    return secondLargest;
    
}

bool arrayIsSorted(vector<int> arr) {
    
    // two pointer approach
    for(int i=0; i<arr.size()-1; ++i) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    
    return true;
}

vector<int> removeDuplicatesFromSorted(vector<int> arr) {
    
    vector<int> res;
    
    /*Brute force*/
    
    // set<int> st;
    // for(int a: arr) st.insert(a);
    
    // for(auto it = st.begin(); it!=st.end(); ++it) {
    //     res.push_back(*it);
    // }
    
    
    /*Optimal*/
    
    for(int i=0; i<arr.size(); ++i) {
        if(res.size() == 0 || res.back() != arr[i]) res.push_back(arr[i]);
    }



    
 
    return res;
}



vector<int> leftRotateByD(vector<int> arr, int d) {
    
    // d we have needs to be modular
    d = d%arr.size();
    
    vector<int> res(arr.size());
    copy(arr.begin(), arr.end(), res.begin());
    // the above thing holds no relevance to the sol
    
    reverse(res.begin(), res.begin() + d);
    reverse(res.begin() + d, res.end());
    reverse(res.begin(), res.end());
    
    return res; 
}



vector<int> moveZerosToEnd(vector<int> arr) {
    
    vector<int> res(arr.size());
    copy(arr.begin(), arr.end(), res.begin());
    // the above thing holds no relevance to the sol
    
    // find the first occ of zero 
    int idx = -1;
    for(int i=0; i<res.size(); ++i) {
        if(res[i] == 0) {
            idx = i;
            break;
        }
    }
    
    int j=idx;
    for(int i=idx; i<res.size(); ++i) {
        if(res[i] != 0) {
            swap(res[i], res[j]);
            ++j;
        }
    }
    
    return res;
    
}

vector<int> unionOfArray(vector<int> arr1, vector<int> arr2) {
    
    vector<int> unionArr;
    
    // two pointers for array each
    int i=0, j=0;
    int el;
    while(i < arr1.size() && j < arr2.size()) {
        
        if(arr1[i] <= arr2[j]) {
            if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
                i++;
        } else {
              if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
                j++;
        }
        
    }
    
    // if one of the arrays is bigger 
    while(i < arr1.size()) {
        
       if(unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
                i++;
    }
    
    while(j < arr2.size()) {
         if(unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
                j++;
    }
    
    return unionArr;
    
}

vector<int> intersectionOfArrays(vector<int> arr1, vector<int> arr2) {
    
    vector<int> intersectArr;
    
    int i=0; 
    int j=0;
    
    while(i < arr1.size()) {
        
        if(arr1[i] == arr2[j]) {
            intersectArr.push_back(arr1[i]);
            i++;
            j++;
        }
        
        if(arr1[i] > arr2[j]) {
            j++;
        }
        
        if(arr2[j] > arr1[i]) {
            i++;
        }
    }
    
    return intersectArr;
    
}

int missingNo(vector<int> arr) {
    
    int xor1 = 0;
    int xor2 = 0;
    
    // XOR Logic
    
    for(int i=0; i<arr.size(); ++i) {
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ i+1;
    }
    
    int missing = xor1 ^ xor2;
    
    
    return missing;
}

int maxConsecutiveOnes(vector<int> arr) {
    
    int maxCnt = INT_MIN;
    int cnt = 0;
    for(int i=0; i<arr.size(); ++i) {
        
        if(arr[i] == 1) {
            cnt++;
        } else {
            cnt = 0;
        }
        
        maxCnt = max(maxCnt, cnt);        
    }
        return maxCnt;
    
    
}

int noAppearingOnce(vector<int> arr) {
    
    int xor1 = 0;
    for(int i=0; i<arr.size(); ++i) {
        xor1 ^= arr[i];
    }
    
    return xor1;
    
}

int longestSubarrayGivenSum(vector<int> arr, long long k) {
    
    unordered_map<long long, int> prefixSumMap;
    int maxLen = 0;
    long long sum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;

        if (prefixSumMap.find(rem) != prefixSumMap.end()) {
            maxLen = max(maxLen, i - prefixSumMap[rem]);
        }

        // only insert the first occurrence of sum
        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }

    return maxLen;
}
int main() {
    
    vector<int> arr = {3, 0, 0, 0,0,3};
    
    // input for union and intersection
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {2,4,4,5};
    
    cout<<"Largest Element: "<<largestElement(arr)<<endl;
    
    cout<<"Second Largest Element: "<<secondLargestElement(arr)<<endl;
    
    cout<<"Array is sorted "<<arrayIsSorted(arr)<<endl;  
    
    vector<int> res= removeDuplicatesFromSorted(arr);
    cout<<"Without Duplicates : ";
    for(int a: res) cout<<a<<" "; cout<<endl;
    
    int d = 3;
    res= leftRotateByD(arr, d);
    cout<<"Left Rotates Array : ";
    for(int a: res) cout<<a<<" "; cout<<endl;
    
    res = moveZerosToEnd(arr);
    cout<<"Moved Zeros to the end : ";
    for(int a: res) cout<<a<<" "; cout<<endl;
    
    res = unionOfArray(arr1, arr2);
    cout<<"Union of Arrays : ";
    for(int a: res) cout<<a<<" "; cout<<endl;
    
    res = intersectionOfArrays(arr1, arr2);
    cout<<"Intersection of Arrays : ";
    for(int a: res) cout<<a<<" "; cout<<endl;
    
    cout<<"Missing Number: "<<missingNo(arr)<<endl;
    
    cout<<"Maximum Consecutive Ones : "<<maxConsecutiveOnes(arr)<<endl;
    
    cout<<"No that appears once : "<<noAppearingOnce(arr)<<endl;
    
    long long k = 3;
    cout<<"Longest Subarray with given sum (-ve +ve) : "<<longestSubarrayGivenSum(arr, 3)<<endl;
    
    
    
    
    
    
    return 0;
}