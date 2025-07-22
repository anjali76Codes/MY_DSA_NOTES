
/*
 check if two strings are isomorphic or not.
Two strings are isomorphic if each character in one string can be uniquely mapped to a character in the other string.
Time Complexity: O(n), where n is the length of the strings.
Space Complexity: O(n), where n is the length of the strings.
*/



#include <bits/stdc++.h>
using namespace std;

bool Isomorphic(string s1, string s2)
{
    // If the lengths of the strings are different, they cannot be isomorphic
    if (s1.length() != s2.length())
        return false;

    // Create two hash maps to store character mappings from s1 to s2 and vice versa
    unordered_map<char, char> map1, map2;

    // Iterate over each character in the strings
    for (int i = 0; i < s1.length(); i++)
    {
        char char1 = s1[i];
        char char2 = s2[i];

        // If char1 is already mapped in map1 but maps to a different char2, return false
        if (map1.find(char1) != map1.end() && map1[char1] != char2)
        {
            return false;
        }

        // If char2 is already mapped in map2 but maps to a different char1, return false
        if (map2.find(char2) != map2.end() && map2[char2] != char1)
        {
            return false;
        }

        // Add mappings to both hash maps
        map1[char1] = char2;
        map2[char2] = char1;
    }

    // If no conflicts are found, the strings are isomorphic
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // Check if the strings are isomorphic
    bool res = Isomorphic(s1, s2);

    if (res)
    {
        cout << "Yes, Isomorphic" << endl;
    }
    else
    {
        cout << "Not Isomorphic" << endl;
    }

    return 0;
}
