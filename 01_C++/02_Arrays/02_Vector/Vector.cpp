#include <iostream>
#include <Vector>

using namespace std;
int main()
{
    vector<int> V;


    for (int i = 0; i <= 5; i++)
    {
        int element;
        cin >> element;
        V.push_back(element);
    }



    cout << "Size:" << V.size() << endl;
    cout << "Capacity:" << V.capacity() << endl;


    V.push_back(3);
    cout << "Size:" << V.size() << endl;
    cout << "Capacity:" << V.capacity() << endl;


    V.push_back(13);
    cout << "Size:" << V.size() << endl;
    cout << "Capacity:" << V.capacity() << endl;


    V.push_back(6);
    cout << "Size:" << V.size() << endl;
    cout << "Capacity:" << V.capacity() << endl;



   // resize() 
    V.resize(10);
    cout << "Size:" << V.size() << endl;
    cout << "Capacity:" << V.capacity() << endl;

    
// work on elements means data type is according to elements type not indices
// for each loop
    for (int ele : V)
    {
        cout << ele << endl;
    }
    return 0;
}








#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{

    // initialization
    vector<int> v = {5, 8, 9, 2, 3, 18, 90, 67};


    for(int i = 0; i<8; i++){
        cout<<v[i];
        cout<<" ";
    }





    // Iterator
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }


    vector<int> v1;
    v1.push_back(6);
    v1.push_back(5);
    v1.push_back(62);
    v1.push_back(59);
    v1.push_back(15);




// increasing order
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }



// decreasing order
    sort(v1.begin(), v1.end(), greater<int>());
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    return 0;
}

