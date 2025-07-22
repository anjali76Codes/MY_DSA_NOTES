#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> name;
    name.push_back({53, 29});

    // no need to write in {} - by default
    name.emplace_back(53, 29);

    vector<int> Teena(38);

    vector<int> gupta(5, 53);
    cout << gupta[0] << " " << gupta[4];

    vector<string> Teena(5, "anjali");
    //
    cout << *Teena.begin();

    vector<int> v(5, 53);
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << "  ";
    }

    for (auto anjali : v)
    {
        cout << anjali << "  ";
    }

    cout << "anjali" << endl;
    v.insert(v.begin(), 3, 100);
    v.erase(v.begin());
    for (auto anjali : v)
    {
        cout << anjali << "  ";
    }

    cout << *(v.begin());
    cout << "The vector is : " << (v.empty());

    return 0;
}


