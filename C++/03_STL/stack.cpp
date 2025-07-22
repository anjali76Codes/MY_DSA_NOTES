#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);

    cout << st.top() << endl;
    cout << st.size() << " ";
    stack<string> teena, anjali;
    teena.push("anjali");

    anjali.push("teena");
    cout << teena.top() << " ";
    cout << anjali.top();

    swap(teena, anjali);

    cout << teena.top() << " ";
    cout << anjali.top();
    

    return 0;
}


