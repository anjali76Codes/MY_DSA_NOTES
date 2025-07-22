#include <bits/stdc++.h>
using namespace std;

int main()
{
    // set -->store in sorted form and store  only unique value
    set<int> set1 = {1,1,1,1,1};
    set1.insert(4);
    set1.insert(40);
    set1.insert(53);
    // Find element 53 in the set

    for( auto i: set1){
        cout<<i<<endl;
    }
    auto iterate = set1.find(53);        

    if(iterate==(--set1.end())) {
        cout<<"at end";
    }
    else {
        cout<<" nothing ";
    }

    cout<<endl<<set1.count(1);
    auto anjali = "anjali";
    cout<<anjali;

    multiset<int>multi;
    multi.insert(5);
    multi.insert(12);
    multi.insert(5);
    multi.insert(5);
    multi.erase(multi.find(5));


// unorder--> all elements are arranged randomly don't have any fix order

     unordered_set<int>unorde;
    unorde.insert(212);
    unorde.insert(532);
    unorde.insert(215);
    unorde.insert(5);
    unorde.insert(12);
    unorde.erase(unorde.find(5));
    
    for( auto i: unorde){
        cout<<i<<endl;
    }


   
  
    return 0;
}