#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> anjali = {1, 2, 3};
    // for (auto i : anjali)
    // {
    //     cout << i << "";
    // }

    // vector--> stores in contiguous memory
    // list-->stored in linked structure

    auto it = anjali.begin();
    cout<<*(++it);

    return 0;
}
