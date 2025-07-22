#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> hash(128, {0, 0}); // 128 covers full ASCII

        for (char ch : s) {
            hash[ch].first++;
            hash[ch].second = ch;
        }

        sort(hash.begin(), hash.end(), greater<pair<int, char>>());

        string res = "";
        for (auto p : hash) {
            if (p.first > 0)
                res += string(p.first, p.second);
        }

        return res;
    }
};


int main(){
    return 0;
}