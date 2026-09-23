#include <bits/stdc++.h>
using namespace std;

// largest Odd Number in string
string largestOddNumber(string num) {
    // string ans = "";
    int n = num.length();  // Find the length of the string

    // Loop through the string in reverse order
    for(int i = n-1; i >= 0; i--){
        
        // Check if the digit at current index is odd
        if((num[i] - '0') % 2 != 0){
            return num.substr(0, i+1);  // Return substring from the start to the current index + 1
        }
    }

    return "";  // If no odd number is found, return empty string
}

int main() {
    string s = "5347";  // Input string
    cout << largestOddNumber(s);  // Call the function and print the result

    return 0;
}
