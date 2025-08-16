#include <bits/stdc++.h>
using namespace std;

class Stack {
    list<int> ll;


public:
 void push(int val){  // O(1)
        ll.push_front(val);
    }

 
    void pop(){        // O(1)
        ll.pop_front();
    }


    int top(){               // O(1)
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }

};

int main(){

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // s.pop();
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    // direct using stl 
    stack<int>s1;

     s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.push(400);

    // s.pop();
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return 0;
}