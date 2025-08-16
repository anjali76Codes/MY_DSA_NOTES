/*
Longest Common prefix :
The longest common prefix of a word array is the longest contiguous prefix string that is common to all strings in the word array.

For example, given the word array ["flower","flow","flight"], the longest common prefix is
"fl".
Example 1:
Input: ["flower","flow","flight"]
after sorting : flight , flow , flower
Output: "fl"

# Brute approach :
steps :
1. Iterate over each word in the array
2. For each word, iterate over each character in the word
3. Compare the character with the first character of the first word in the array
4. If the character is not equal to the first character of the first word, return the common
prefix up to the previous character

time complexity :
O(n*m) where n is the number of words and m is the maximum length of a word

# optimal approach 
steps :
1. sort the strings 
2. compare the first characters of the first and last strings .
3. if the characters are equal, add the character to the common(ans)  and move to the next character in the first string.

time complexity :
O(n log n) due to sorting



*/

#include <bits/stdc++.h>
using namespace std;

string longest_common_prefix_brute(vector<string> &s)
{
    string common = "";
    for (int i = 0; i < s[0].length(); i++)
    {
        for (int j = 0; j < s.size() - 1; j++)
        {
            /* ith - index points the position of the words (no. of strings)
           and jth index is the index of the each character of a word

            */

            // it check character of first word is matching to the character of the second and so on (till n -> no. of strings)
            if (s[j][i] != s[j + 1][i])
            {
                return {common};
            }
        }
        common += s[0][i];
    }

    return common;
}



// optimal approach 
string longest_common_prefix_optimal(vector<string>&s){
    string common = "";

    // sort the strings
    sort(s.begin(), s.end());
    int i = 0 ;

    // check first and last word characters
    while(i< s[0].length() && s[0][i] == s[s.size()-1][i]){
        common += s[0][i];
        i++;
    }
    return common;

}



int main()
{

    vector<string> s = {"flow" , "flight" , "flower"};

    cout << longest_common_prefix_brute(s);
    cout << longest_common_prefix_optimal(s);

    return 0;
}