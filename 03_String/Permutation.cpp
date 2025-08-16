#include <bits/stdc++.h>
using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }

    return true;
}



bool checkInclusion(string s1, string s2)
{

    // 1. To store the character and its freq in freq array

    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        // char - char -> ASCII value (along with char store its freq )
        freq[s1[i] - 'a']++;
    }

    int windsize = s1.length();
    // 2. same do for the windwo freq
    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0;
        int idx = i;
        int windFreq[26] = {0};

        while (windIdx < windsize && idx < s2.length())
        {
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq))
        {
            return true;
        }
    }

    return false;
}

int main()
{

    string s1 = "ab";
    string s2 = "eidboaoo";
   cout<< checkInclusion(s1, s2);
    

    return 0;
}