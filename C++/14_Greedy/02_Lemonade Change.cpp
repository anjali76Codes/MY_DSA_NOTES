/*
Lemonade change :
Given an array => which represents the queue of the customers with their bills value
customer can only pay $5 , $10 , $20 and at starting we don't have any change

Approach :
- if customer denomination is $5 then simply add +1(five++)
- if $10 then five-- and ten++
- if $20 then there will be two cases
    1. either if we have 10 and 5 then  five-- , ten--
    2. five>=3 then  five--


Time complexity : O(N)
space complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool LemonadeChange(int arr[], int n)
{
    int five = 0, ten = 0;

    for (int i = 0; i < n; i++)
    {
        // 1. when denomination is $5
        if (arr[i] == 5)
        {
            five++;
        }

        else if (arr[i] == 10)
        {
            if (five)
            {
                five--;
                ten++;
            }
            else
                return false;
        }

        else
        {
            if (ten && five)
            {

                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }

            else return false;
        }
    }
    return true;
}

int main()
{
    int n = 6;
    int arr[n] = {5, 5, 5, 10, 20 };
    cout << LemonadeChange(arr, n) << endl;

    return 0;
}