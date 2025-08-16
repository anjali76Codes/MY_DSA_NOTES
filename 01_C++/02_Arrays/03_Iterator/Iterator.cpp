// Iterator is present in all 


// Iterator in Vector  
#include<bits/stdc++.h>
using namespace std;

int main()
{

// initialize vector
vector<int>v;
v.push_back(5);
v.push_back(10);
v.push_back(35);
v.push_back(20);
v.push_back(25);



// Iterator  initialize
vector<int>:: iterator it = v.begin();

while(it != v.end()){


// in vector we need to point first element so -> *it
cout<<*it<<endl;
it++;
}

return 0;
}





// Iterator in Ordered Map

#include<bits/stdc++.h>
using namespace std;

int main()
{

// initialize   map
map<int , int> m ;
m[0] = 1;
m[1] = 10;
m[2] = 15;
m[3] = 10;
m[4] = 12;

map<int,int>:: iterator it1 = m.begin();
while(it1 != m.end()){

    // in map we have key and value so we are using pair for accessing the key and values
    cout<< "key: "<<it1->first<<" value "<< it1->second<<endl;

    it1++;
}

return 0;
}










// Iterator in Unordered Map

#include<bits/stdc++.h>
using namespace std;

int main()
{

// initialize    unordered map
unordered_map<int , int> m;
m[0] = 1;
m[1] = 10;
m[2] = 15;
m[3] = 10;
m[4] = 12;

unordered_map<int,int>:: iterator it1 = m.begin();
while(it1 != m.end()){

    // in map we have key and value so we are using pair for accessing the key and values
    cout<< "key: "<<it1->first<<" value "<< it1->second<<endl;

    it1++;
}

return 0;
}





