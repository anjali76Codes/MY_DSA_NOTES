/*
if string -> (())((()))  then we have to remove the outermost parenthesis

decomposition : when all open bracket has close bracket

# stack approach :
- if stack is empty then push it but don't add it in ans
- if stack is not empty then push it nad add in ans

time complexity : O(n)
space complexity : O(n)


# Pointer approach :
-> if cnt = 0 then don't add in ans
-> In string when this will come '('  do cnt++ and in ans
-> when ')' will come do cnt--




*/

#include <bits/stdc++.h>
using namespace std;

string Remove_Outer_Parenthesis(string s)
{
    int cnt = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
       

        if ((s[i] == ')'))
        {
            cnt--;
        }

         if (cnt != 0)
        {
            ans.push_back(s[i]);
        }

        if ((s[i] == '('))
        {
            cnt++;
        }
    }

    return ans ;
}

int main()
{
    string s;
    getline(cin, s);
    string res = Remove_Outer_Parenthesis(s);
    cout << res << endl;

    return 0;
}