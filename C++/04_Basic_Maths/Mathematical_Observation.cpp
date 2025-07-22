#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> ls;
    
    // Loop through numbers from 1 to sqrt(n) to find divisors
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {  // Correct condition to check if i is a divisor of n
            ls.push_back(i);
            
            // To avoid adding the square root twice, check if n / i is not equal to i
            if(n / i != i) {
                ls.push_back(n / i);
            }
        }
    }
    
    // Sort divisors in ascending order(better complexity)
    sort(ls.begin(), ls.end());
    
    // Print the divisors
    for(auto it : ls) {
        cout << it << " ";
    }
    
    return 0;
}
