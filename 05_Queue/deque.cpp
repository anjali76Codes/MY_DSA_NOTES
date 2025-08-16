#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;

    // simply push the ele 
    dq.push_back(9);
    dq.push_back(11);
    dq.push_back(15);   // 9 11 15 
    dq.push_front(5);   // 5 9 11 15 
   
    dq.pop_back();
    cout<<dq.front();  // 5

return 0;
}