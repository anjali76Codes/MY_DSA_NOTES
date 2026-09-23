// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();

//         // -------------------------------------------------------------
//         // Prefix sums:
//         // Z[i] = number of zeros in s[0..i-1]
//         // O[i] = number of ones  in s[0..i-1]
//         // -------------------------------------------------------------
//         vector<int> Z(n+1, 0), O(n+1, 0);

//         for (int i = 0; i < n; i++) {
//             Z[i+1] = Z[i] + (s[i] == '0');
//             O[i+1] = O[i] + (s[i] == '1');
//         }

//         long long ans = 0;

//         // -------------------------------------------------------------
//         // Explanation of threshold B:
//         //
//         // Condition for a substring to be valid:
//         //     ones >= zeros^2
//         //
//         // If zeros > sqrt(n), then zeros^2 > n, but no substring can
//         // have length > n. That means:
//         //     zeros > sqrt(n)  =>  impossible to satisfy
//         //
//         // Therefore, we only need to check substrings with <= B zeros.
//         // This massively reduces the time.
//         // -------------------------------------------------------------
//         int B = (int)sqrt(n) + 2;

//         // -------------------------------------------------------------
//         // Iterate over all right endpoints r of substrings.
//         // Then scan backward to find substrings ending at r.
//         //
//         // BUT: we stop scanning when zeros exceed B (≈ sqrt(n)).
//         // -------------------------------------------------------------
//         for (int r = 1; r <= n; r++) {

//             int zeros = 0;  // zeros in current substring s[l..r]

//             // Move left boundary l backwards
//             for (int l = r; l >= 1; l--) {

//                 // -----------------------------------------------------
//                 // Update zero count based on new character at position l
//                 // -----------------------------------------------------
//                 if (s[l-1] == '0')
//                     zeros++;

//                 // -----------------------------------------------------
//                 // If zeros exceed threshold, substring can never satisfy
//                 // ones >= zeros^2, so we break early.
//                 // -----------------------------------------------------
//                 if (zeros > B)
//                     break;

//                 // Compute ones using prefix sums
//                 int ones = O[r] - O[l-1];

//                 // -----------------------------------------------------
//                 // Check the required condition:
//                 //    ones >= zeros^2
//                 // -----------------------------------------------------
//                 if (ones >= zeros * zeros)
//                     ans++;
//             }
//         }

//         return (int)ans;
//     }
// };
