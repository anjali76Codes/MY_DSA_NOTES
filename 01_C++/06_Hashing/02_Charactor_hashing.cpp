#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Array to count frequency of each character from 'a' to 'z'
    int hash[26] = {0};

    // Count the frequency of each character in the string s
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;

    // Process each query
    while (q--) {
        char c;
        cin >> c;

        // Output the count of character c in string s
        cout << hash[c - 'a'] << endl;
    }

    return 0;
}
