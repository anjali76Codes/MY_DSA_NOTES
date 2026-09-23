class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s) {
            freq[ch]++;
        }

        // Store character and frequency
        vector<pair<char, int>> arr(freq.begin(), freq.end());

        // Sort by frequency in descending order
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Build answer
        string ans;

        for (auto &p : arr) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};