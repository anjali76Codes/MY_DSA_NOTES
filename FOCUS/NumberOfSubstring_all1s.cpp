// class Solution {
// public:
//     int numSub(string s) {
//         const int M = 1000000007; // Modulo value
//         int n = s.length();
//         long long cnt = 0;
//         long long res = 0;
        
//         for (int i = 0; i < n; i++) {
//             if (s[i] == '1') { // Compare with '1' not 1
//                 cnt++;
//             } else {
//                 res = (res + cnt * (cnt + 1) / 2) % M; // Add the count of substrings formed by the group of 1's
//                 cnt = 0; // Reset count when we hit a '0'
//             }
//         }
        
//         // Adding the last group of '1's if the string ends with '1'
//         res = (res + cnt * (cnt + 1) / 2) % M;
        
//         return (int)res; // Return the result as an integer
//     }
// };
