#include <bits/stdc++.h>
using namespace std;

int main()
{

    pair<int, string> student = {1, "Anjali"};
    pair<int, string> student2;
    student2.first = 2, student2.second = "Teena";

    

    cout << student.first << " " << student.second << endl;
    cout << student2.first << " " << student2.second << endl;

    pair<int, pair<string, string>> name = {1, {"Anjali", "Teena"}};

    pair<int, string> students[2];
    cout << sizeof(students) / sizeof(students[0]) << endl;

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
    {
        cout << "Enter the " << i << "th student details :";
        cin >> students[i].first >> students[i].second;
    }

    pair<int, int> name2 = {1, 53};
    cout << name2.first << " " << name2.second << endl;

    return 0;
}
