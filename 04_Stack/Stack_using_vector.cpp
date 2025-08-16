#include<bits/stdc++.h>
using namespace std ;

class Stack{
    public:
    vector<int>v;

    void push(int val){
        v.push_back(val);
    }


    void pop(){
        v.pop_back();
    }


    int top(){
        return v[v.size()-1];
    }

    bool Empty(){
        return v.size() == 0;
    }

};



int main(){

    Stack s ;
    s.Empty();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // s.pop();
    while(!s.Empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}