/*
time complexity :

*/


#include<bits/stdc++.h>
using namespace std; 

class Node{
public:
 int data ; 
 Node* next ;

 Node(int data1 , Node*next1){
    data = data1 ;
    next = next1 ;
 }

 Node(int data1 ){
    data = data1 ;
    next = NULL ;
 }
};

class Stack_LL{
public:
    // declaring the top which first point to null 
    Node* top  ; 
    int size = 0 ;

    void push(int ele){
        Node* temp = new Node(ele);
        temp->next = top ;
        top = temp ;
        size++;

    }


   void pop(){
        Node* temp = top;
        top = top->next ; 
        size--;
        cout<<temp->data<<endl;
       delete temp;
   
    

    }


void getTop(){
    cout<< "top element is :"<<top->data<<endl;  
    }

   void getSize(){
      cout<<"size is: "<< size<<endl;
    }


};

int main(){
    Stack_LL ans;
    ans.push(1);
    ans.push(2);
     ans.push(3);

ans.pop();
ans.getTop();
ans.getSize();

    return 0;
}