#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int revnum = 0;
    int copynum = n;
    while (n > 0)
    {
        int lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }

    if (revnum == copynum)
    {
        cout << "palindrome";
    }

    else
    {
        cout << "Given no. is not a palindrome";
    }

    return 0;
}

// class Solution {
public:
bool isPalindrome(int x)
{

    if (x < 0)
        return false;

    int temp = x;
    int num = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        num = (num * 10) + digit;
        temp /= 10;
    }

    return num == x;
}
}
;

/*
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        int temp = x;
        long long num = 0;

        while (temp > 0) {
            int digit = temp % 10;
            num = (num * 10) + digit;
            temp /= 10;
        }

        return num == x;
    }
};
*/