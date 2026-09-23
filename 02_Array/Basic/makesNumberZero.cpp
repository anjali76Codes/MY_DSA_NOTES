#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 && num2) {
            // Always subtract the smaller from the larger one in one go
            if (num1 >= num2) {
                cnt += num1 / num2;  // Add the quotient to the count
                num1 %= num2;         // Reduce num1 to the remainder
            } else {
                cnt += num2 / num1;  // Add the quotient to the count
                num2 %= num1;         // Reduce num2 to the remainder
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int result = sol.countOperations(num1, num2);
    cout << "Number of operations: " << result << endl;

    return 0;
}
