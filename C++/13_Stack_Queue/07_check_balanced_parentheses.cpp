/*
time complexity : O(N)
space complexity : O(N)
*/


#include <bits/stdc++.h>
using namespace std;

bool check_balanced_parentheses(string s) {
    // Create a stack to store opening brackets
    stack<char> st;

    // Iterate over the string
    for (int i = 0; i < s.length(); i++) {

        // If the current character is an opening bracket, push it onto the stack
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {

            // If the stack is empty when encountering a closing bracket, return false
            if (st.empty()) return false;

            char ch = st.top();
            st.pop();

            // Check if the current closing bracket matches the top of the stack
            if ((s[i] == ')' && ch != '(') || 
                (s[i] == ']' && ch != '[') || 
                (s[i] == '}' && ch != '{')) {
                return false;
            }
        }
    }

    // If the stack is empty, all brackets are balanced
    return st.empty();
}

int main() {
    string s1 = "(([{}()]))";
    string s2 = "(([{()]))";

    if (check_balanced_parentheses(s1)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}
