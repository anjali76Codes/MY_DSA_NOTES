#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
        }
};


class queue_ll{
    public:
    Node* start , * end   ;
    int size;
    queue_ll(){
        start = NULL;
        end = NULL;
        size = 0;

    }
   

    void push(int ele){
        Node *newNode = new Node(ele);
        if(start == NULL && end == NULL){
            start = end = newNode ; 

        }

     else{
         end->next = newNode ; 
        end = newNode ;
     }
     size++;
        
    }

    void pop(){
        if(start == NULL&& end == NULL){
            cout<<"Queue is empty"<<endl;

        }
        else{
            Node* deletedNode = start;
        start = start->next; 
        cout<<deletedNode->data<<endl;

        delete deletedNode;

        }
    size--;
        
    }

    void top(){
        if(start == NULL && end == NULL){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<start->data<<endl;
        }
    }

    void getSize(){
        cout<<size<<endl;
    }



};


int main(){

    queue_ll ans ;
    ans.push(3);
    ans.push(5);
    ans.push(7);
    ans.pop();
    ans.top();
    ans.getSize();
    return 0;
}