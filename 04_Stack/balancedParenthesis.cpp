#include <bits/stdc++.h>
using namespace std;

bool checkBalancedParenthesis(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        // Push opening brackets
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
            st.push(s[i]);
        } else { 
            // If stack is empty when expecting a matching opening bracket
            if (st.empty()) return false;

            char ch = st.top();
            st.pop();

            // Check if the popped bracket matches the current closing bracket
            if ((s[i] == ']' && ch != '[') ||
                (s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{')) {
                return false;
            }
        }
    }
    // If stack is empty, all brackets matched
    return st.empty();
}

int main() {
    string s = "()[{}()]";
    cout << (checkBalancedParenthesis(s) ? "Balanced" : "Not Balanced");
    return 0;
}
