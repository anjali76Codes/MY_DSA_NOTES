#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> qu;
    qu.push(53);
    qu.push(29);
    qu.push(28);
    qu.push(31);
    qu.push(11);
    qu.pop();
   
    cout<<qu.front(); // this returns a value

    auto it = qu.front();
    cout<<it++; // this returns a value

    // Note: disadvantage of stack, queue and dequeue can access only first and last elements not in between


    

    return 0;
}