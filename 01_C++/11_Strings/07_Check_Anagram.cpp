/*
Check if two strings are anagram of each other
to check this this condition should satisfy first
-->  string s1 and s2 has same length
-> two strings are anagram of each other when they have the same characters but arrangements of the characters are vary .

ex. hello
olleh -> in this in both string the count of all characters are same so we can say that two strings are anagram of each other


Brute approach :
-  both string has same length 
- sort the both strings
-  check if every character of str1 and str2 matches with each other

time complexity : O(nlogn)


Optimal approach :
- check condition (strings has same length or not)
- store the count of each character of str1
- when iterating on str2 count --
- at end iterate again if any of the character is not equal to zero then strings are not anagram of each other

time complexity : O(n)


*/

#include <bits/stdc++.h>
using namespace std;


// 1st approach 

bool CheckAnagrams(string str1, string str2)
{

  if (str1.length() != str2.length())
    return false;
 
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
 
  // Case 2: check if every character of str1 and str2 matches with each other
  for (int i = 0; i < str1.length(); i++)
  {
    if (str1[i] != str2[i])
      return false;
  }
  return true;
}



//optimal approach
bool check_anagram(string s1, string s2)
{
    // when strings don't have the same length
    if (s1.length() != s2.length())
    {
        return false;
    }

    // create a array to store the count of each character

    int fre[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {

       // s = "anagram", t = "nagaram"
        fre[s1[i] - 'a']++;  // a - 1  


    }

    for (int i = 0; i < s2.length(); i++)
    {
        fre[s2[i] - 'a']--;
    }

    // iterate again if any of the character count is not equal to zero then return false
    for (int i = 0; i < 26; i++)
    {
        if (fre[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    cout << CheckAnagrams(s1, s2);
    cout << check_anagram(s1, s2);

    return 0;
}